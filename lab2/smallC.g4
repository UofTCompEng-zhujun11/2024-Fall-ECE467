//
//  smallC.g4
//  ECE467 Lab 2
//
//  Created by Tarek Abdelrahman on 2023-08-21.
//  Modified by Tarek Abdelrahman on 2024-09-21.
//  Copyright © 2023-2024 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE467 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

// This file contains the skeltal code for the smallC grammar

// ECE467 student: please 
//    1. complete the rules as indicated,
//    2. do NOT change the name of grammar
//    3. do NOT change the names of the non-terminals
//    4. do NOT change the order of the rules 
//    5. do NOT change the names of the takens

grammar smallC;

program: (preamble | ) decls* EOF;

preamble:  '#include' '"scio.h"';

decls:
    scalarDeclList
    | arrDeclList
    | fcnProto
    | fcnDecl
    ;

scalarDeclList:
    scalarDecl|
    scalarDecl scalarDeclList
;

scalarDecl: varType varName ';';

arrDeclList:
    arrDecl|
    arrDecl arrDeclList
;

arrDecl: // ECE467 student: add rule
    varType arrName '[' intConst ']' ';'
;

fcnProto: // ECE467 student: add rule
    retType fcnName '(' params ')' ';'
;

fcnDecl: // ECE467 student: add rule
    retType fcnName '(' params ')' scope
;

varType: // ECE467 student: add rule
    'bool' | 'int'
;

retType: // ECE467 student: add rule
    'void' | varType
;

constant: // ECE467 student: add rule
    boolConst | intConst
;

scope: // ECE467 student: add rule
    '{' (scalarDecl | arrDecl)* (stmt)* '}'
;

stmt: // ECE467 student: add rule
    expr ';'
    | assignStmt
    | ifStmt
    | whileStmt
    | retStmt
    | scope
;

assignStmt: // ECE467 student: add rule
    var '=' expr ';'
;

ifStmt: // ECE467 student: add rule
    'if' '(' expr ')' stmt
    | 'if' '(' expr ')' stmt 'else' stmt
;

whileStmt: // ECE467 student: add rule
    'while' '(' expr ')' stmt
;

retStmt: // ECE467 student: add rule
    'return' ';' | 'return' expr ';'
;

expr: // ECE467 student: add rule
    intExpr
    | '(' expr ')'
    | fcnName '(' args ')'
    | '!' expr
    | '-' expr
    | expr '<' expr
    | expr '<=' expr
    | expr '>' expr
    | expr '>=' expr
    | expr '==' expr
    | expr '!=' expr
    | expr '||' expr
    | expr '&&' expr
;

intExpr: // ECE467 student: add rule
    constant
    | var
    | intExpr '+' intExpr
    | intExpr '-' intExpr
    | intExpr '*' intExpr
    | intExpr '/' intExpr
    | '(' intExpr ')'
;

var: // ECE467 student: add rule
    varName | arrName '[' intExpr ']'
;

params: // ECE467 student: add rule
    paramList | /* epsilon */
;

paramEntry: // ECE467 student: add rule
    varType varName
    | varType arrName '[]'
;

paramList: // ECE467 student: add rule
    paramEntry
    | paramEntry ',' paramList
;

args: // ECE467 student: add rule
    argList | /* epsilon */
;

argEntry: // ECE467 student: add rule
    expr
;

argList: // ECE467 student: add rule
    argEntry | argEntry ',' argList
;

varName: // ECE467 student: add rule
    ID
;
arrName: // ECE467 student: add rule
    ID
;

fcnName: // ECE467 student: add rule
    ID
;

boolConst: // ECE467 student: add rule
    BOOL
;

intConst: // ECE467 student: add rule
    '-' INT | INT
;

// ECE467 student: complete these tokens definitions and use 
// them in the rules 
BOOL: (('true') | ('false')) ;
ID: [a-zA-Z][a-zA-Z0-9_]* ;
INT: [1-9][0-9]* | '0';
WS: [ \t\r\n] -> skip ;
COMMENT: '//' (~[\r\n])* -> skip;

