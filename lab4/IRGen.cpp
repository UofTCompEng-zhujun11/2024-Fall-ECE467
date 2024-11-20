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
    llvm::Function *llvmFunc;
    llvm::BasicBlock *EntryBB;
    llvm::Argument* arg;
    llvm::Value *Alloca;
    SymTable<VariableEntry>* varST;
    std::vector<ParameterNode*> funcParams = func->getParams();
    llvm::FunctionType *funcRt;
    std::vector<llvm::Type *> LLVMparams;

    if (!func->getProto()){
        llvmFunc = (*this->TheModule).getFunction(func->getIdent()->getName());
        if (llvmFunc == nullptr){
            for (int i = 0; i < funcParams.size(); i++){
                LLVMparams.push_back(convertType(funcParams[i]->getType()));
            }
            funcRt = llvm::FunctionType::get(convertType(func->getRetType()), LLVMparams, false);
            llvmFunc = Function::Create(funcRt, Function::ExternalLinkage, func->getIdent()->getName(), this->TheModule.get());
        }

        EntryBB = llvm::BasicBlock::Create(*TheContext, "entry", llvmFunc);
        (*Builder).SetInsertPoint(EntryBB);

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
        varST->setLLVMValue(scalar->getIdent()->getName(), Alloca);
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
    funcArgs = call->getArguments();
    //visit args
    for (int i = 0; i < funcArgs.size(); i++){
        funcArgs[i]->visit(this);
    }
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
                LLVMIdx,
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
    }
    
    ASTVisitorBase::visitReferenceExprNode(ref);
}

void IRGen::visitUnaryExprNode(UnaryExprNode* unary) {
    ExprNode* unaExprOperand;

    //visit val first
    unaExprOperand = unary->getOperand();
    // assert(unaExprOperand != nullptr);
    unaExprOperand->visit(this);
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
            LLVMIdx,
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
    //vist first
    ifStmt->getCondition()->visit(this);
    ifStmt->getThen()->visit(this);
    if (ifStmt->getHasElse()) ifStmt->getElse()->visit(this);
    ASTVisitorBase::visitIfStmtNode(ifStmt);
}

void IRGen::visitReturnStmtNode(ReturnStmtNode* ret) {
    ExprNode* retExpr;

    retExpr = ret->getReturn();
    if (retExpr != nullptr)
        retExpr->visit(this);

    Builder->CreateRet(ret->getReturn()->getLLVMValue());
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
    whileStmt->getCondition()->visit(this);
    whileStmt->getBody()->visit(this);
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
