//
//  IRGen.cpp
//  ECE467 Lab 4
//
//  Created by Tarek Abdelrahman on 2023-10-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include <iostream>
using namespace std;

#include "IRGen.h"
#include "SymTable.h"
#include "ASTVisitorBase.h"
using namespace smallc;
using namespace llvm;

namespace smallc {

IRGen::IRGen(const std::string moduleName) : ASTVisitorBase(),
                                             prog(nullptr),
                                             TheModule(),
                                             Builder(),
                                             ModuleName(moduleName) {
    TheContext = std::make_unique<llvm::LLVMContext>();
}

unique_ptr<Module> 
IRGen::getModule() {
    Builder.reset();
    return std::move(TheModule);
}

llvm::Type*
IRGen::convertType(TypeNode* type){
    llvm::Type* base;
    switch(type->getTypeEnum()){
        case TypeNode::TypeEnum::Void:
            base = llvm::Type::getVoidTy(*TheContext);
            break;
        case TypeNode::TypeEnum::Int:
            base = llvm::Type::getInt32Ty(*TheContext);
            break;
        case TypeNode::TypeEnum::Bool:
            base = llvm::Type::getInt1Ty(*TheContext);
            break;
    }
    if(type->isArray()){
        ArrayTypeNode* arrType = (ArrayTypeNode*) type;
        return llvm::ArrayType::get(base, arrType->getSize());
    }
    return base;
}

SymTable<VariableEntry>*
IRGen::findTable(IdentifierNode* id){
    ASTNode* parent = id->getParent();
    bool found = false;
    SymTable<VariableEntry>* res = nullptr;
    while (parent && !found){
        if (parent->hasVarTable()){
            if (parent->getParent()){
                ScopeNode* scope = (ScopeNode*)parent;
                res = scope->getVarTable();
            }
            else {
                res = id->getRoot()->getVarTable();
            }
            if (res && res->contains(id->getName()))
                found = true;
        }
        parent = parent->getParent();
    }
    return res;
}

// ECE467 STUDENT: complete the implementation of the visitor functions
void IRGen::visitASTNode(ASTNode* node) {
    ASTVisitorBase::visitASTNode(node);
}

void IRGen::visitArgumentNode(ArgumentNode* arg) {
    //visit expression
    arg->getExpr()->visit(this);
    ASTVisitorBase::visitArgumentNode(arg);
}

void IRGen::visitDeclNode(DeclNode* decl) {
    ASTVisitorBase::visitDeclNode(decl);
}

void IRGen::visitArrayDeclNode(ArrayDeclNode* array) {
    llvm::Type* arrayType;
    llvm::Value* llvmArrValue;
    llvm::Function *llvmFunc;
    llvm::Value *Alloca;
    SymTable<VariableEntry>* varST;
    llvm::Constant* initValue;

    arrayType = convertType(array->getType());
    if (array->isGlobal()) {
        // Global variable creation
        initValue = llvm::Constant::getNullValue(arrayType);
        llvmArrValue = new llvm::GlobalVariable(
            (*this->TheModule),
            arrayType,
            false,
            llvm::GlobalValue::CommonLinkage,
            llvm::ConstantAggregateZero::get(arrayType),     
            array->getIdent()->getName()
        );
        varST = findTable(array->getIdent());
        assert(varST->contains(array->getIdent()->getName()));
        varST->setLLVMValue(array->getIdent()->getName(), llvmArrValue);
    } else {
        // Local variable creation
        llvmFunc = (*this->TheModule).getFunction(array->getIdent()->getName());
        Alloca = (*Builder).CreateAlloca(arrayType, nullptr, array->getIdent()->getName());
        varST = findTable(array->getIdent());
        assert(varST->contains(array->getIdent()->getName()));
        varST->setLLVMValue(array->getIdent()->getName(), Alloca);
    }
    ASTVisitorBase::visitArrayDeclNode(array);
}

void IRGen::visitFunctionDeclNode(FunctionDeclNode* func) {
    llvm::Function *llvmFunc = nullptr;
    llvm::BasicBlock *Entryblock;
    llvm::Argument* arg;
    llvm::Value *Alloca;
    SymTable<VariableEntry>* varST;
    std::vector<ParameterNode*> funcParams = func->getParams();
    llvm::FunctionType *funcRt;
    std::vector<llvm::Type *> LLVMparams;

    
    llvmFunc = (*this->TheModule).getFunction(func->getIdent()->getName());
    if (llvmFunc == nullptr){
        for (int i = 0; i < funcParams.size(); i++){
            LLVMparams.push_back(convertType(funcParams[i]->getType()));
        }
        funcRt = llvm::FunctionType::get(convertType(func->getRetType()), LLVMparams, false);
        llvmFunc = Function::Create(funcRt, Function::ExternalLinkage, func->getIdent()->getName(), this->TheModule.get());
    }

    if (!func->getProto()){
        Entryblock = llvm::BasicBlock::Create(*TheContext, "entry", llvmFunc);
        (*Builder).SetInsertPoint(Entryblock);

        //code from Kaleidoscope
        int i = 0;
        for (auto &Arg : llvmFunc->args()){
            Arg.setName(funcParams[i]->getIdent()->getName());
            if (funcParams[i]->getType()->getTypeEnum() == TypeNode::Bool) {
                Arg.addAttr(llvm::Attribute::ZExt);
            }
            i++;
        }
            
        for (int i = 0; i < llvmFunc->arg_size(); i++) {
            arg = llvmFunc->getArg(i);
            Alloca = (*Builder).CreateAlloca(arg->getType(), nullptr, arg->getName());
            varST = func->getBody()->getVarTable();
            assert(varST->contains(funcParams[i]->getIdent()->getName()));
            varST->setLLVMValue(funcParams[i]->getIdent()->getName(), Alloca);
            (*Builder).CreateStore(arg, Alloca);
        }
        //visit scope
        func->getBody()->visit(this);
    }

    ASTVisitorBase::visitFunctionDeclNode(func);
}

void IRGen::visitScalarDeclNode(ScalarDeclNode* scalar) {
    llvm::Type* varType;
    llvm::Value* llvmVarValue;
    llvm::Function *llvmFunc;
    llvm::Value *Alloca;
    SymTable<VariableEntry>* varST;
    llvm::Constant* initValue;

    varType = convertType(scalar->getType());
    if (scalar->isGlobal()) {
        // Global variable creation
        initValue = llvm::Constant::getNullValue(varType);
        llvmVarValue = new llvm::GlobalVariable(
            (*this->TheModule),
            varType,
            false,
            llvm::GlobalValue::CommonLinkage,
            initValue,     
            scalar->getIdent()->getName()
        );
        varST = findTable(scalar->getIdent());
        assert(varST->contains(scalar->getIdent()->getName()));
        varST->setLLVMValue(scalar->getIdent()->getName(), llvmVarValue);
    } else {
        // Local variable creation
        llvmFunc = (*this->TheModule).getFunction(scalar->getIdent()->getName());
        Alloca = (*Builder).CreateAlloca(varType, nullptr, scalar->getIdent()->getName());
        varST = findTable(scalar->getIdent());
        assert(varST->contains(scalar->getIdent()->getName()));
        varST->setLLVMValue(scalar->getIdent()->getName(), Alloca);
    }

    ASTVisitorBase::visitScalarDeclNode(scalar);
}

void IRGen::visitExprNode(ExprNode* exp) {
    ASTVisitorBase::visitExprNode(exp);
}

void IRGen::visitBinaryExprNode(BinaryExprNode* bin) {
    //visit nodes
    bin->getLeft()->visit(this);
    bin->getRight()->visit(this);

    ExprNode::Opcode binOP;
    llvm::Value *leftLLVMval;
    llvm::Value *rightLLVMval;
    llvm::Value* resultLLVMval;

    leftLLVMval = bin->getLeft()->getLLVMValue();
    rightLLVMval = bin->getRight()->getLLVMValue();

    binOP = bin->getOpcode();
    switch (binOP) {
        case ExprNode::Addition:
            resultLLVMval = Builder->CreateAdd(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::Subtraction:
            resultLLVMval = Builder->CreateSub(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::Multiplication:
            resultLLVMval = Builder->CreateMul(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::Division:
            resultLLVMval = Builder->CreateSDiv(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::And:
            resultLLVMval = Builder->CreateAnd(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::Or:
            resultLLVMval = Builder->CreateOr(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::Equal:
            resultLLVMval = Builder->CreateICmpEQ(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::NotEqual:
            resultLLVMval = Builder->CreateICmpNE(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::LessThan:
            resultLLVMval = Builder->CreateICmpSLT(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::LessorEqual:
            resultLLVMval = Builder->CreateICmpSLE(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::Greater:
            resultLLVMval = Builder->CreateICmpSGT(leftLLVMval, rightLLVMval);
            break;
        case ExprNode::GreaterorEqual:
            resultLLVMval = Builder->CreateICmpSGE(leftLLVMval, rightLLVMval);
            break;
        default:
            assert(false);
            return;
    }
    bin->setLLVMValue(resultLLVMval);

    ASTVisitorBase::visitBinaryExprNode(bin);
}

void IRGen::visitBoolExprNode(BoolExprNode* boolExpr) {
    ExprNode* boolExprVal;

    //visit val first
    boolExprVal = boolExpr->getValue();
    // assert(boolExprVal != nullptr);
    boolExprVal->visit(this);
    boolExpr->setLLVMValue(boolExpr->getValue()->getLLVMValue());

    ASTVisitorBase::visitBoolExprNode(boolExpr);
}

void IRGen::visitCallExprNode(CallExprNode* call) {
    std::vector<ArgumentNode*> funcArgs;
    std::vector<llvm::Value*> llvmArgs;
    llvm::Value* argVal;
    llvm::Function* callee;
    llvm::Value* callRet;

    funcArgs = call->getArguments();
    //visit args
    for (int i = 0; i < funcArgs.size(); i++){
        funcArgs[i]->visit(this);
        argVal = funcArgs[i]->getExpr()->getLLVMValue();
        llvmArgs.push_back(argVal);
    }

    callee = TheModule->getFunction(call->getIdent()->getName());
    callRet = Builder->CreateCall(callee, llvmArgs);

    call->setLLVMValue(callRet);

    ASTVisitorBase::visitCallExprNode(call);
}

void IRGen::visitConstantExprNode(ConstantExprNode* constant) {
    ASTVisitorBase::visitConstantExprNode(constant);
}

void IRGen::visitBoolConstantNode(BoolConstantNode* boolConst) {
    boolConst->setTypeBool();

    llvm::Value* llvmBoolconstant;

    llvmBoolconstant = llvm::ConstantInt::get(convertType(boolConst->getType()), boolConst->getVal(), false);
    boolConst->setLLVMValue(llvmBoolconstant);
    ASTVisitorBase::visitBoolConstantNode(boolConst);
}

void IRGen::visitIntConstantNode(IntConstantNode* intConst) {
    intConst->setTypeInt();

    llvm::Value* intconstant;

    intconstant = llvm::ConstantInt::get(convertType(intConst->getType()), intConst->getVal(), true);
    intConst->setLLVMValue(intconstant);

    ASTVisitorBase::visitIntConstantNode(intConst);
}

void IRGen::visitIntExprNode(IntExprNode* intExpr) {
    ExprNode* intExprVal;

    //visit val first
    intExprVal = intExpr->getValue();
    // assert(intExprVal != nullptr);
    intExprVal->visit(this);
    intExpr->setLLVMValue(intExpr->getValue()->getLLVMValue());

    ASTVisitorBase::visitIntExprNode(intExpr);
}

void IRGen::visitReferenceExprNode(ReferenceExprNode* ref) {
    llvm::Value* refValue = nullptr;
    llvm::Value* result = nullptr;
    llvm::Value* elementLLVMVal;
    llvm::Value* indices[2]; 
    SymTable<VariableEntry>* varST;
    VariableEntry var;
    llvm::ArrayRef<Value*> LLVMIdx;
    llvm::Type* ArrType;
    AssignStmtNode* assignmentPtr;
    
    assignmentPtr = dynamic_cast<AssignStmtNode*>(ref->getParent());
    if (assignmentPtr == nullptr){
        varST = findTable(ref->getIdent());
        assert(varST->contains(ref->getIdent()->getName()));
        var = varST->get(ref->getIdent()->getName());
        refValue = var.getValue();
        assert(refValue != nullptr);

        if (ref->getIndex() != nullptr) {
            ref->getIndex()->visit(this);
            indices[1] = ref->getIndex()->getLLVMValue();
            indices[0] = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0);
            LLVMIdx = llvm::ArrayRef<Value*>(indices, 2);
            elementLLVMVal = (*Builder).CreateGEP(
                convertType(var.getType()),
                refValue,
                LLVMIdx
            );
            // Load
            switch(var.getType()->getTypeEnum()){
                case TypeNode::TypeEnum::Void:
                    ArrType = llvm::Type::getVoidTy(*TheContext);
                    break;
                case TypeNode::TypeEnum::Int:
                    ArrType = llvm::Type::getInt32Ty(*TheContext);
                    break;
                case TypeNode::TypeEnum::Bool:
                    ArrType = llvm::Type::getInt1Ty(*TheContext);
                    break;
            }
            result = (*Builder).CreateLoad(ArrType, elementLLVMVal);
        } else {
            // Handle scalar reference
            result = (*Builder).CreateLoad(convertType(var.getType()), refValue);
        }
        ref->setLLVMValue(result);
    } else {
        varST = findTable(ref->getIdent());
        var = varST->get(ref->getIdent()->getName());
        refValue = var.getValue();
        ref->setLLVMValue(refValue);
    }
    
    ASTVisitorBase::visitReferenceExprNode(ref);
}

void IRGen::visitUnaryExprNode(UnaryExprNode* unary) {
    ExprNode* unaExprOperand;
    llvm::Value *unaExprOperandLLVMval;
    llvm::Value* resultLLVMval;
    ExprNode::Opcode unaOP;

    //visit val first
    unaExprOperand = unary->getOperand();
    // assert(unaExprOperand != nullptr);
    unaExprOperand->visit(this);
    unaExprOperandLLVMval = unaExprOperand->getLLVMValue();

    unaOP = unary->getOpcode();
    switch (unaOP) {
        case ExprNode::Not:
            resultLLVMval = Builder->CreateNot(unaExprOperandLLVMval);
            break;
        case ExprNode::Minus:
            resultLLVMval = Builder->CreateNeg(unaExprOperandLLVMval);
            break;
        default:
            assert(false);
    }
    unary->setLLVMValue(resultLLVMval);

    ASTVisitorBase::visitUnaryExprNode(unary);
}

void IRGen::visitIdentifierNode(IdentifierNode* id) {
    ASTVisitorBase::visitIdentifierNode(id);
}

void IRGen::visitParameterNode(ParameterNode* param) {
    ASTVisitorBase::visitParameterNode(param);
}

void IRGen::visitProgramNode(ProgramNode* prg) {
    this->TheModule = std::make_unique<llvm::Module>(this->ModuleName, *(this->TheContext));
    this->Builder = std::make_unique<llvm::IRBuilder<>>(*(this->TheContext));
    this->prog = prg;

    llvm::Function *llvmFunc = nullptr;
    llvm::FunctionType *funcRt;
    std::vector<llvm::Type *> LLVMparams;

    if (prg->useIo()){
        LLVMparams.push_back(llvm::Type::getInt1Ty(*TheContext));
        funcRt = llvm::FunctionType::get(llvm::Type::getVoidTy(*TheContext), LLVMparams, false);
        llvmFunc = Function::Create(funcRt, Function::ExternalLinkage, "writeBool", this->TheModule.get());
        for (llvm::Argument& arg : llvmFunc->args()) 
                arg.addAttr(llvm::Attribute::ZExt);

        LLVMparams.clear();
        LLVMparams.push_back(llvm::Type::getInt32Ty(*TheContext));
        funcRt = llvm::FunctionType::get(llvm::Type::getVoidTy(*TheContext), LLVMparams, false);
        llvmFunc = Function::Create(funcRt, Function::ExternalLinkage, "writeInt", this->TheModule.get());

        LLVMparams.clear();
        funcRt = llvm::FunctionType::get(llvm::Type::getVoidTy(*TheContext), LLVMparams, false);
        llvmFunc = Function::Create(funcRt, Function::ExternalLinkage, "newLine", this->TheModule.get());

        funcRt = llvm::FunctionType::get(llvm::Type::getInt32Ty(*TheContext), LLVMparams, false);
        llvmFunc = Function::Create(funcRt, Function::ExternalLinkage, "readInt", this->TheModule.get());

        funcRt = llvm::FunctionType::get(llvm::Type::getInt1Ty(*TheContext), LLVMparams, false);
        llvmFunc = Function::Create(funcRt, Function::ExternalLinkage, "readBool", this->TheModule.get());
    }

    ASTVisitorBase::visitProgramNode(prg);
}

void IRGen::visitStmtNode(StmtNode* stmt) {
    ASTVisitorBase::visitStmtNode(stmt);
}

void IRGen::visitAssignStmtNode(AssignStmtNode* assign) {
    //visit target and val
    assign->getTarget()->visit(this);
    assign->getValue()->visit(this);

    llvm::Value* targetLLVMVal;
    llvm::Value* valueLLVMVal;
    ReferenceExprNode* ref;
    llvm::Value* refValue = nullptr;
    llvm::Value* elementLLVMVal;
    llvm::Value* indices[2]; 
    SymTable<VariableEntry>* varST;
    VariableEntry var;
    llvm::ArrayRef<Value*> LLVMIdx;
    llvm::Type* ArrType;

    ref = assign->getTarget();
    
    varST = findTable(ref->getIdent());
    var = varST->get(ref->getIdent()->getName());
    refValue = var.getValue();
    assert(refValue != nullptr);

    if (ref->getIndex() != nullptr) {
        ref->getIndex()->visit(this);
        indices[1] = ref->getIndex()->getLLVMValue();
        indices[0] = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0);
        LLVMIdx = llvm::ArrayRef<Value*>(indices, 2);
        elementLLVMVal = (*Builder).CreateGEP(
            convertType(var.getType()),
            refValue,
            LLVMIdx
        );
        targetLLVMVal = elementLLVMVal;
    } else {
        targetLLVMVal = refValue;
    }
    valueLLVMVal = assign->getValue()->getLLVMValue();         

    // Create a store instruction
    (*Builder).CreateStore(valueLLVMVal, targetLLVMVal);

    ASTVisitorBase::visitAssignStmtNode(assign);
}

void IRGen::visitExprStmtNode(ExprStmtNode* expr) {
    expr->getExpr()->visit(this);
    ASTVisitorBase::visitExprStmtNode(expr);
}

void IRGen::visitIfStmtNode(IfStmtNode* ifStmt) {
    llvm::Function* parentFunction;
    llvm::BasicBlock* thenBB;
    llvm::BasicBlock* elseBB;
    llvm::BasicBlock* exitBB;
    llvm::Value* condValue;

    parentFunction = Builder->GetInsertBlock()->getParent();
    thenBB = llvm::BasicBlock::Create(*TheContext, "then", parentFunction);
    exitBB = llvm::BasicBlock::Create(*TheContext, "merge", parentFunction);
    if (ifStmt->getHasElse()) elseBB = llvm::BasicBlock::Create(*TheContext, "else", parentFunction);

    ifStmt->getCondition()->visit(this);
    condValue = ifStmt->getCondition()->getLLVMValue();

    if (ifStmt->getHasElse())
        Builder->CreateCondBr(condValue, thenBB, elseBB);
    else
        Builder->CreateCondBr(condValue, thenBB, exitBB);

    Builder->SetInsertPoint(thenBB);
    ifStmt->getThen()->visit(this);
    Builder->CreateBr(exitBB);

    if (ifStmt->getHasElse()) {
        Builder->SetInsertPoint(elseBB);
        ifStmt->getElse()->visit(this);
        Builder->CreateBr(exitBB);
    }

    Builder->SetInsertPoint(exitBB);

    ASTVisitorBase::visitIfStmtNode(ifStmt);
}

void IRGen::visitReturnStmtNode(ReturnStmtNode* ret) {
    ExprNode* retExpr;

    retExpr = ret->getReturn();
    if (retExpr != nullptr)
        retExpr->visit(this);

    if (retExpr != nullptr)
        Builder->CreateRet(retExpr->getLLVMValue());
    else
        Builder->CreateRetVoid();
    ASTVisitorBase::visitReturnStmtNode(ret);
}

void IRGen::visitScopeNode(ScopeNode* scope) {
    std::vector<DeclNode*> scopeDecles;
    scopeDecles = scope->getDeclarations();
    for (int i = 0; i < scopeDecles.size(); i++)
        scopeDecles[i]->visit(this);
    ASTVisitorBase::visitScopeNode(scope);
}

void IRGen::visitWhileStmtNode(WhileStmtNode* whileStmt) {
    // Create the basic blocks
    llvm::Function* parentFunction;
    llvm::BasicBlock* condblock;
    llvm::BasicBlock* bodyblock;
    llvm::BasicBlock* exitblock;
    llvm::Value* condValue;

    parentFunction = Builder->GetInsertBlock()->getParent();
    condblock = llvm::BasicBlock::Create(*TheContext, "while.cond", parentFunction);
    bodyblock = llvm::BasicBlock::Create(*TheContext, "while.body", parentFunction);
    exitblock = llvm::BasicBlock::Create(*TheContext, "while.exit", parentFunction);

    Builder->CreateBr(condblock);
    Builder->SetInsertPoint(condblock);
    whileStmt->getCondition()->visit(this);
    condValue = whileStmt->getCondition()->getLLVMValue();

    Builder->CreateCondBr(condValue, bodyblock, exitblock);

    Builder->SetInsertPoint(bodyblock);
    whileStmt->getBody()->visit(this);

    Builder->CreateBr(condblock);

    Builder->SetInsertPoint(exitblock);

    ASTVisitorBase::visitWhileStmtNode(whileStmt);
}

void IRGen::visitTypeNode(TypeNode* type) {
    ASTVisitorBase::visitTypeNode(type);
}

void IRGen::visitPrimitiveTypeNode(PrimitiveTypeNode* type) {
    ASTVisitorBase::visitPrimitiveTypeNode(type);
}

void IRGen::visitArrayTypeNode(ArrayTypeNode* type) {
    ASTVisitorBase::visitArrayTypeNode(type);
}


} // namespace smallc
