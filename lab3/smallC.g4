//
//  smallC.g4
//  ECE467 Lab 3
//
//  Created by Tarek Abdelrahman on 2023-09-13.
//  Based on code written by Ao (Dino) Li for ECE467.
//  Copyright © 2023 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

grammar smallC;

@header {
#include "ASTNodes.h"
#include <iostream>
#include <string>
#include <vector>
}

program
returns [smallc::ProgramNode *prg]
@init {
    $prg = new smallc::ProgramNode();
    $prg->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    //cout << $prg << "<<< prg node addr in g4 at init\n";
}
: (preamble {$prg->setIo(true);}
| ) (decls
{
    for(unsigned int i = 0; i < $decls.declarations.size();i++){
        $prg->addChild($decls.declarations[i]);
        $decls.declarations[i]->setRoot($prg);
    }
}
)* EOF ;

preamble:  '#include' '"scio.h"';

decls 
returns [std::vector<smallc::DeclNode*> declarations]
    :
    scalarDeclList
    {
        for(unsigned int i = 0; i < $scalarDeclList.scalars.size(); i++){
            $declarations.push_back($scalarDeclList.scalars[i]);
        }
    }
    | arrDeclList
    {
        for(unsigned int i = 0; i < $arrDeclList.arrays.size(); i++){
            $declarations.push_back($arrDeclList.arrays[i]);
        }
    }
    | fcnProto
    {
        $declarations.push_back($fcnProto.fcnProtoNode);
    }
    | fcnDecl
    {   
        $declarations.push_back($fcnDecl.fcnDeclNode);
    }
;

scalarDeclList
returns [std::vector<smallc::ScalarDeclNode*> scalars]
    :
    scalarDecl
    {
        $scalars.push_back($scalarDecl.decl);
    }
    | scalarDecl
    {
        $scalars.push_back($scalarDecl.decl);
    }
    scalarDeclList
    {
        for(unsigned int i = 0; i < $scalarDeclList.scalars.size(); i++){
            $scalars.push_back($scalarDeclList.scalars[i]);
        }
    }
;

scalarDecl 
returns [smallc::ScalarDeclNode* decl] 
@init {$decl = new smallc::ScalarDeclNode();
       $decl->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}
    :
    varType 
    {
        $decl->setType($varType.typeNode);
    }
    varName
    {
        $decl->setName($varName.nameNode);
    }
    ';'
;

arrDeclList 
returns [std::vector<smallc::ArrayDeclNode*> arrays]
    :
    arrDecl
    {
        $arrays.push_back($arrDecl.decl);
    }
    | arrDecl 
    {
        $arrays.push_back($arrDecl.decl);
    }
    arrDeclList
    {
        for(unsigned int i = 0; i < $arrDeclList.arrays.size(); i++){
            $arrays.push_back($arrDeclList.arrays[i]);
        }
    }
;

arrDecl 
returns [smallc::ArrayDeclNode* decl]
locals [smallc::ArrayTypeNode* arrTypeNode]
@init {$decl = new smallc::ArrayDeclNode();
       $decl->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}
    :
    varType arrName '[' intConst ']' ';'
    {
        $arrTypeNode = new smallc::ArrayTypeNode($varType.typeNode);
        $arrTypeNode->setLine($varType.typeNode->getLine());
        $arrTypeNode->setColumn($varType.typeNode->getCol());
        $decl->setName($arrName.nameNode);
        $arrTypeNode->setSize(std::stoi($intConst.text));
        $decl->setType($arrTypeNode);
    }
;

fcnProto
returns [smallc::FunctionDeclNode* fcnProtoNode]
@init {
        $fcnProtoNode = new smallc::FunctionDeclNode();
        $fcnProtoNode->setProto(true);
        $fcnProtoNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}
    :
    retType 
    {
        $fcnProtoNode->setRetType($retType.typeNode);
    }
    fcnName 
    {
        $fcnProtoNode->setName($fcnName.nameNode);
    }
    '(' 
    params 
    {
        $fcnProtoNode->setParameter($params.parameterList);
    }
    ')' ';'
;

fcnDecl 
returns [smallc::FunctionDeclNode* fcnDeclNode]
@init {
        $fcnDeclNode = new smallc::FunctionDeclNode();
        $fcnDeclNode->setProto(false);
        $fcnDeclNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}
    :
    retType 
    {
        $fcnDeclNode->setRetType($retType.typeNode);
    }
    fcnName 
    {
        $fcnDeclNode->setName($fcnName.nameNode);
    }
    '(' 
    params 
    {
        $fcnDeclNode->setParameter($params.parameterList);
    }
    ')' 
    scope
    {
        $fcnDeclNode->setBody($scope.scope_);
    }

;

varType 
returns [smallc::PrimitiveTypeNode* typeNode]
@init {$typeNode = new smallc::PrimitiveTypeNode();
       $typeNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}:
    'bool'
    {
        $typeNode->setType(smallc::TypeNode::TypeEnum::Bool);
    }
    | 'int'
    {
        $typeNode->setType(smallc::TypeNode::TypeEnum::Int);
    }
;

retType 
returns [smallc::PrimitiveTypeNode* typeNode]
:
    'void'
    {
        $typeNode = new smallc::PrimitiveTypeNode();
        $typeNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $typeNode->setType(smallc::TypeNode::TypeEnum::Void);
    }
    | varType
    {
        $typeNode = $varType.typeNode;
    }
;

constant 
returns [smallc::ConstantExprNode* contExprNode]
    :
    boolConst
    {
        $contExprNode = new smallc::BoolConstantNode($boolConst.text);
        $contExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $contExprNode->setTypeBool();
    }
    | intConst
    {
        $contExprNode = new smallc::IntConstantNode($intConst.text);
        $contExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $contExprNode->setTypeInt();
    }
;

boolConst :
    BOOL
;

scope
returns[smallc::ScopeNode* scope_]
@init{
    $scope_ = new smallc::ScopeNode();
    $scope_->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
:
    '{' (scalarDecl
    {
        $scalarDecl.decl->setParent($scope_); 
        $scope_->addDeclaration($scalarDecl.decl);
    }
    |arrDecl
    {
        $arrDecl.decl->setParent($scope_); 
        $scope_->addDeclaration($arrDecl.decl);
    }
    )* (stmt
    {
        // $stmt.statement->setParent($scope_); 
        $scope_->addChild($stmt.statement);
    }
    )* '}'
;

stmt 
returns [smallc::StmtNode* statement]
locals [smallc::ExprStmtNode* exprStmt]:
    expr 
    {
        $exprStmt = new smallc::ExprStmtNode($expr.exprStmtNode);
        $statement = $exprStmt;
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    ';'
    | assignStmt
    {
        $statement = $assignStmt.assignStmtNode;
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | ifStmt
    {
        $statement = $ifStmt.ifStmtNode;
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | whileStmt
    {
        $statement = $whileStmt.whileStmtNode;
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | retStmt
    {
        $statement = $retStmt.retStmtNode;
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | scope
    {
        $statement = $scope.scope_;
        $statement->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;
//all statement locations are set above in "stmt"
assignStmt 
returns [smallc::AssignStmtNode* assignStmtNode]
@init {$assignStmtNode = new smallc::AssignStmtNode();}:
    var
    {
        $assignStmtNode->setTarget($var.target_);
    }
     '=' 
    expr 
    {
        $assignStmtNode->setValue($expr.exprStmtNode);
    }
    ';'
;

ifStmt 
returns [smallc::IfStmtNode* ifStmtNode]
@init {$ifStmtNode = new smallc::IfStmtNode();}:
    'if' '(' expr ')' stmt 
    {
        $ifStmtNode->setCondition($expr.exprStmtNode);
        $ifStmtNode->setThen($stmt.statement);
        $ifStmtNode->setHasElse(false);
        $expr.exprStmtNode->setParent($ifStmtNode);
        $stmt.statement->setParent($ifStmtNode);
    }
    | 'if' '(' expr ')' then=stmt 'else' e=stmt
    {
        $ifStmtNode->setCondition($expr.exprStmtNode);
        $ifStmtNode->setThen($then.statement);
        $ifStmtNode->setHasElse(true);
        $ifStmtNode->setElse($e.statement);
        $expr.exprStmtNode->setParent($ifStmtNode);
        $then.statement->setParent($ifStmtNode);
        $e.statement->setParent($ifStmtNode);
    }
;

whileStmt 
returns [smallc::WhileStmtNode* whileStmtNode]
@init {$whileStmtNode = new smallc::WhileStmtNode();}:
    'while' '(' expr ')' stmt
    {
        $whileStmtNode->setCondition($expr.exprStmtNode);
        $whileStmtNode->setBody($stmt.statement);
    }
;


retStmt 
returns [smallc::ReturnStmtNode* retStmtNode]
@init {$retStmtNode = new smallc::ReturnStmtNode();}:
    'return' expr ';'
    {
        $retStmtNode->setReturn($expr.exprStmtNode);
    }
    |'return' ';'
    {
        //$retStmtNode->setReturn(nullptr);
    }
;

expr 
returns [smallc::ExprNode* exprStmtNode]
locals [smallc::BinaryExprNode* binaryExprNode, smallc::UnaryExprNode* unaryExprNode, smallc::CallExprNode* funcCallNode, smallc::IdentifierNode* funcName, smallc::BoolExprNode* boolexpr]
    :
    intExpr
    {
        $exprStmtNode = $intExpr.intExprNode;
        // $exprStmtNode->setTypeInt();
    }
    | '(' 
    expr
    {
        $exprStmtNode = $expr.exprStmtNode;
    }
     ')'
    | fcnName '(' args ')'
    {
        $funcCallNode = new smallc::CallExprNode();
        $funcCallNode->setIdent($fcnName.nameNode);
        $funcCallNode->setArguments($args.argsList);
        $exprStmtNode = $funcCallNode;
        $exprStmtNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exprStmtNode->setTypeVoid();
    }
    | op=('!' | '-') expr
    {
        $unaryExprNode = new smallc::UnaryExprNode($expr.exprStmtNode);
        $unaryExprNode->setOpcode($op.text);
        $exprStmtNode = $unaryExprNode;
        if ($op.text == "!") $exprStmtNode->setTypeBool();
        if ($op.text == "-") $exprStmtNode->setTypeInt();
        $exprStmtNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        
    }
    | l=expr op=('<' | '<=' | '>' | '>=') r=expr
    {
        $binaryExprNode = new smallc::BinaryExprNode($l.exprStmtNode, $r.exprStmtNode);
        $binaryExprNode->setOpcode($op.text);
        $binaryExprNode->setTypeBool();
        $boolexpr = new smallc::BoolExprNode($binaryExprNode);
        $binaryExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exprStmtNode = $boolexpr;
        $exprStmtNode->setTypeBool();
        $exprStmtNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | l=expr op=('==' | '!=') r=expr
    {
        $binaryExprNode = new smallc::BinaryExprNode($l.exprStmtNode, $r.exprStmtNode);
        $binaryExprNode->setOpcode($op.text);
        $binaryExprNode->setTypeBool();
        $boolexpr = new smallc::BoolExprNode($binaryExprNode);
        $binaryExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exprStmtNode = $boolexpr;
        $exprStmtNode->setTypeBool();
        $exprStmtNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | l=expr op='||' r=expr
    {
        $binaryExprNode = new smallc::BinaryExprNode($l.exprStmtNode, $r.exprStmtNode);
        $binaryExprNode->setOpcode($op.text);
        $binaryExprNode->setTypeBool();
        $boolexpr = new smallc::BoolExprNode($binaryExprNode);
        $binaryExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exprStmtNode = $boolexpr;
        $exprStmtNode->setTypeBool();
        $exprStmtNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
    | l=expr op='&&' r=expr
    {
        $binaryExprNode = new smallc::BinaryExprNode($l.exprStmtNode, $r.exprStmtNode);
        $binaryExprNode->setOpcode($op.text);
        $binaryExprNode->setTypeBool();
        $boolexpr = new smallc::BoolExprNode($binaryExprNode);
        $binaryExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $exprStmtNode = $boolexpr;
        $exprStmtNode->setTypeBool();
        $exprStmtNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
    }
;

//int type set in expr class
intExpr 
returns [smallc::IntExprNode* intExprNode]
locals [smallc::BinaryExprNode* binaryExprNode]
    :
    var
    {
        $intExprNode = new smallc::IntExprNode($var.target_);
        $intExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $intExprNode->setTypeVoid();
    }
    | constant
    {
        $intExprNode = new smallc::IntExprNode($constant.contExprNode);
        $intExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $intExprNode->setType($constant.contExprNode->getType());
    }
    | l=intExpr op=('*' | '/' ) r=intExpr
    {
        $binaryExprNode = new smallc::BinaryExprNode($l.intExprNode, $r.intExprNode);
        $binaryExprNode->setOpcode($op.text);
        $binaryExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $binaryExprNode->setTypeInt();
        $intExprNode = new smallc::IntExprNode($binaryExprNode);
        $intExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $intExprNode->setTypeInt();
    }
    | l=intExpr op=('+' | '-' ) r=intExpr
    {
        $binaryExprNode = new smallc::BinaryExprNode($l.intExprNode, $r.intExprNode);
        $binaryExprNode->setOpcode($op.text);
        $binaryExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $binaryExprNode->setTypeInt();
        $intExprNode = new smallc::IntExprNode($binaryExprNode);
        $intExprNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
        $intExprNode->setTypeInt();
    }
    | '(' 
    intExpr
    {
        $intExprNode = $intExpr.intExprNode;
    }
    ')'
;

var 
returns [smallc::ReferenceExprNode* target_]
@init {$target_ = new smallc::ReferenceExprNode();
       $target_->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
       $target_->setTypeVoid();}:
    varName
    {
        $target_->setIdent($varName.nameNode);
        // $target_->setIndex(nullptr);
    }
    //ints have index ptr == null
    | arrName
    {
        $target_->setIdent($arrName.nameNode);
    } 
    '[' 
    intExpr 
    {
        $target_->setIndex($intExpr.intExprNode);
    }
    ']'
;

params 
returns [std::vector<smallc::ParameterNode*> parameterList]:
    paramList
    {
        for(unsigned int i = 0; i < $paramList.parameterList.size(); i++)
            $parameterList.push_back($paramList.parameterList[i]);
    }
    | ;

paramEntry 
returns [smallc::ParameterNode* paramEntryNode]
locals [smallc::ArrayTypeNode* arrTypeNode]
@init {$paramEntryNode = new smallc::ParameterNode();
       $paramEntryNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}:
    varType 
    {
        $paramEntryNode->setType($varType.typeNode);
    }
    varName
    {
        $paramEntryNode->setIdent($varName.nameNode);
    }
    | varType 
    {
        $arrTypeNode = new smallc::ArrayTypeNode($varType.typeNode);
        $arrTypeNode->setLine($varType.typeNode->getLine());
        $arrTypeNode->setColumn($varType.typeNode->getCol());
        $paramEntryNode->setType($arrTypeNode);
    }
    arrName
    {
        $paramEntryNode->setIdent($arrName.nameNode);
    }
    '[]'
;

paramList 
returns [std::vector<smallc::ParameterNode*> parameterList]:
    paramEntry
    {
       $parameterList.push_back($paramEntry.paramEntryNode);
    }
    | paramEntry
    {
       $parameterList.push_back($paramEntry.paramEntryNode);
    }
    ',' 
    paramList
    {
        for(unsigned int i = 0; i < $paramList.parameterList.size(); i++)
            $parameterList.push_back($paramList.parameterList[i]);
    }
;

args 
returns [std::vector<smallc::ArgumentNode*> argsList]:
    argList
    {
        for(unsigned int i = 0; i < $argList.argsList.size(); i++)
            $argsList.push_back($argList.argsList[i]);
    }
    |
;

//SetArray in symbol table phase
argEntry 
returns [smallc::ArgumentNode* argEntryNode]
@init {$argEntryNode = new smallc::ArgumentNode();
       $argEntryNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());}:
    expr
    {
        $argEntryNode->setExpr($expr.exprStmtNode);
    }
;

argList 
returns [std::vector<smallc::ArgumentNode*> argsList]:
    argEntry
    {
        $argsList.push_back($argEntry.argEntryNode);
    }
    | argEntry
    {
        $argsList.push_back($argEntry.argEntryNode);
    }
     ',' 
    argList
    {
        for(unsigned int i = 0; i < $argList.argsList.size(); i++)
            $argsList.push_back($argList.argsList[i]);
    };

varName
returns[smallc::IdentifierNode* nameNode] 
: t = ID
{
    $nameNode = new smallc::IdentifierNode($t.text);
    $nameNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
;

arrName 
returns[smallc::IdentifierNode* nameNode] 
: t = ID
{
    $nameNode = new smallc::IdentifierNode($t.text);
    $nameNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
;

fcnName 
returns[smallc::IdentifierNode* nameNode]
: t = ID
{
    $nameNode = new smallc::IdentifierNode($t.text);
    $nameNode->setLocation($ctx->start->getLine(), $ctx->start->getCharPositionInLine());
}
;

intConst : INT
| '-' INT
;

BOOL: 'true' | 'false';
ID: [a-zA-Z][a-zA-Z0-9_]* ;
INT:    [0] | ([1-9][0-9]*);
WS:     [ \t\r\n]+ -> skip;
COMMENT: '//' (~[\r\n])* -> skip;
