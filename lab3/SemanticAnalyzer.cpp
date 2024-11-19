//
//  SemanticAnalyzer.cpp
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

#include "ASTVisitorBase.h"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <type_traits>
#include <vector>
using namespace std;

#include "SemanticAnalyzer.h"
#include "SymTable.h"
#include "assert.h"
#include <algorithm>    // std::min
using namespace smallc;

namespace smallc {

SemaError::SemaError (ErrorEnum code_, std::pair<unsigned int, unsigned int> location_) : code(code_), location(location_), msg() { }

SemaError::SemaError(ErrorEnum code_, std::pair<unsigned int, unsigned int> location_, std::string msg_) : code(code_), location(location_), msg(msg_) { }

// Constructor
SemanticAnalyzer::SemanticAnalyzer (): ASTVisitorBase(), prog(nullptr), errors() {}

// Print all the error messages at once
void
SemanticAnalyzer::printErrorMsgs () {
    for (const auto& e : errors) {
        std::cout << "sema: " << e.location.first
                  << ":" << e.location.second << " : ";
        switch (e.code) {
            case SemaError::IdentReDefined:
                std::cout << "redefinition of";
                break;
            case SemaError::IdentUnDefined:
                std::cout << "use of undefined identifier";
                break;
            case SemaError::NoMatchingDef:
                std::cout << "no matching definition for";
                break;
            case SemaError::MisMatchedReturn:
                std::cout << "mismatched return statement";
                break;
            case SemaError::InconsistentDef:
                std::cout << "definition inconsistent with earlier definition of";
                break;
            case SemaError::InvalidCond:
                std::cout << "invalid condition in";
                break;
            case SemaError::TypeMisMatch:
                std::cout << "type mismatch";
                break;
            case SemaError::InvalidArraySize:
                std::cout << "size cannot be negative for array";
                break;
            case SemaError::InvalidAccess:
                std::cout << "invalid use of identifier";
                break;
            default:
                std::cout << "unknown error number";
                break;
        }
        std::cout << " " << e.msg << std::endl;
    }
}

// Add an error to the list of errors
void
SemanticAnalyzer::addError (const SemaError& err) {
    errors.push_back(err);
}

// ECE467 STUDENT: implement the visitor classes, perfoming
// semantic analysis
void SemanticAnalyzer::visitASTNode(ASTNode *node) {
    ASTVisitorBase::visitASTNode(node);
}

void SemanticAnalyzer::visitArgumentNode(ArgumentNode *arg) {
    IntExprNode* intExpr;
    ReferenceExprNode* refExpr;
    ScopeNode* scope = nullptr;
    ProgramNode* prg = nullptr;
    IntExprNode* refIdxPtr;
    ArgumentNode* argptr;
    SymTable<VariableEntry>* varST;
    ASTNode* parent;
    ArrayTypeNode* arrVarType;
    bool decleared;
    
    //visit expression
    arg->getExpr()->visit(this);

    //set isArr for current arg
    intExpr = dynamic_cast<IntExprNode*>(arg->getExpr());
    if (intExpr != nullptr) 
        refExpr = dynamic_cast<ReferenceExprNode*>(intExpr->getValue());
    if (intExpr != nullptr && refExpr != nullptr){
        parent = arg->getParent();
        decleared = false;
        while (parent != nullptr) {
            scope = dynamic_cast<ScopeNode*>(parent);
            prg = dynamic_cast<ProgramNode*>(parent);
            if (scope != nullptr) {
                varST = scope->getVarTable();
                decleared = varST->contains(refExpr->getIdent()->getName());
            }
            if (prg != nullptr) {
                varST = prg->getVarTable();
                decleared = varST->contains(refExpr->getIdent()->getName());
            }
            parent = parent->getParent();
            if (decleared) break;
        }
        if (decleared) {
            VariableEntry &currVar = varST->get(refExpr->getIdent()->getName());
            arrVarType = dynamic_cast<ArrayTypeNode*>(currVar.getType());
            if (arrVarType != nullptr && refExpr->getIndex() == nullptr)
                arg->setArray();
        }
    }
    

    ASTVisitorBase::visitArgumentNode(arg);
}

void SemanticAnalyzer::visitDeclNode(DeclNode *decl) {
    ASTVisitorBase::visitDeclNode(decl);
}

void SemanticAnalyzer::visitArrayDeclNode(ArrayDeclNode *array) {
    // assert(array->getParent()->hasVarTable());
    ArrayTypeNode* arrayType = array->getType();
    std::string arrayName = array->getIdent()->getName();
    SymTable<VariableEntry>* varST;
    VariableEntry* newVar;

    //check if parent is prg or scope
    if (array->getParent() == array->getRoot()) 
        varST = array->getRoot()->getVarTable();
    else
        varST = (dynamic_cast<ScopeNode*>(array->getParent()))->getVarTable();

    //raise error if redef
    if (varST->contains(arrayName)){
        addError(SemaError(SemaError::IdentReDefined, array->getLocation(), arrayName));
    } else {
        if (arrayType->getSize() > 0){
            newVar = new VariableEntry(arrayType);
            varST->insert(arrayName, *newVar);
        } else {
            addError(SemaError(SemaError::InvalidArraySize, array->getLocation(), arrayName));
        }
    }

    ASTVisitorBase::visitArrayDeclNode(array);
}

void SemanticAnalyzer::visitFunctionDeclNode(FunctionDeclNode *func) {
    // assert(func->getParent() == func->getRoot());
    // assert(func->getRoot()->hasVarTable());

    ProgramNode* root = func->getRoot();
    SymTable<FunctionEntry>* funcST = root->getFuncTable();
    SymTable<VariableEntry>* varST;
    VariableEntry* newVar;
    ParameterNode* currPara;
    std::string funcName = func->getIdent()->getName();
    std::vector<TypeNode*> funcSTtypes;
    std::vector<ParameterNode*> funcParams;
    FunctionEntry* newFunc;
    bool numParam_match, param_type_match;

    funcParams = func->getParams();

    //check if func name exists
    if(funcST->contains(funcName)){
        //fetch the func
        FunctionEntry& existingFunc = funcST->get(funcName);
        funcSTtypes = existingFunc.getParameterTypes();
        numParam_match = funcSTtypes.size() == func->getNumParameters();
        param_type_match = true;

        for (int i = 0; i < func->getNumParameters() && numParam_match; i++){
            param_type_match = (funcSTtypes[i]->getTypeEnum() == funcParams[i]->getType()->getTypeEnum())
                                && (funcSTtypes[i]->isArray() == funcParams[i]->getType()->isArray());
            if (!param_type_match)
                break;
        }

        //if existingFunc is a proto, but input don't match return type/param
        if (existingFunc.proto && (existingFunc.getReturnType()->getTypeEnum() != func->getRetType()->getTypeEnum() || !numParam_match || !param_type_match))
            addError(SemaError(SemaError::InconsistentDef, func->getLocation(), funcName));
        //not proto, then redefinition
        else if (!existingFunc.proto && (existingFunc.getReturnType()->getTypeEnum() == func->getRetType()->getTypeEnum() && numParam_match && param_type_match))
            addError(SemaError(SemaError::IdentReDefined, func->getLocation(), funcName));
        existingFunc.proto = func->getProto();

    } else {
        newFunc = new FunctionEntry();
        newFunc->returnType = func->getRetType();
        for (int i = 0; i < func->getNumParameters(); i++)
            newFunc->parameterTypes.push_back(funcParams[i]->getType());
        newFunc->proto = func->getProto();
        funcST->insert(funcName, *newFunc);
    }

    //if func got body
    if (!func->getProto()){
        //add params to scope var table
        // assert(func->getBody()->hasVarTable());
        varST = func->getBody()->getVarTable();
        for (int i = 0; i < func->getNumParameters(); i++){
            currPara = funcParams[i];
            if (currPara->getType()->isArray()) 
                newVar = new VariableEntry(dynamic_cast<ArrayTypeNode*>(currPara->getType()));
            else 
                newVar = new VariableEntry(dynamic_cast<PrimitiveTypeNode*>(currPara->getType()));            
            varST->insert(currPara->getIdent()->getName(), *newVar);
        }
        //visit scope
        func->getBody()->visit(this);
    }
    ASTVisitorBase::visitFunctionDeclNode(func);
}

void SemanticAnalyzer::visitScalarDeclNode(ScalarDeclNode *scalar) {
    // assert(scalar->getParent()->hasVarTable());
    PrimitiveTypeNode* scalarType = scalar->getType();
    std::string scalarName = scalar->getIdent()->getName();
    SymTable<VariableEntry>* varST;
    VariableEntry* newVar;

    //check if parent is prg or scope
    if (scalar->getParent() == scalar->getRoot()){
        varST = scalar->getRoot()->getVarTable();
    }
    else{
        varST = (dynamic_cast<ScopeNode*>(scalar->getParent()))->getVarTable();
    }

    //raise error if redef
    if (varST->contains(scalarName)){
        addError(SemaError(SemaError::IdentReDefined, scalar->getLocation(), scalarName));
    } else {
        newVar = new VariableEntry(scalarType);
        varST->insert(scalarName, *newVar);
    }
    ASTVisitorBase::visitScalarDeclNode(scalar);
}

void SemanticAnalyzer::visitExprNode(ExprNode *exp) {
    ASTVisitorBase::visitExprNode(exp);
}

void SemanticAnalyzer::visitBinaryExprNode(BinaryExprNode *bin) {
    PrimitiveTypeNode* leftType;
    PrimitiveTypeNode* rightType;
    TypeNode::TypeEnum leftTpEnum, rightTpEnum;
    ExprNode::Opcode binOP;
    bool noError;

    //visit nodes
    bin->getLeft()->visit(this);
    bin->getRight()->visit(this);

    //get type for left and right operands
    leftType = bin->getLeft()->getType();
    rightType = bin->getRight()->getType();
    // assert(leftType != nullptr && rightType != nullptr);
    leftTpEnum = leftType->getTypeEnum();
    rightTpEnum = rightType->getTypeEnum();

    //type mismatch check
    binOP = bin->getOpcode();
    noError = true;
    switch (binOP) {
        case ExprNode::Addition:
        case ExprNode::Subtraction:
        case ExprNode::Multiplication:
        case ExprNode::Division:
            if (!(leftTpEnum == TypeNode::TypeEnum::Int && rightTpEnum == TypeNode::TypeEnum::Int)){
                addError(SemaError(SemaError::TypeMisMatch, bin->getLocation()));
                noError = false;
            }
            break;
        case ExprNode::Not:
            // assert(false);
        case ExprNode::Minus:
            // assert(false);
        case ExprNode::And:
        case ExprNode::Or:
            if (!(leftTpEnum == TypeNode::TypeEnum::Bool && rightTpEnum == TypeNode::TypeEnum::Bool)){
                addError(SemaError(SemaError::TypeMisMatch, bin->getLocation()));
                noError = false;
            }
            break;
        case ExprNode::Equal:
        case ExprNode::NotEqual:
        case ExprNode::LessThan:
        case ExprNode::LessorEqual:
        case ExprNode::Greater:
        case ExprNode::GreaterorEqual:
            //int and bool are both allowed
            if (!(leftTpEnum == rightTpEnum && rightTpEnum != TypeNode::TypeEnum::Void)){
                addError(SemaError(SemaError::TypeMisMatch, bin->getLocation()));
                noError = false;
            }
            break;
        default:
            // assert(false);
            break;
    }
    //set void for error chaining
    if (!noError)
        bin->setTypeVoid();
    ASTVisitorBase::visitBinaryExprNode(bin);
}

void SemanticAnalyzer::visitBoolExprNode(BoolExprNode *boolExpr) {
    ExprNode* boolExprVal;

    //visit val first
    boolExprVal = boolExpr->getValue();
    // assert(boolExprVal != nullptr);
    boolExprVal->visit(this);

    //check and set type
    boolExpr->setType(boolExprVal->getType());

    ASTVisitorBase::visitBoolExprNode(boolExpr);
}

void SemanticAnalyzer::visitCallExprNode(CallExprNode *call) {
    //if name no match: undefined
    //if name match but param no match: no matching def
    std::vector<ArgumentNode*> funcArgs;
    std::vector<TypeNode*> exisitngFuncParam;
    ASTNode* parent = nullptr;
    SymTable<FunctionEntry>* funcST;
    bool decleared;
    bool numParamMatch, typeParamMatch;
    bool noError;

    funcArgs = call->getArguments();
    parent = call->getParent();
    decleared = false;
    funcST = nullptr;
    noError = true;

    //search for func name in ST
    while (parent != nullptr) {
        if (parent->getParent() == nullptr){
            funcST = dynamic_cast<ProgramNode*>(parent)->getFuncTable();
            decleared = funcST->contains(call->getIdent()->getName());
        }
        parent = parent->getParent();
        if (decleared) break;
    }

    //raise undefiend
    if (!decleared){
        addError(SemaError(SemaError::IdentUnDefined, call->getLocation(), call->getIdent()->getName()));
        noError = false;
    }

    //visit args
    for (int i = 0; i < funcArgs.size(); i++){
        funcArgs[i]->visit(this);
    }

    //check for arg type/num match
    if (decleared && funcST != nullptr){
        FunctionEntry &existingFunc = funcST->get(call->getIdent()->getName());
        exisitngFuncParam = existingFunc.getParameterTypes();
        numParamMatch = exisitngFuncParam.size() == funcArgs.size();
        typeParamMatch = true;
        //check isArr from argument node, check type for arg.expr
        for (int i = 0; i < funcArgs.size() && numParamMatch; i++){
            // std::cout << "ex type " << exisitngFuncParam[i]->getTypeEnum() << " arg type " << funcArgs[i]->getExpr()->getType()->getTypeEnum() << std::endl;
            // std::cout << "ex isArr " << exisitngFuncParam[i]->isArray() << " arg isArr " << funcArgs[i]->isArray() << std::endl;
            typeParamMatch = (exisitngFuncParam[i]->getTypeEnum() == funcArgs[i]->getExpr()->getType()->getTypeEnum())
                                && (exisitngFuncParam[i]->isArray() == funcArgs[i]->isArray());
            if (!typeParamMatch)
                break;
        }
        if (!typeParamMatch || !numParamMatch){
            addError(SemaError(SemaError::NoMatchingDef, call->getLocation(), call->getIdent()->getName()));
            noError = false;
        }
        if (noError){
            //chaining error, func call expression is default to void, set in smallc.g4
            call->setType(existingFunc.getReturnType());
        }
    }
    ASTVisitorBase::visitCallExprNode(call);
}

void SemanticAnalyzer::visitConstantExprNode(ConstantExprNode *constant) {
    ASTVisitorBase::visitConstantExprNode(constant);
}

void SemanticAnalyzer::visitBoolConstantNode(BoolConstantNode *boolConst) {
    ASTVisitorBase::visitBoolConstantNode(boolConst);
}

void SemanticAnalyzer::visitIntConstantNode(IntConstantNode *intConst) {
    ASTVisitorBase::visitIntConstantNode(intConst);
}

void SemanticAnalyzer::visitIntExprNode(IntExprNode *intExpr) {
    ExprNode* intExprVal;

    //visit val first
    intExprVal = intExpr->getValue();
    // assert(intExprVal != nullptr);
    intExprVal->visit(this);

    //check and set void
    intExpr->setType(intExprVal->getType());
    ASTVisitorBase::visitIntExprNode(intExpr);
}

void SemanticAnalyzer::visitReferenceExprNode(ReferenceExprNode *ref) {
    //search parent until parent is null
    //if there is a var table, check if var table contains ver name
    //do not handle func call here
    //how to NOT check for return stmt????
    ASTNode* parent = nullptr;
    SymTable<VariableEntry>* varST;
    PrimitiveTypeNode* primTypePtr;
    ArrayTypeNode* arrTypePtr;
    ScopeNode* scope = nullptr;
    ProgramNode* prg = nullptr;
    IntExprNode* refIdxPtr;
    ArgumentNode* argptr;
    bool decleared;

    parent = ref->getParent();
    decleared = false;
    while (parent != nullptr) {
        scope = dynamic_cast<ScopeNode*>(parent);
        prg = dynamic_cast<ProgramNode*>(parent);
        if (scope != nullptr) {
            varST = scope->getVarTable();
            decleared = varST->contains(ref->getIdent()->getName());
        }
        if (prg != nullptr) {
            varST = prg->getVarTable();
            decleared = varST->contains(ref->getIdent()->getName());
        }
        parent = parent->getParent();
        if (decleared) break;
    }

    if (!decleared){
        addError(SemaError(SemaError::IdentUnDefined, ref->getLocation(), ref->getIdent()->getName()));
        ref->setTypeVoid();
    } else {
        //config vartype
        VariableEntry& currVar = varST->get(ref->getIdent()->getName());
        primTypePtr = dynamic_cast<PrimitiveTypeNode*>(currVar.getType());
        arrTypePtr = dynamic_cast<ArrayTypeNode*>(currVar.getType());
        argptr = dynamic_cast<ArgumentNode*>(ref->getParent()->getParent());
        // assert(primTypePtr == nullptr || arrTypePtr == nullptr);
        refIdxPtr = ref->getIndex();

        if (primTypePtr != nullptr){
            ref->setType(primTypePtr);
            if (refIdxPtr != nullptr){
                addError(SemaError(SemaError::InvalidAccess, ref->getLocation(), ref->getIdent()->getName()));
                ref->setTypeVoid();
            }
        }
        if (arrTypePtr != nullptr){
            if (arrTypePtr->getTypeEnum() == TypeNode::Bool) ref->setTypeBool();
            if (arrTypePtr->getTypeEnum() == TypeNode::Int) ref->setTypeInt();
            if (refIdxPtr == nullptr && argptr == nullptr){
                addError(SemaError(SemaError::InvalidAccess, ref->getLocation(), ref->getIdent()->getName()));
                ref->setTypeVoid();
            }
        }
    }

    ASTVisitorBase::visitReferenceExprNode(ref);
}

void SemanticAnalyzer::visitUnaryExprNode(UnaryExprNode *unary) {
    ExprNode* unaExprOperand;

    //visit val first
    unaExprOperand = unary->getOperand();
    // assert(unaExprOperand != nullptr);
    unaExprOperand->visit(this);

    //set err location as unary's child
    PrimitiveTypeNode* operandType;
    TypeNode::TypeEnum operandTpEnum;
    ExprNode::Opcode unaOP;
    bool noError;

    //get type for left and right operands
    operandType = unaExprOperand->getType();
    operandTpEnum = operandType->getTypeEnum();

    //type mismatch check
    unaOP = unary->getOpcode();
    noError = true;
    switch (unaOP) {
        case ExprNode::Not:
            if (!(operandTpEnum == TypeNode::TypeEnum::Bool)){
                addError(SemaError(SemaError::TypeMisMatch, unaExprOperand->getLocation()));
                noError = false;
            }
            break;
        case ExprNode::Minus:
            if (!(operandTpEnum == TypeNode::TypeEnum::Int)){
                addError(SemaError(SemaError::TypeMisMatch, unaExprOperand->getLocation()));
                noError = false;
            }
            break;
        default:
            // assert(false);
            break;
    }

    //set void for error chaining
    if (!noError)
        unary->setTypeVoid();

    ASTVisitorBase::visitUnaryExprNode(unary);
}

void SemanticAnalyzer::visitIdentifierNode(IdentifierNode *id) {
    ASTVisitorBase::visitIdentifierNode(id);
}

void SemanticAnalyzer::visitParameterNode(ParameterNode *param) {
    ASTVisitorBase::visitParameterNode(param);
}

void SemanticAnalyzer::visitProgramNode(ProgramNode *prg) {
    // assert(prg->getParent() == nullptr);
    SymTable<FunctionEntry> *funcSt;
    std::vector<TypeNode*> paramTypeVec;
    FunctionEntry* newFunc;
    PrimitiveTypeNode* funcRetType;
    PrimitiveTypeNode* paramType;

    if (prg->useIo()){
        funcSt = prg->getFuncTable();
        //readBool
        funcRetType = new PrimitiveTypeNode(TypeNode::Bool);
        newFunc = new FunctionEntry(funcRetType, paramTypeVec);
        newFunc->proto = true;
        funcSt->insert("readBool", *newFunc);
        //readInt
        funcRetType = new PrimitiveTypeNode(TypeNode::Int);
        newFunc = new FunctionEntry(funcRetType, paramTypeVec);
        newFunc->proto = true;
        funcSt->insert("readInt", *newFunc);
        //newLine
        funcRetType = new PrimitiveTypeNode(TypeNode::Void);
        newFunc = new FunctionEntry(funcRetType, paramTypeVec);
        newFunc->proto = true;
        funcSt->insert("newLine", *newFunc);
        //writeBool
        funcRetType = new PrimitiveTypeNode(TypeNode::Void);
        paramType = new PrimitiveTypeNode(TypeNode::Bool);
        paramTypeVec.clear();
        paramTypeVec.push_back(paramType);
        newFunc = new FunctionEntry(funcRetType, paramTypeVec);
        newFunc->proto = true;
        funcSt->insert("writeBool", *newFunc);
        //writeInt
        funcRetType = new PrimitiveTypeNode(TypeNode::Void);
        paramType = new PrimitiveTypeNode(TypeNode::Int);
        paramTypeVec.clear();
        paramTypeVec.push_back(paramType);
        newFunc = new FunctionEntry(funcRetType, paramTypeVec);
        newFunc->proto = true;
        funcSt->insert("writeInt", *newFunc);
    }

    ASTVisitorBase::visitProgramNode(prg);
}

void SemanticAnalyzer::visitStmtNode(StmtNode *stmt) {
    ASTVisitorBase::visitStmtNode(stmt);
}

void SemanticAnalyzer::visitAssignStmtNode(AssignStmtNode *assign) {
    TypeNode::TypeEnum targetType;
    TypeNode::TypeEnum valType;

    //visit target and val
    assign->getTarget()->visit(this);
    assign->getValue()->visit(this);

    //get and check type
    targetType = assign->getTarget()->getType()->getTypeEnum();
    valType = assign->getValue()->getType()->getTypeEnum();
    if (!(targetType == valType && targetType != TypeNode::Void)){
        addError(SemaError(SemaError::TypeMisMatch, assign->getLocation()));
    }

    ASTVisitorBase::visitAssignStmtNode(assign);
}

void SemanticAnalyzer::visitExprStmtNode(ExprStmtNode *expr) {
    expr->getExpr()->visit(this);
    ASTVisitorBase::visitExprStmtNode(expr);
}

void SemanticAnalyzer::visitIfStmtNode(IfStmtNode *ifStmt) {
    TypeNode::TypeEnum conditionType;

    //vist first
    ifStmt->getCondition()->visit(this);
    ifStmt->getThen()->visit(this);
    if (ifStmt->getHasElse()) ifStmt->getElse()->visit(this);

    //check type
    conditionType = ifStmt->getCondition()->getType()->getTypeEnum();
    if(conditionType != TypeNode::Bool){
        addError(SemaError(SemaError::InvalidCond, ifStmt->getLocation(), "if statement"));
    }

    ASTVisitorBase::visitIfStmtNode(ifStmt);
}

void SemanticAnalyzer::visitReturnStmtNode(ReturnStmtNode *ret) {
    //go up to scope, then go up to func Decl, fetch return type from func Decl
    //use loop to walk up the tree
    ASTNode* parent;
    FunctionDeclNode* funcDeclPtr;
    PrimitiveTypeNode* funcRetTypePtr;
    PrimitiveTypeNode* retExprType;
    ExprNode* retExpr;
    SymTable<FunctionEntry>* funcST;
    ProgramNode* prg;

    //vist retExpr first
    retExpr = ret->getReturn();
    if (retExpr != nullptr)
        retExpr->visit(this);

    //search up the tree for the func dec
    parent = ret->getParent();
    while (parent != nullptr){
        funcDeclPtr = dynamic_cast<FunctionDeclNode*>(parent);
        if (funcDeclPtr != nullptr) break;
        parent = parent->getParent();
    }
    // assert(parent != nullptr && funcDeclPtr != nullptr);

    //search up the tree for the func ST
    parent = ret->getParent();
    while (parent->getParent() != nullptr){
        parent = parent->getParent();
    }
    prg = dynamic_cast<ProgramNode*>(parent);
    // assert(prg != nullptr);
    funcST = prg->getFuncTable();
    FunctionEntry& funcProto = funcST->get(funcDeclPtr->getIdent()->getName());

    //fecth ret type and do check
    funcRetTypePtr = funcProto.getReturnType();
    if (retExpr == nullptr){
        if (funcRetTypePtr->getTypeEnum() != TypeNode::Void){
            addError(SemaError(SemaError::MisMatchedReturn, ret->getLocation()));
        }
    } else {
        retExprType = retExpr->getType();
        if (retExprType->getTypeEnum() != funcRetTypePtr->getTypeEnum() 
            || funcRetTypePtr->getTypeEnum() == TypeNode::Void){
            addError(SemaError(SemaError::MisMatchedReturn, ret->getLocation()));
        }
    }

    ASTVisitorBase::visitReturnStmtNode(ret);
}

void SemanticAnalyzer::visitScopeNode(ScopeNode *scope) {
    std::vector<DeclNode*> scopeDecles;
    scopeDecles = scope->getDeclarations();
    for (int i = 0; i < scopeDecles.size(); i++)
        scopeDecles[i]->visit(this);
    ASTVisitorBase::visitScopeNode(scope);
}

void SemanticAnalyzer::visitWhileStmtNode(WhileStmtNode *whileStmt) {
    TypeNode::TypeEnum conditionType;

    //visit
    whileStmt->getCondition()->visit(this);
    whileStmt->getBody()->visit(this);

    //check type
    conditionType = whileStmt->getCondition()->getType()->getTypeEnum();
    if(conditionType != TypeNode::Bool){
        addError(SemaError(SemaError::InvalidCond, whileStmt->getLocation(), "while statement"));
    }

    ASTVisitorBase::visitWhileStmtNode(whileStmt);
}

void SemanticAnalyzer::visitTypeNode(TypeNode *type) {
    ASTVisitorBase::visitTypeNode(type);
}

void SemanticAnalyzer::visitPrimitiveTypeNode(PrimitiveTypeNode *type) {
    ASTVisitorBase::visitPrimitiveTypeNode(type);
}

void SemanticAnalyzer::visitArrayTypeNode(ArrayTypeNode *type) {
    ASTVisitorBase::visitArrayTypeNode(type);
}
} // namespace
