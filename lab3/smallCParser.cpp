
#include "ASTNodes.h"
#include <iostream>
#include <string>
#include <vector>


// Generated from smallC.g4 by ANTLR 4.7.2


#include "smallCVisitor.h"

#include "smallCParser.h"


using namespace antlrcpp;
using namespace antlr4;

smallCParser::smallCParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

smallCParser::~smallCParser() {
  delete _interpreter;
}

std::string smallCParser::getGrammarFileName() const {
  return "smallC.g4";
}

const std::vector<std::string>& smallCParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& smallCParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

smallCParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::ProgramContext::EOF() {
  return getToken(smallCParser::EOF, 0);
}

smallCParser::PreambleContext* smallCParser::ProgramContext::preamble() {
  return getRuleContext<smallCParser::PreambleContext>(0);
}

std::vector<smallCParser::DeclsContext *> smallCParser::ProgramContext::decls() {
  return getRuleContexts<smallCParser::DeclsContext>();
}

smallCParser::DeclsContext* smallCParser::ProgramContext::decls(size_t i) {
  return getRuleContext<smallCParser::DeclsContext>(i);
}


size_t smallCParser::ProgramContext::getRuleIndex() const {
  return smallCParser::RuleProgram;
}


antlrcpp::Any smallCParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ProgramContext* smallCParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, smallCParser::RuleProgram);

      dynamic_cast<ProgramContext *>(_localctx)->prg =  new smallc::ProgramNode();
      _localctx->prg->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
      //cout << _localctx->prg << "<<< prg node addr in g4 at init\n";

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__0: {
        setState(64);
        preamble();
        _localctx->prg->setIo(true);
        break;
      }

      case smallCParser::EOF:
      case smallCParser::T__7:
      case smallCParser::T__8:
      case smallCParser::T__9: {
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(75);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smallCParser::T__7)
      | (1ULL << smallCParser::T__8)
      | (1ULL << smallCParser::T__9))) != 0)) {
      setState(70);
      dynamic_cast<ProgramContext *>(_localctx)->declsContext = decls();

          for(unsigned int i = 0; i < dynamic_cast<ProgramContext *>(_localctx)->declsContext->declarations.size();i++){
              _localctx->prg->addChild(dynamic_cast<ProgramContext *>(_localctx)->declsContext->declarations[i]);
              dynamic_cast<ProgramContext *>(_localctx)->declsContext->declarations[i]->setRoot(_localctx->prg);
          }

      setState(77);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(78);
    match(smallCParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PreambleContext ------------------------------------------------------------------

smallCParser::PreambleContext::PreambleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t smallCParser::PreambleContext::getRuleIndex() const {
  return smallCParser::RulePreamble;
}


antlrcpp::Any smallCParser::PreambleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitPreamble(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::PreambleContext* smallCParser::preamble() {
  PreambleContext *_localctx = _tracker.createInstance<PreambleContext>(_ctx, getState());
  enterRule(_localctx, 2, smallCParser::RulePreamble);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(smallCParser::T__0);
    setState(81);
    match(smallCParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclsContext ------------------------------------------------------------------

smallCParser::DeclsContext::DeclsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ScalarDeclListContext* smallCParser::DeclsContext::scalarDeclList() {
  return getRuleContext<smallCParser::ScalarDeclListContext>(0);
}

smallCParser::ArrDeclListContext* smallCParser::DeclsContext::arrDeclList() {
  return getRuleContext<smallCParser::ArrDeclListContext>(0);
}

smallCParser::FcnProtoContext* smallCParser::DeclsContext::fcnProto() {
  return getRuleContext<smallCParser::FcnProtoContext>(0);
}

smallCParser::FcnDeclContext* smallCParser::DeclsContext::fcnDecl() {
  return getRuleContext<smallCParser::FcnDeclContext>(0);
}


size_t smallCParser::DeclsContext::getRuleIndex() const {
  return smallCParser::RuleDecls;
}


antlrcpp::Any smallCParser::DeclsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitDecls(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::DeclsContext* smallCParser::decls() {
  DeclsContext *_localctx = _tracker.createInstance<DeclsContext>(_ctx, getState());
  enterRule(_localctx, 4, smallCParser::RuleDecls);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(83);
      dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext = scalarDeclList();

              for(unsigned int i = 0; i < dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext->scalars.size(); i++){
                  _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->scalarDeclListContext->scalars[i]);
              }
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
      dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext = arrDeclList();

              for(unsigned int i = 0; i < dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext->arrays.size(); i++){
                  _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->arrDeclListContext->arrays[i]);
              }
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(89);
      dynamic_cast<DeclsContext *>(_localctx)->fcnProtoContext = fcnProto();

              _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->fcnProtoContext->fcnProtoNode);
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(92);
      dynamic_cast<DeclsContext *>(_localctx)->fcnDeclContext = fcnDecl();
         
              _localctx->declarations.push_back(dynamic_cast<DeclsContext *>(_localctx)->fcnDeclContext->fcnDeclNode);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarDeclListContext ------------------------------------------------------------------

smallCParser::ScalarDeclListContext::ScalarDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ScalarDeclContext* smallCParser::ScalarDeclListContext::scalarDecl() {
  return getRuleContext<smallCParser::ScalarDeclContext>(0);
}

smallCParser::ScalarDeclListContext* smallCParser::ScalarDeclListContext::scalarDeclList() {
  return getRuleContext<smallCParser::ScalarDeclListContext>(0);
}


size_t smallCParser::ScalarDeclListContext::getRuleIndex() const {
  return smallCParser::RuleScalarDeclList;
}


antlrcpp::Any smallCParser::ScalarDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScalarDeclList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScalarDeclListContext* smallCParser::scalarDeclList() {
  ScalarDeclListContext *_localctx = _tracker.createInstance<ScalarDeclListContext>(_ctx, getState());
  enterRule(_localctx, 6, smallCParser::RuleScalarDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(105);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(97);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext = scalarDecl();

              _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext->decl);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext = scalarDecl();

              _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclContext->decl);
          
      setState(102);
      dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext = scalarDeclList();

              for(unsigned int i = 0; i < dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext->scalars.size(); i++){
                  _localctx->scalars.push_back(dynamic_cast<ScalarDeclListContext *>(_localctx)->scalarDeclListContext->scalars[i]);
              }
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarDeclContext ------------------------------------------------------------------

smallCParser::ScalarDeclContext::ScalarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ScalarDeclContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::VarNameContext* smallCParser::ScalarDeclContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}


size_t smallCParser::ScalarDeclContext::getRuleIndex() const {
  return smallCParser::RuleScalarDecl;
}


antlrcpp::Any smallCParser::ScalarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScalarDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScalarDeclContext* smallCParser::scalarDecl() {
  ScalarDeclContext *_localctx = _tracker.createInstance<ScalarDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, smallCParser::RuleScalarDecl);
  dynamic_cast<ScalarDeclContext *>(_localctx)->decl =  new smallc::ScalarDeclNode();
         _localctx->decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    dynamic_cast<ScalarDeclContext *>(_localctx)->varTypeContext = varType();

            _localctx->decl->setType(dynamic_cast<ScalarDeclContext *>(_localctx)->varTypeContext->typeNode);
        
    setState(109);
    dynamic_cast<ScalarDeclContext *>(_localctx)->varNameContext = varName();

            _localctx->decl->setName(dynamic_cast<ScalarDeclContext *>(_localctx)->varNameContext->nameNode);
        
    setState(111);
    match(smallCParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrDeclListContext ------------------------------------------------------------------

smallCParser::ArrDeclListContext::ArrDeclListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArrDeclContext* smallCParser::ArrDeclListContext::arrDecl() {
  return getRuleContext<smallCParser::ArrDeclContext>(0);
}

smallCParser::ArrDeclListContext* smallCParser::ArrDeclListContext::arrDeclList() {
  return getRuleContext<smallCParser::ArrDeclListContext>(0);
}


size_t smallCParser::ArrDeclListContext::getRuleIndex() const {
  return smallCParser::RuleArrDeclList;
}


antlrcpp::Any smallCParser::ArrDeclListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrDeclList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrDeclListContext* smallCParser::arrDeclList() {
  ArrDeclListContext *_localctx = _tracker.createInstance<ArrDeclListContext>(_ctx, getState());
  enterRule(_localctx, 10, smallCParser::RuleArrDeclList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(113);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext = arrDecl();

              _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext->decl);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(116);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext = arrDecl();

              _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclContext->decl);
          
      setState(118);
      dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext = arrDeclList();

              for(unsigned int i = 0; i < dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext->arrays.size(); i++){
                  _localctx->arrays.push_back(dynamic_cast<ArrDeclListContext *>(_localctx)->arrDeclListContext->arrays[i]);
              }
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrDeclContext ------------------------------------------------------------------

smallCParser::ArrDeclContext::ArrDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ArrDeclContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::ArrNameContext* smallCParser::ArrDeclContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}

smallCParser::IntConstContext* smallCParser::ArrDeclContext::intConst() {
  return getRuleContext<smallCParser::IntConstContext>(0);
}


size_t smallCParser::ArrDeclContext::getRuleIndex() const {
  return smallCParser::RuleArrDecl;
}


antlrcpp::Any smallCParser::ArrDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrDeclContext* smallCParser::arrDecl() {
  ArrDeclContext *_localctx = _tracker.createInstance<ArrDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, smallCParser::RuleArrDecl);
  dynamic_cast<ArrDeclContext *>(_localctx)->decl =  new smallc::ArrayDeclNode();
         _localctx->decl->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    dynamic_cast<ArrDeclContext *>(_localctx)->varTypeContext = varType();
    setState(124);
    dynamic_cast<ArrDeclContext *>(_localctx)->arrNameContext = arrName();
    setState(125);
    match(smallCParser::T__3);
    setState(126);
    dynamic_cast<ArrDeclContext *>(_localctx)->intConstContext = intConst();
    setState(127);
    match(smallCParser::T__4);
    setState(128);
    match(smallCParser::T__2);

            dynamic_cast<ArrDeclContext *>(_localctx)->arrTypeNode =  new smallc::ArrayTypeNode(dynamic_cast<ArrDeclContext *>(_localctx)->varTypeContext->typeNode);
            _localctx->arrTypeNode->setLine(dynamic_cast<ArrDeclContext *>(_localctx)->varTypeContext->typeNode->getLine());
            _localctx->arrTypeNode->setColumn(dynamic_cast<ArrDeclContext *>(_localctx)->varTypeContext->typeNode->getCol());
            _localctx->decl->setName(dynamic_cast<ArrDeclContext *>(_localctx)->arrNameContext->nameNode);
            _localctx->arrTypeNode->setSize(std::stoi((dynamic_cast<ArrDeclContext *>(_localctx)->intConstContext != nullptr ? _input->getText(dynamic_cast<ArrDeclContext *>(_localctx)->intConstContext->start, dynamic_cast<ArrDeclContext *>(_localctx)->intConstContext->stop) : nullptr)));
            _localctx->decl->setType(_localctx->arrTypeNode);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnProtoContext ------------------------------------------------------------------

smallCParser::FcnProtoContext::FcnProtoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::RetTypeContext* smallCParser::FcnProtoContext::retType() {
  return getRuleContext<smallCParser::RetTypeContext>(0);
}

smallCParser::FcnNameContext* smallCParser::FcnProtoContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ParamsContext* smallCParser::FcnProtoContext::params() {
  return getRuleContext<smallCParser::ParamsContext>(0);
}


size_t smallCParser::FcnProtoContext::getRuleIndex() const {
  return smallCParser::RuleFcnProto;
}


antlrcpp::Any smallCParser::FcnProtoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnProto(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnProtoContext* smallCParser::fcnProto() {
  FcnProtoContext *_localctx = _tracker.createInstance<FcnProtoContext>(_ctx, getState());
  enterRule(_localctx, 14, smallCParser::RuleFcnProto);

          dynamic_cast<FcnProtoContext *>(_localctx)->fcnProtoNode =  new smallc::FunctionDeclNode();
          _localctx->fcnProtoNode->setProto(true);
          _localctx->fcnProtoNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    dynamic_cast<FcnProtoContext *>(_localctx)->retTypeContext = retType();

            _localctx->fcnProtoNode->setRetType(dynamic_cast<FcnProtoContext *>(_localctx)->retTypeContext->typeNode);
        
    setState(133);
    dynamic_cast<FcnProtoContext *>(_localctx)->fcnNameContext = fcnName();

            _localctx->fcnProtoNode->setName(dynamic_cast<FcnProtoContext *>(_localctx)->fcnNameContext->nameNode);
        
    setState(135);
    match(smallCParser::T__5);
    setState(136);
    dynamic_cast<FcnProtoContext *>(_localctx)->paramsContext = params();

            _localctx->fcnProtoNode->setParameter(dynamic_cast<FcnProtoContext *>(_localctx)->paramsContext->parameterList);
        
    setState(138);
    match(smallCParser::T__6);
    setState(139);
    match(smallCParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnDeclContext ------------------------------------------------------------------

smallCParser::FcnDeclContext::FcnDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::RetTypeContext* smallCParser::FcnDeclContext::retType() {
  return getRuleContext<smallCParser::RetTypeContext>(0);
}

smallCParser::FcnNameContext* smallCParser::FcnDeclContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ParamsContext* smallCParser::FcnDeclContext::params() {
  return getRuleContext<smallCParser::ParamsContext>(0);
}

smallCParser::ScopeContext* smallCParser::FcnDeclContext::scope() {
  return getRuleContext<smallCParser::ScopeContext>(0);
}


size_t smallCParser::FcnDeclContext::getRuleIndex() const {
  return smallCParser::RuleFcnDecl;
}


antlrcpp::Any smallCParser::FcnDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnDecl(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnDeclContext* smallCParser::fcnDecl() {
  FcnDeclContext *_localctx = _tracker.createInstance<FcnDeclContext>(_ctx, getState());
  enterRule(_localctx, 16, smallCParser::RuleFcnDecl);

          dynamic_cast<FcnDeclContext *>(_localctx)->fcnDeclNode =  new smallc::FunctionDeclNode();
          _localctx->fcnDeclNode->setProto(false);
          _localctx->fcnDeclNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    dynamic_cast<FcnDeclContext *>(_localctx)->retTypeContext = retType();

            _localctx->fcnDeclNode->setRetType(dynamic_cast<FcnDeclContext *>(_localctx)->retTypeContext->typeNode);
        
    setState(143);
    dynamic_cast<FcnDeclContext *>(_localctx)->fcnNameContext = fcnName();

            _localctx->fcnDeclNode->setName(dynamic_cast<FcnDeclContext *>(_localctx)->fcnNameContext->nameNode);
        
    setState(145);
    match(smallCParser::T__5);
    setState(146);
    dynamic_cast<FcnDeclContext *>(_localctx)->paramsContext = params();

            _localctx->fcnDeclNode->setParameter(dynamic_cast<FcnDeclContext *>(_localctx)->paramsContext->parameterList);
        
    setState(148);
    match(smallCParser::T__6);
    setState(149);
    dynamic_cast<FcnDeclContext *>(_localctx)->scopeContext = scope();

            _localctx->fcnDeclNode->setBody(dynamic_cast<FcnDeclContext *>(_localctx)->scopeContext->scope_);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext ------------------------------------------------------------------

smallCParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t smallCParser::VarTypeContext::getRuleIndex() const {
  return smallCParser::RuleVarType;
}


antlrcpp::Any smallCParser::VarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarTypeContext* smallCParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 18, smallCParser::RuleVarType);
  dynamic_cast<VarTypeContext *>(_localctx)->typeNode =  new smallc::PrimitiveTypeNode();
         _localctx->typeNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        match(smallCParser::T__7);

                _localctx->typeNode->setType(smallc::TypeNode::TypeEnum::Bool);
            
        break;
      }

      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(154);
        match(smallCParser::T__8);

                _localctx->typeNode->setType(smallc::TypeNode::TypeEnum::Int);
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetTypeContext ------------------------------------------------------------------

smallCParser::RetTypeContext::RetTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::RetTypeContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}


size_t smallCParser::RetTypeContext::getRuleIndex() const {
  return smallCParser::RuleRetType;
}


antlrcpp::Any smallCParser::RetTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitRetType(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::RetTypeContext* smallCParser::retType() {
  RetTypeContext *_localctx = _tracker.createInstance<RetTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, smallCParser::RuleRetType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(163);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(158);
        match(smallCParser::T__9);

                dynamic_cast<RetTypeContext *>(_localctx)->typeNode =  new smallc::PrimitiveTypeNode();
                _localctx->typeNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                _localctx->typeNode->setType(smallc::TypeNode::TypeEnum::Void);
            
        break;
      }

      case smallCParser::T__7:
      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(160);
        dynamic_cast<RetTypeContext *>(_localctx)->varTypeContext = varType();

                dynamic_cast<RetTypeContext *>(_localctx)->typeNode =  dynamic_cast<RetTypeContext *>(_localctx)->varTypeContext->typeNode;
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

smallCParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::BoolConstContext* smallCParser::ConstantContext::boolConst() {
  return getRuleContext<smallCParser::BoolConstContext>(0);
}

smallCParser::IntConstContext* smallCParser::ConstantContext::intConst() {
  return getRuleContext<smallCParser::IntConstContext>(0);
}


size_t smallCParser::ConstantContext::getRuleIndex() const {
  return smallCParser::RuleConstant;
}


antlrcpp::Any smallCParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ConstantContext* smallCParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 22, smallCParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::BOOL: {
        enterOuterAlt(_localctx, 1);
        setState(165);
        dynamic_cast<ConstantContext *>(_localctx)->boolConstContext = boolConst();

                dynamic_cast<ConstantContext *>(_localctx)->contExprNode =  new smallc::BoolConstantNode((dynamic_cast<ConstantContext *>(_localctx)->boolConstContext != nullptr ? _input->getText(dynamic_cast<ConstantContext *>(_localctx)->boolConstContext->start, dynamic_cast<ConstantContext *>(_localctx)->boolConstContext->stop) : nullptr));
                _localctx->contExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                _localctx->contExprNode->setTypeBool();
            
        break;
      }

      case smallCParser::T__18:
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(168);
        dynamic_cast<ConstantContext *>(_localctx)->intConstContext = intConst();

                dynamic_cast<ConstantContext *>(_localctx)->contExprNode =  new smallc::IntConstantNode((dynamic_cast<ConstantContext *>(_localctx)->intConstContext != nullptr ? _input->getText(dynamic_cast<ConstantContext *>(_localctx)->intConstContext->start, dynamic_cast<ConstantContext *>(_localctx)->intConstContext->stop) : nullptr));
                _localctx->contExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                _localctx->contExprNode->setTypeInt();
            
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolConstContext ------------------------------------------------------------------

smallCParser::BoolConstContext::BoolConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::BoolConstContext::BOOL() {
  return getToken(smallCParser::BOOL, 0);
}


size_t smallCParser::BoolConstContext::getRuleIndex() const {
  return smallCParser::RuleBoolConst;
}


antlrcpp::Any smallCParser::BoolConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitBoolConst(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::BoolConstContext* smallCParser::boolConst() {
  BoolConstContext *_localctx = _tracker.createInstance<BoolConstContext>(_ctx, getState());
  enterRule(_localctx, 24, smallCParser::RuleBoolConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    match(smallCParser::BOOL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScopeContext ------------------------------------------------------------------

smallCParser::ScopeContext::ScopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<smallCParser::ScalarDeclContext *> smallCParser::ScopeContext::scalarDecl() {
  return getRuleContexts<smallCParser::ScalarDeclContext>();
}

smallCParser::ScalarDeclContext* smallCParser::ScopeContext::scalarDecl(size_t i) {
  return getRuleContext<smallCParser::ScalarDeclContext>(i);
}

std::vector<smallCParser::ArrDeclContext *> smallCParser::ScopeContext::arrDecl() {
  return getRuleContexts<smallCParser::ArrDeclContext>();
}

smallCParser::ArrDeclContext* smallCParser::ScopeContext::arrDecl(size_t i) {
  return getRuleContext<smallCParser::ArrDeclContext>(i);
}

std::vector<smallCParser::StmtContext *> smallCParser::ScopeContext::stmt() {
  return getRuleContexts<smallCParser::StmtContext>();
}

smallCParser::StmtContext* smallCParser::ScopeContext::stmt(size_t i) {
  return getRuleContext<smallCParser::StmtContext>(i);
}


size_t smallCParser::ScopeContext::getRuleIndex() const {
  return smallCParser::RuleScope;
}


antlrcpp::Any smallCParser::ScopeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitScope(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ScopeContext* smallCParser::scope() {
  ScopeContext *_localctx = _tracker.createInstance<ScopeContext>(_ctx, getState());
  enterRule(_localctx, 26, smallCParser::RuleScope);

      dynamic_cast<ScopeContext *>(_localctx)->scope_ =  new smallc::ScopeNode();
      _localctx->scope_->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(smallCParser::T__10);
    setState(184);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == smallCParser::T__7

    || _la == smallCParser::T__8) {
      setState(182);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(176);
        dynamic_cast<ScopeContext *>(_localctx)->scalarDeclContext = scalarDecl();

                dynamic_cast<ScopeContext *>(_localctx)->scalarDeclContext->decl->setParent(_localctx->scope_); 
                _localctx->scope_->addDeclaration(dynamic_cast<ScopeContext *>(_localctx)->scalarDeclContext->decl);
            
        break;
      }

      case 2: {
        setState(179);
        dynamic_cast<ScopeContext *>(_localctx)->arrDeclContext = arrDecl();

                dynamic_cast<ScopeContext *>(_localctx)->arrDeclContext->decl->setParent(_localctx->scope_); 
                _localctx->scope_->addDeclaration(dynamic_cast<ScopeContext *>(_localctx)->arrDeclContext->decl);
            
        break;
      }

      }
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(192);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << smallCParser::T__5)
      | (1ULL << smallCParser::T__10)
      | (1ULL << smallCParser::T__13)
      | (1ULL << smallCParser::T__15)
      | (1ULL << smallCParser::T__16)
      | (1ULL << smallCParser::T__17)
      | (1ULL << smallCParser::T__18)
      | (1ULL << smallCParser::BOOL)
      | (1ULL << smallCParser::ID)
      | (1ULL << smallCParser::INT))) != 0)) {
      setState(187);
      dynamic_cast<ScopeContext *>(_localctx)->stmtContext = stmt();

              // dynamic_cast<ScopeContext *>(_localctx)->stmtContext->statement->setParent(_localctx->scope_); 
              _localctx->scope_->addChild(dynamic_cast<ScopeContext *>(_localctx)->stmtContext->statement);
          
      setState(194);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(195);
    match(smallCParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

smallCParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::StmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

smallCParser::AssignStmtContext* smallCParser::StmtContext::assignStmt() {
  return getRuleContext<smallCParser::AssignStmtContext>(0);
}

smallCParser::IfStmtContext* smallCParser::StmtContext::ifStmt() {
  return getRuleContext<smallCParser::IfStmtContext>(0);
}

smallCParser::WhileStmtContext* smallCParser::StmtContext::whileStmt() {
  return getRuleContext<smallCParser::WhileStmtContext>(0);
}

smallCParser::RetStmtContext* smallCParser::StmtContext::retStmt() {
  return getRuleContext<smallCParser::RetStmtContext>(0);
}

smallCParser::ScopeContext* smallCParser::StmtContext::scope() {
  return getRuleContext<smallCParser::ScopeContext>(0);
}


size_t smallCParser::StmtContext::getRuleIndex() const {
  return smallCParser::RuleStmt;
}


antlrcpp::Any smallCParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::StmtContext* smallCParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 28, smallCParser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(216);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(197);
      dynamic_cast<StmtContext *>(_localctx)->exprContext = expr(0);

              dynamic_cast<StmtContext *>(_localctx)->exprStmt =  new smallc::ExprStmtNode(dynamic_cast<StmtContext *>(_localctx)->exprContext->exprStmtNode);
              dynamic_cast<StmtContext *>(_localctx)->statement =  _localctx->exprStmt;
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      setState(199);
      match(smallCParser::T__2);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(201);
      dynamic_cast<StmtContext *>(_localctx)->assignStmtContext = assignStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->assignStmtContext->assignStmtNode;
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(204);
      dynamic_cast<StmtContext *>(_localctx)->ifStmtContext = ifStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->ifStmtContext->ifStmtNode;
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(207);
      dynamic_cast<StmtContext *>(_localctx)->whileStmtContext = whileStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->whileStmtContext->whileStmtNode;
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(210);
      dynamic_cast<StmtContext *>(_localctx)->retStmtContext = retStmt();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->retStmtContext->retStmtNode;
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(213);
      dynamic_cast<StmtContext *>(_localctx)->scopeContext = scope();

              dynamic_cast<StmtContext *>(_localctx)->statement =  dynamic_cast<StmtContext *>(_localctx)->scopeContext->scope_;
              _localctx->statement->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignStmtContext ------------------------------------------------------------------

smallCParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarContext* smallCParser::AssignStmtContext::var() {
  return getRuleContext<smallCParser::VarContext>(0);
}

smallCParser::ExprContext* smallCParser::AssignStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::AssignStmtContext::getRuleIndex() const {
  return smallCParser::RuleAssignStmt;
}


antlrcpp::Any smallCParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::AssignStmtContext* smallCParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 30, smallCParser::RuleAssignStmt);
  dynamic_cast<AssignStmtContext *>(_localctx)->assignStmtNode =  new smallc::AssignStmtNode();

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    dynamic_cast<AssignStmtContext *>(_localctx)->varContext = var();

            _localctx->assignStmtNode->setTarget(dynamic_cast<AssignStmtContext *>(_localctx)->varContext->target_);
        
    setState(220);
    match(smallCParser::T__12);
    setState(221);
    dynamic_cast<AssignStmtContext *>(_localctx)->exprContext = expr(0);

            _localctx->assignStmtNode->setValue(dynamic_cast<AssignStmtContext *>(_localctx)->exprContext->exprStmtNode);
        
    setState(223);
    match(smallCParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

smallCParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::IfStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

std::vector<smallCParser::StmtContext *> smallCParser::IfStmtContext::stmt() {
  return getRuleContexts<smallCParser::StmtContext>();
}

smallCParser::StmtContext* smallCParser::IfStmtContext::stmt(size_t i) {
  return getRuleContext<smallCParser::StmtContext>(i);
}


size_t smallCParser::IfStmtContext::getRuleIndex() const {
  return smallCParser::RuleIfStmt;
}


antlrcpp::Any smallCParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::IfStmtContext* smallCParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 32, smallCParser::RuleIfStmt);
  dynamic_cast<IfStmtContext *>(_localctx)->ifStmtNode =  new smallc::IfStmtNode();

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(241);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(225);
      match(smallCParser::T__13);
      setState(226);
      match(smallCParser::T__5);
      setState(227);
      dynamic_cast<IfStmtContext *>(_localctx)->exprContext = expr(0);
      setState(228);
      match(smallCParser::T__6);
      setState(229);
      dynamic_cast<IfStmtContext *>(_localctx)->stmtContext = stmt();

              _localctx->ifStmtNode->setCondition(dynamic_cast<IfStmtContext *>(_localctx)->exprContext->exprStmtNode);
              _localctx->ifStmtNode->setThen(dynamic_cast<IfStmtContext *>(_localctx)->stmtContext->statement);
              _localctx->ifStmtNode->setHasElse(false);
              dynamic_cast<IfStmtContext *>(_localctx)->exprContext->exprStmtNode->setParent(_localctx->ifStmtNode);
              dynamic_cast<IfStmtContext *>(_localctx)->stmtContext->statement->setParent(_localctx->ifStmtNode);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
      match(smallCParser::T__13);
      setState(233);
      match(smallCParser::T__5);
      setState(234);
      dynamic_cast<IfStmtContext *>(_localctx)->exprContext = expr(0);
      setState(235);
      match(smallCParser::T__6);
      setState(236);
      dynamic_cast<IfStmtContext *>(_localctx)->then = stmt();
      setState(237);
      match(smallCParser::T__14);
      setState(238);
      dynamic_cast<IfStmtContext *>(_localctx)->e = stmt();

              _localctx->ifStmtNode->setCondition(dynamic_cast<IfStmtContext *>(_localctx)->exprContext->exprStmtNode);
              _localctx->ifStmtNode->setThen(dynamic_cast<IfStmtContext *>(_localctx)->then->statement);
              _localctx->ifStmtNode->setHasElse(true);
              _localctx->ifStmtNode->setElse(dynamic_cast<IfStmtContext *>(_localctx)->e->statement);
              dynamic_cast<IfStmtContext *>(_localctx)->exprContext->exprStmtNode->setParent(_localctx->ifStmtNode);
              dynamic_cast<IfStmtContext *>(_localctx)->then->statement->setParent(_localctx->ifStmtNode);
              dynamic_cast<IfStmtContext *>(_localctx)->e->statement->setParent(_localctx->ifStmtNode);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

smallCParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::WhileStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}

smallCParser::StmtContext* smallCParser::WhileStmtContext::stmt() {
  return getRuleContext<smallCParser::StmtContext>(0);
}


size_t smallCParser::WhileStmtContext::getRuleIndex() const {
  return smallCParser::RuleWhileStmt;
}


antlrcpp::Any smallCParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::WhileStmtContext* smallCParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, smallCParser::RuleWhileStmt);
  dynamic_cast<WhileStmtContext *>(_localctx)->whileStmtNode =  new smallc::WhileStmtNode();

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    match(smallCParser::T__15);
    setState(244);
    match(smallCParser::T__5);
    setState(245);
    dynamic_cast<WhileStmtContext *>(_localctx)->exprContext = expr(0);
    setState(246);
    match(smallCParser::T__6);
    setState(247);
    dynamic_cast<WhileStmtContext *>(_localctx)->stmtContext = stmt();

            _localctx->whileStmtNode->setCondition(dynamic_cast<WhileStmtContext *>(_localctx)->exprContext->exprStmtNode);
            _localctx->whileStmtNode->setBody(dynamic_cast<WhileStmtContext *>(_localctx)->stmtContext->statement);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetStmtContext ------------------------------------------------------------------

smallCParser::RetStmtContext::RetStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::RetStmtContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::RetStmtContext::getRuleIndex() const {
  return smallCParser::RuleRetStmt;
}


antlrcpp::Any smallCParser::RetStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitRetStmt(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::RetStmtContext* smallCParser::retStmt() {
  RetStmtContext *_localctx = _tracker.createInstance<RetStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, smallCParser::RuleRetStmt);
  dynamic_cast<RetStmtContext *>(_localctx)->retStmtNode =  new smallc::ReturnStmtNode();

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(258);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(250);
      match(smallCParser::T__16);
      setState(251);
      dynamic_cast<RetStmtContext *>(_localctx)->exprContext = expr(0);
      setState(252);
      match(smallCParser::T__2);

              _localctx->retStmtNode->setReturn(dynamic_cast<RetStmtContext *>(_localctx)->exprContext->exprStmtNode);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(255);
      match(smallCParser::T__16);
      setState(256);
      match(smallCParser::T__2);

              //_localctx->retStmtNode->setReturn(nullptr);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

smallCParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::IntExprContext* smallCParser::ExprContext::intExpr() {
  return getRuleContext<smallCParser::IntExprContext>(0);
}

std::vector<smallCParser::ExprContext *> smallCParser::ExprContext::expr() {
  return getRuleContexts<smallCParser::ExprContext>();
}

smallCParser::ExprContext* smallCParser::ExprContext::expr(size_t i) {
  return getRuleContext<smallCParser::ExprContext>(i);
}

smallCParser::FcnNameContext* smallCParser::ExprContext::fcnName() {
  return getRuleContext<smallCParser::FcnNameContext>(0);
}

smallCParser::ArgsContext* smallCParser::ExprContext::args() {
  return getRuleContext<smallCParser::ArgsContext>(0);
}


size_t smallCParser::ExprContext::getRuleIndex() const {
  return smallCParser::RuleExpr;
}


antlrcpp::Any smallCParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


smallCParser::ExprContext* smallCParser::expr() {
   return expr(0);
}

smallCParser::ExprContext* smallCParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  smallCParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  smallCParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, smallCParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(279);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(261);
      dynamic_cast<ExprContext *>(_localctx)->intExprContext = intExpr(0);

              dynamic_cast<ExprContext *>(_localctx)->exprStmtNode =  dynamic_cast<ExprContext *>(_localctx)->intExprContext->intExprNode;
              // _localctx->exprStmtNode->setTypeInt();
          
      break;
    }

    case 2: {
      setState(264);
      match(smallCParser::T__5);
      setState(265);
      dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(0);

              dynamic_cast<ExprContext *>(_localctx)->exprStmtNode =  dynamic_cast<ExprContext *>(_localctx)->exprContext->exprStmtNode;
          
      setState(267);
      match(smallCParser::T__6);
      break;
    }

    case 3: {
      setState(269);
      dynamic_cast<ExprContext *>(_localctx)->fcnNameContext = fcnName();
      setState(270);
      match(smallCParser::T__5);
      setState(271);
      dynamic_cast<ExprContext *>(_localctx)->argsContext = args();
      setState(272);
      match(smallCParser::T__6);

              dynamic_cast<ExprContext *>(_localctx)->funcCallNode =  new smallc::CallExprNode();
              _localctx->funcCallNode->setIdent(dynamic_cast<ExprContext *>(_localctx)->fcnNameContext->nameNode);
              _localctx->funcCallNode->setArguments(dynamic_cast<ExprContext *>(_localctx)->argsContext->argsList);
              dynamic_cast<ExprContext *>(_localctx)->exprStmtNode =  _localctx->funcCallNode;
              _localctx->exprStmtNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              _localctx->exprStmtNode->setTypeVoid();
          
      break;
    }

    case 4: {
      setState(275);
      dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == smallCParser::T__17

      || _la == smallCParser::T__18)) {
        dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(276);
      dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(5);

              dynamic_cast<ExprContext *>(_localctx)->unaryExprNode =  new smallc::UnaryExprNode(dynamic_cast<ExprContext *>(_localctx)->exprContext->exprStmtNode);
              _localctx->unaryExprNode->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
              dynamic_cast<ExprContext *>(_localctx)->exprStmtNode =  _localctx->unaryExprNode;
              if ((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : "") == "!") _localctx->exprStmtNode->setTypeBool();
              if ((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : "") == "-") _localctx->exprStmtNode->setTypeInt();
              _localctx->exprStmtNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
              
          
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(303);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(301);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(281);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(282);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << smallCParser::T__19)
            | (1ULL << smallCParser::T__20)
            | (1ULL << smallCParser::T__21)
            | (1ULL << smallCParser::T__22))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(283);
          dynamic_cast<ExprContext *>(_localctx)->r = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(5);

                            dynamic_cast<ExprContext *>(_localctx)->binaryExprNode =  new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->exprStmtNode, dynamic_cast<ExprContext *>(_localctx)->r->exprStmtNode);
                            _localctx->binaryExprNode->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->binaryExprNode->setTypeBool();
                            dynamic_cast<ExprContext *>(_localctx)->boolexpr =  new smallc::BoolExprNode(_localctx->binaryExprNode);
                            _localctx->binaryExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->exprStmtNode =  _localctx->boolexpr;
                            _localctx->exprStmtNode->setTypeBool();
                            _localctx->exprStmtNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(286);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(287);
          dynamic_cast<ExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__23

          || _la == smallCParser::T__24)) {
            dynamic_cast<ExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(288);
          dynamic_cast<ExprContext *>(_localctx)->r = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(4);

                            dynamic_cast<ExprContext *>(_localctx)->binaryExprNode =  new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->exprStmtNode, dynamic_cast<ExprContext *>(_localctx)->r->exprStmtNode);
                            _localctx->binaryExprNode->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->binaryExprNode->setTypeBool();
                            dynamic_cast<ExprContext *>(_localctx)->boolexpr =  new smallc::BoolExprNode(_localctx->binaryExprNode);
                            _localctx->binaryExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->exprStmtNode =  _localctx->boolexpr;
                            _localctx->exprStmtNode->setTypeBool();
                            _localctx->exprStmtNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                        
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(291);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(292);
          dynamic_cast<ExprContext *>(_localctx)->op = match(smallCParser::T__25);
          setState(293);
          dynamic_cast<ExprContext *>(_localctx)->r = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(3);

                            dynamic_cast<ExprContext *>(_localctx)->binaryExprNode =  new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->exprStmtNode, dynamic_cast<ExprContext *>(_localctx)->r->exprStmtNode);
                            _localctx->binaryExprNode->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->binaryExprNode->setTypeBool();
                            dynamic_cast<ExprContext *>(_localctx)->boolexpr =  new smallc::BoolExprNode(_localctx->binaryExprNode);
                            _localctx->binaryExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->exprStmtNode =  _localctx->boolexpr;
                            _localctx->exprStmtNode->setTypeBool();
                            _localctx->exprStmtNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                        
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(296);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(297);
          dynamic_cast<ExprContext *>(_localctx)->op = match(smallCParser::T__26);
          setState(298);
          dynamic_cast<ExprContext *>(_localctx)->r = dynamic_cast<ExprContext *>(_localctx)->exprContext = expr(2);

                            dynamic_cast<ExprContext *>(_localctx)->binaryExprNode =  new smallc::BinaryExprNode(dynamic_cast<ExprContext *>(_localctx)->l->exprStmtNode, dynamic_cast<ExprContext *>(_localctx)->r->exprStmtNode);
                            _localctx->binaryExprNode->setOpcode((dynamic_cast<ExprContext *>(_localctx)->op != nullptr ? dynamic_cast<ExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->binaryExprNode->setTypeBool();
                            dynamic_cast<ExprContext *>(_localctx)->boolexpr =  new smallc::BoolExprNode(_localctx->binaryExprNode);
                            _localctx->binaryExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            dynamic_cast<ExprContext *>(_localctx)->exprStmtNode =  _localctx->boolexpr;
                            _localctx->exprStmtNode->setTypeBool();
                            _localctx->exprStmtNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                        
          break;
        }

        } 
      }
      setState(305);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IntExprContext ------------------------------------------------------------------

smallCParser::IntExprContext::IntExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarContext* smallCParser::IntExprContext::var() {
  return getRuleContext<smallCParser::VarContext>(0);
}

smallCParser::ConstantContext* smallCParser::IntExprContext::constant() {
  return getRuleContext<smallCParser::ConstantContext>(0);
}

std::vector<smallCParser::IntExprContext *> smallCParser::IntExprContext::intExpr() {
  return getRuleContexts<smallCParser::IntExprContext>();
}

smallCParser::IntExprContext* smallCParser::IntExprContext::intExpr(size_t i) {
  return getRuleContext<smallCParser::IntExprContext>(i);
}


size_t smallCParser::IntExprContext::getRuleIndex() const {
  return smallCParser::RuleIntExpr;
}


antlrcpp::Any smallCParser::IntExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIntExpr(this);
  else
    return visitor->visitChildren(this);
}


smallCParser::IntExprContext* smallCParser::intExpr() {
   return intExpr(0);
}

smallCParser::IntExprContext* smallCParser::intExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  smallCParser::IntExprContext *_localctx = _tracker.createInstance<IntExprContext>(_ctx, parentState);
  smallCParser::IntExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, smallCParser::RuleIntExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(318);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::ID: {
        setState(307);
        dynamic_cast<IntExprContext *>(_localctx)->varContext = var();

                dynamic_cast<IntExprContext *>(_localctx)->intExprNode =  new smallc::IntExprNode(dynamic_cast<IntExprContext *>(_localctx)->varContext->target_);
                _localctx->intExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                _localctx->intExprNode->setTypeVoid();
            
        break;
      }

      case smallCParser::T__18:
      case smallCParser::BOOL:
      case smallCParser::INT: {
        setState(310);
        dynamic_cast<IntExprContext *>(_localctx)->constantContext = constant();

                dynamic_cast<IntExprContext *>(_localctx)->intExprNode =  new smallc::IntExprNode(dynamic_cast<IntExprContext *>(_localctx)->constantContext->contExprNode);
                _localctx->intExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                _localctx->intExprNode->setType(dynamic_cast<IntExprContext *>(_localctx)->constantContext->contExprNode->getType());
            
        break;
      }

      case smallCParser::T__5: {
        setState(313);
        match(smallCParser::T__5);
        setState(314);
        dynamic_cast<IntExprContext *>(_localctx)->intExprContext = intExpr(0);

                dynamic_cast<IntExprContext *>(_localctx)->intExprNode =  dynamic_cast<IntExprContext *>(_localctx)->intExprContext->intExprNode;
            
        setState(316);
        match(smallCParser::T__6);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(332);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(330);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(320);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(321);
          dynamic_cast<IntExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__27

          || _la == smallCParser::T__28)) {
            dynamic_cast<IntExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(322);
          dynamic_cast<IntExprContext *>(_localctx)->r = dynamic_cast<IntExprContext *>(_localctx)->intExprContext = intExpr(4);

                            dynamic_cast<IntExprContext *>(_localctx)->binaryExprNode =  new smallc::BinaryExprNode(dynamic_cast<IntExprContext *>(_localctx)->l->intExprNode, dynamic_cast<IntExprContext *>(_localctx)->r->intExprNode);
                            _localctx->binaryExprNode->setOpcode((dynamic_cast<IntExprContext *>(_localctx)->op != nullptr ? dynamic_cast<IntExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->binaryExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            _localctx->binaryExprNode->setTypeInt();
                            dynamic_cast<IntExprContext *>(_localctx)->intExprNode =  new smallc::IntExprNode(_localctx->binaryExprNode);
                            _localctx->intExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            _localctx->intExprNode->setTypeInt();
                        
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<IntExprContext>(parentContext, parentState);
          _localctx->l = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleIntExpr);
          setState(325);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(326);
          dynamic_cast<IntExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == smallCParser::T__18

          || _la == smallCParser::T__29)) {
            dynamic_cast<IntExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(327);
          dynamic_cast<IntExprContext *>(_localctx)->r = dynamic_cast<IntExprContext *>(_localctx)->intExprContext = intExpr(3);

                            dynamic_cast<IntExprContext *>(_localctx)->binaryExprNode =  new smallc::BinaryExprNode(dynamic_cast<IntExprContext *>(_localctx)->l->intExprNode, dynamic_cast<IntExprContext *>(_localctx)->r->intExprNode);
                            _localctx->binaryExprNode->setOpcode((dynamic_cast<IntExprContext *>(_localctx)->op != nullptr ? dynamic_cast<IntExprContext *>(_localctx)->op->getText() : ""));
                            _localctx->binaryExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            _localctx->binaryExprNode->setTypeInt();
                            dynamic_cast<IntExprContext *>(_localctx)->intExprNode =  new smallc::IntExprNode(_localctx->binaryExprNode);
                            _localctx->intExprNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
                            _localctx->intExprNode->setTypeInt();
                        
          break;
        }

        } 
      }
      setState(334);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

smallCParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarNameContext* smallCParser::VarContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}

smallCParser::ArrNameContext* smallCParser::VarContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}

smallCParser::IntExprContext* smallCParser::VarContext::intExpr() {
  return getRuleContext<smallCParser::IntExprContext>(0);
}


size_t smallCParser::VarContext::getRuleIndex() const {
  return smallCParser::RuleVar;
}


antlrcpp::Any smallCParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarContext* smallCParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 42, smallCParser::RuleVar);
  dynamic_cast<VarContext *>(_localctx)->target_ =  new smallc::ReferenceExprNode();
         _localctx->target_->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());
         _localctx->target_->setTypeVoid();

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(345);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(335);
      dynamic_cast<VarContext *>(_localctx)->varNameContext = varName();

              _localctx->target_->setIdent(dynamic_cast<VarContext *>(_localctx)->varNameContext->nameNode);
              // _localctx->target_->setIndex(nullptr);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(338);
      dynamic_cast<VarContext *>(_localctx)->arrNameContext = arrName();

              _localctx->target_->setIdent(dynamic_cast<VarContext *>(_localctx)->arrNameContext->nameNode);
          
      setState(340);
      match(smallCParser::T__3);
      setState(341);
      dynamic_cast<VarContext *>(_localctx)->intExprContext = intExpr(0);

              _localctx->target_->setIndex(dynamic_cast<VarContext *>(_localctx)->intExprContext->intExprNode);
          
      setState(343);
      match(smallCParser::T__4);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

smallCParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ParamListContext* smallCParser::ParamsContext::paramList() {
  return getRuleContext<smallCParser::ParamListContext>(0);
}


size_t smallCParser::ParamsContext::getRuleIndex() const {
  return smallCParser::RuleParams;
}


antlrcpp::Any smallCParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamsContext* smallCParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 44, smallCParser::RuleParams);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(351);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__7:
      case smallCParser::T__8: {
        enterOuterAlt(_localctx, 1);
        setState(347);
        dynamic_cast<ParamsContext *>(_localctx)->paramListContext = paramList();

                for(unsigned int i = 0; i < dynamic_cast<ParamsContext *>(_localctx)->paramListContext->parameterList.size(); i++)
                    _localctx->parameterList.push_back(dynamic_cast<ParamsContext *>(_localctx)->paramListContext->parameterList[i]);
            
        break;
      }

      case smallCParser::T__6: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamEntryContext ------------------------------------------------------------------

smallCParser::ParamEntryContext::ParamEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::VarTypeContext* smallCParser::ParamEntryContext::varType() {
  return getRuleContext<smallCParser::VarTypeContext>(0);
}

smallCParser::VarNameContext* smallCParser::ParamEntryContext::varName() {
  return getRuleContext<smallCParser::VarNameContext>(0);
}

smallCParser::ArrNameContext* smallCParser::ParamEntryContext::arrName() {
  return getRuleContext<smallCParser::ArrNameContext>(0);
}


size_t smallCParser::ParamEntryContext::getRuleIndex() const {
  return smallCParser::RuleParamEntry;
}


antlrcpp::Any smallCParser::ParamEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParamEntry(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamEntryContext* smallCParser::paramEntry() {
  ParamEntryContext *_localctx = _tracker.createInstance<ParamEntryContext>(_ctx, getState());
  enterRule(_localctx, 46, smallCParser::RuleParamEntry);
  dynamic_cast<ParamEntryContext *>(_localctx)->paramEntryNode =  new smallc::ParameterNode();
         _localctx->paramEntryNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(364);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(353);
      dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext = varType();

              _localctx->paramEntryNode->setType(dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext->typeNode);
          
      setState(355);
      dynamic_cast<ParamEntryContext *>(_localctx)->varNameContext = varName();

              _localctx->paramEntryNode->setIdent(dynamic_cast<ParamEntryContext *>(_localctx)->varNameContext->nameNode);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(358);
      dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext = varType();

              dynamic_cast<ParamEntryContext *>(_localctx)->arrTypeNode =  new smallc::ArrayTypeNode(dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext->typeNode);
              _localctx->arrTypeNode->setLine(dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext->typeNode->getLine());
              _localctx->arrTypeNode->setColumn(dynamic_cast<ParamEntryContext *>(_localctx)->varTypeContext->typeNode->getCol());
              _localctx->paramEntryNode->setType(_localctx->arrTypeNode);
          
      setState(360);
      dynamic_cast<ParamEntryContext *>(_localctx)->arrNameContext = arrName();

              _localctx->paramEntryNode->setIdent(dynamic_cast<ParamEntryContext *>(_localctx)->arrNameContext->nameNode);
          
      setState(362);
      match(smallCParser::T__30);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

smallCParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ParamEntryContext* smallCParser::ParamListContext::paramEntry() {
  return getRuleContext<smallCParser::ParamEntryContext>(0);
}

smallCParser::ParamListContext* smallCParser::ParamListContext::paramList() {
  return getRuleContext<smallCParser::ParamListContext>(0);
}


size_t smallCParser::ParamListContext::getRuleIndex() const {
  return smallCParser::RuleParamList;
}


antlrcpp::Any smallCParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ParamListContext* smallCParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 48, smallCParser::RuleParamList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(375);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(366);
      dynamic_cast<ParamListContext *>(_localctx)->paramEntryContext = paramEntry();

             _localctx->parameterList.push_back(dynamic_cast<ParamListContext *>(_localctx)->paramEntryContext->paramEntryNode);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(369);
      dynamic_cast<ParamListContext *>(_localctx)->paramEntryContext = paramEntry();

             _localctx->parameterList.push_back(dynamic_cast<ParamListContext *>(_localctx)->paramEntryContext->paramEntryNode);
          
      setState(371);
      match(smallCParser::T__31);
      setState(372);
      dynamic_cast<ParamListContext *>(_localctx)->paramListContext = paramList();

              for(unsigned int i = 0; i < dynamic_cast<ParamListContext *>(_localctx)->paramListContext->parameterList.size(); i++)
                  _localctx->parameterList.push_back(dynamic_cast<ParamListContext *>(_localctx)->paramListContext->parameterList[i]);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgsContext ------------------------------------------------------------------

smallCParser::ArgsContext::ArgsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArgListContext* smallCParser::ArgsContext::argList() {
  return getRuleContext<smallCParser::ArgListContext>(0);
}


size_t smallCParser::ArgsContext::getRuleIndex() const {
  return smallCParser::RuleArgs;
}


antlrcpp::Any smallCParser::ArgsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgs(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgsContext* smallCParser::args() {
  ArgsContext *_localctx = _tracker.createInstance<ArgsContext>(_ctx, getState());
  enterRule(_localctx, 50, smallCParser::RuleArgs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(381);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::T__5:
      case smallCParser::T__17:
      case smallCParser::T__18:
      case smallCParser::BOOL:
      case smallCParser::ID:
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(377);
        dynamic_cast<ArgsContext *>(_localctx)->argListContext = argList();

                for(unsigned int i = 0; i < dynamic_cast<ArgsContext *>(_localctx)->argListContext->argsList.size(); i++)
                    _localctx->argsList.push_back(dynamic_cast<ArgsContext *>(_localctx)->argListContext->argsList[i]);
            
        break;
      }

      case smallCParser::T__6: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgEntryContext ------------------------------------------------------------------

smallCParser::ArgEntryContext::ArgEntryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ExprContext* smallCParser::ArgEntryContext::expr() {
  return getRuleContext<smallCParser::ExprContext>(0);
}


size_t smallCParser::ArgEntryContext::getRuleIndex() const {
  return smallCParser::RuleArgEntry;
}


antlrcpp::Any smallCParser::ArgEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgEntry(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgEntryContext* smallCParser::argEntry() {
  ArgEntryContext *_localctx = _tracker.createInstance<ArgEntryContext>(_ctx, getState());
  enterRule(_localctx, 52, smallCParser::RuleArgEntry);
  dynamic_cast<ArgEntryContext *>(_localctx)->argEntryNode =  new smallc::ArgumentNode();
         _localctx->argEntryNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    dynamic_cast<ArgEntryContext *>(_localctx)->exprContext = expr(0);

            _localctx->argEntryNode->setExpr(dynamic_cast<ArgEntryContext *>(_localctx)->exprContext->exprStmtNode);
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

smallCParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

smallCParser::ArgEntryContext* smallCParser::ArgListContext::argEntry() {
  return getRuleContext<smallCParser::ArgEntryContext>(0);
}

smallCParser::ArgListContext* smallCParser::ArgListContext::argList() {
  return getRuleContext<smallCParser::ArgListContext>(0);
}


size_t smallCParser::ArgListContext::getRuleIndex() const {
  return smallCParser::RuleArgList;
}


antlrcpp::Any smallCParser::ArgListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArgList(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArgListContext* smallCParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 54, smallCParser::RuleArgList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(395);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(386);
      dynamic_cast<ArgListContext *>(_localctx)->argEntryContext = argEntry();

              _localctx->argsList.push_back(dynamic_cast<ArgListContext *>(_localctx)->argEntryContext->argEntryNode);
          
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(389);
      dynamic_cast<ArgListContext *>(_localctx)->argEntryContext = argEntry();

              _localctx->argsList.push_back(dynamic_cast<ArgListContext *>(_localctx)->argEntryContext->argEntryNode);
          
      setState(391);
      match(smallCParser::T__31);
      setState(392);
      dynamic_cast<ArgListContext *>(_localctx)->argListContext = argList();

              for(unsigned int i = 0; i < dynamic_cast<ArgListContext *>(_localctx)->argListContext->argsList.size(); i++)
                  _localctx->argsList.push_back(dynamic_cast<ArgListContext *>(_localctx)->argListContext->argsList[i]);
          
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarNameContext ------------------------------------------------------------------

smallCParser::VarNameContext::VarNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::VarNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::VarNameContext::getRuleIndex() const {
  return smallCParser::RuleVarName;
}


antlrcpp::Any smallCParser::VarNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitVarName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::VarNameContext* smallCParser::varName() {
  VarNameContext *_localctx = _tracker.createInstance<VarNameContext>(_ctx, getState());
  enterRule(_localctx, 56, smallCParser::RuleVarName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    dynamic_cast<VarNameContext *>(_localctx)->t = match(smallCParser::ID);

        dynamic_cast<VarNameContext *>(_localctx)->nameNode =  new smallc::IdentifierNode((dynamic_cast<VarNameContext *>(_localctx)->t != nullptr ? dynamic_cast<VarNameContext *>(_localctx)->t->getText() : ""));
        _localctx->nameNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrNameContext ------------------------------------------------------------------

smallCParser::ArrNameContext::ArrNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::ArrNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::ArrNameContext::getRuleIndex() const {
  return smallCParser::RuleArrName;
}


antlrcpp::Any smallCParser::ArrNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitArrName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::ArrNameContext* smallCParser::arrName() {
  ArrNameContext *_localctx = _tracker.createInstance<ArrNameContext>(_ctx, getState());
  enterRule(_localctx, 58, smallCParser::RuleArrName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(400);
    dynamic_cast<ArrNameContext *>(_localctx)->t = match(smallCParser::ID);

        dynamic_cast<ArrNameContext *>(_localctx)->nameNode =  new smallc::IdentifierNode((dynamic_cast<ArrNameContext *>(_localctx)->t != nullptr ? dynamic_cast<ArrNameContext *>(_localctx)->t->getText() : ""));
        _localctx->nameNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FcnNameContext ------------------------------------------------------------------

smallCParser::FcnNameContext::FcnNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::FcnNameContext::ID() {
  return getToken(smallCParser::ID, 0);
}


size_t smallCParser::FcnNameContext::getRuleIndex() const {
  return smallCParser::RuleFcnName;
}


antlrcpp::Any smallCParser::FcnNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitFcnName(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::FcnNameContext* smallCParser::fcnName() {
  FcnNameContext *_localctx = _tracker.createInstance<FcnNameContext>(_ctx, getState());
  enterRule(_localctx, 60, smallCParser::RuleFcnName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    dynamic_cast<FcnNameContext *>(_localctx)->t = match(smallCParser::ID);

        dynamic_cast<FcnNameContext *>(_localctx)->nameNode =  new smallc::IdentifierNode((dynamic_cast<FcnNameContext *>(_localctx)->t != nullptr ? dynamic_cast<FcnNameContext *>(_localctx)->t->getText() : ""));
        _localctx->nameNode->setLocation(_localctx->start->getLine(), _localctx->start->getCharPositionInLine());

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntConstContext ------------------------------------------------------------------

smallCParser::IntConstContext::IntConstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* smallCParser::IntConstContext::INT() {
  return getToken(smallCParser::INT, 0);
}


size_t smallCParser::IntConstContext::getRuleIndex() const {
  return smallCParser::RuleIntConst;
}


antlrcpp::Any smallCParser::IntConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<smallCVisitor*>(visitor))
    return parserVisitor->visitIntConst(this);
  else
    return visitor->visitChildren(this);
}

smallCParser::IntConstContext* smallCParser::intConst() {
  IntConstContext *_localctx = _tracker.createInstance<IntConstContext>(_ctx, getState());
  enterRule(_localctx, 62, smallCParser::RuleIntConst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(409);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case smallCParser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(406);
        match(smallCParser::INT);
        break;
      }

      case smallCParser::T__18: {
        enterOuterAlt(_localctx, 2);
        setState(407);
        match(smallCParser::T__18);
        setState(408);
        match(smallCParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool smallCParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);
    case 20: return intExprSempred(dynamic_cast<IntExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool smallCParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);
    case 2: return precpred(_ctx, 2);
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool smallCParser::intExprSempred(IntExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 3);
    case 5: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> smallCParser::_decisionToDFA;
atn::PredictionContextCache smallCParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN smallCParser::_atn;
std::vector<uint16_t> smallCParser::_serializedATN;

std::vector<std::string> smallCParser::_ruleNames = {
  "program", "preamble", "decls", "scalarDeclList", "scalarDecl", "arrDeclList", 
  "arrDecl", "fcnProto", "fcnDecl", "varType", "retType", "constant", "boolConst", 
  "scope", "stmt", "assignStmt", "ifStmt", "whileStmt", "retStmt", "expr", 
  "intExpr", "var", "params", "paramEntry", "paramList", "args", "argEntry", 
  "argList", "varName", "arrName", "fcnName", "intConst"
};

std::vector<std::string> smallCParser::_literalNames = {
  "", "'#include'", "'\"scio.h\"'", "';'", "'['", "']'", "'('", "')'", "'bool'", 
  "'int'", "'void'", "'{'", "'}'", "'='", "'if'", "'else'", "'while'", "'return'", 
  "'!'", "'-'", "'<'", "'<='", "'>'", "'>='", "'=='", "'!='", "'||'", "'&&'", 
  "'*'", "'/'", "'+'", "'[]'", "','"
};

std::vector<std::string> smallCParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "BOOL", "ID", 
  "INT", "WS", "COMMENT"
};

dfa::Vocabulary smallCParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> smallCParser::_tokenNames;

smallCParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x27, 0x19e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x47, 0xa, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x4c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x4f, 0xb, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x62, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x6c, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7c, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x9f, 0xa, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa6, 0xa, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xae, 0xa, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xb9, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 
    0xbc, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xc1, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0xc4, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xdb, 0xa, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xf4, 0xa, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x105, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x11a, 0xa, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x7, 0x15, 0x130, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x133, 0xb, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 
    0x16, 0x141, 0xa, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 
    0x16, 0x14d, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x150, 0xb, 0x16, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x15c, 0xa, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x162, 0xa, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x16f, 0xa, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x17a, 0xa, 0x1a, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x180, 0xa, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x18e, 
    0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x19c, 0xa, 0x21, 0x3, 0x21, 0x2, 0x4, 0x28, 0x2a, 0x22, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x2, 0x7, 0x3, 0x2, 0x14, 
    0x15, 0x3, 0x2, 0x16, 0x19, 0x3, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x1e, 0x1f, 
    0x4, 0x2, 0x15, 0x15, 0x20, 0x20, 0x2, 0x1a3, 0x2, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x52, 0x3, 0x2, 0x2, 0x2, 0x6, 0x61, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x6d, 0x3, 0x2, 0x2, 0x2, 0xc, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x9e, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x18, 0xad, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xda, 0x3, 0x2, 0x2, 0x2, 0x20, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0x24, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x26, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x119, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x140, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x161, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x32, 0x179, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x36, 0x181, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x192, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x195, 0x3, 0x2, 0x2, 0x2, 0x40, 0x19b, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x5, 0x4, 0x3, 0x2, 0x43, 0x44, 0x8, 
    0x2, 0x1, 0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x46, 0x42, 0x3, 0x2, 0x2, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x47, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x5, 0x6, 0x4, 0x2, 
    0x49, 0x4a, 0x8, 0x2, 0x1, 0x2, 0x4a, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x48, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 
    0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x2, 
    0x2, 0x3, 0x51, 0x3, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x3, 0x2, 
    0x2, 0x53, 0x54, 0x7, 0x4, 0x2, 0x2, 0x54, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x56, 0x5, 0x8, 0x5, 0x2, 0x56, 0x57, 0x8, 0x4, 0x1, 0x2, 0x57, 
    0x62, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x5, 0xc, 0x7, 0x2, 0x59, 0x5a, 
    0x8, 0x4, 0x1, 0x2, 0x5a, 0x62, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x5, 
    0x10, 0x9, 0x2, 0x5c, 0x5d, 0x8, 0x4, 0x1, 0x2, 0x5d, 0x62, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x5f, 0x5, 0x12, 0xa, 0x2, 0x5f, 0x60, 0x8, 0x4, 0x1, 
    0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 0x61, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x58, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0x62, 0x7, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 
    0x5, 0xa, 0x6, 0x2, 0x64, 0x65, 0x8, 0x5, 0x1, 0x2, 0x65, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x66, 0x67, 0x5, 0xa, 0x6, 0x2, 0x67, 0x68, 0x8, 0x5, 
    0x1, 0x2, 0x68, 0x69, 0x5, 0x8, 0x5, 0x2, 0x69, 0x6a, 0x8, 0x5, 0x1, 
    0x2, 0x6a, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6e, 0x5, 0x14, 0xb, 0x2, 0x6e, 0x6f, 0x8, 0x6, 0x1, 0x2, 0x6f, 0x70, 
    0x5, 0x3a, 0x1e, 0x2, 0x70, 0x71, 0x8, 0x6, 0x1, 0x2, 0x71, 0x72, 0x7, 
    0x5, 0x2, 0x2, 0x72, 0xb, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x5, 0xe, 
    0x8, 0x2, 0x74, 0x75, 0x8, 0x7, 0x1, 0x2, 0x75, 0x7c, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x77, 0x5, 0xe, 0x8, 0x2, 0x77, 0x78, 0x8, 0x7, 0x1, 0x2, 
    0x78, 0x79, 0x5, 0xc, 0x7, 0x2, 0x79, 0x7a, 0x8, 0x7, 0x1, 0x2, 0x7a, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x73, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x5, 
    0x14, 0xb, 0x2, 0x7e, 0x7f, 0x5, 0x3c, 0x1f, 0x2, 0x7f, 0x80, 0x7, 0x6, 
    0x2, 0x2, 0x80, 0x81, 0x5, 0x40, 0x21, 0x2, 0x81, 0x82, 0x7, 0x7, 0x2, 
    0x2, 0x82, 0x83, 0x7, 0x5, 0x2, 0x2, 0x83, 0x84, 0x8, 0x8, 0x1, 0x2, 
    0x84, 0xf, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x5, 0x16, 0xc, 0x2, 0x86, 
    0x87, 0x8, 0x9, 0x1, 0x2, 0x87, 0x88, 0x5, 0x3e, 0x20, 0x2, 0x88, 0x89, 
    0x8, 0x9, 0x1, 0x2, 0x89, 0x8a, 0x7, 0x8, 0x2, 0x2, 0x8a, 0x8b, 0x5, 
    0x2e, 0x18, 0x2, 0x8b, 0x8c, 0x8, 0x9, 0x1, 0x2, 0x8c, 0x8d, 0x7, 0x9, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0x5, 0x2, 0x2, 0x8e, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x90, 0x5, 0x16, 0xc, 0x2, 0x90, 0x91, 0x8, 0xa, 0x1, 0x2, 
    0x91, 0x92, 0x5, 0x3e, 0x20, 0x2, 0x92, 0x93, 0x8, 0xa, 0x1, 0x2, 0x93, 
    0x94, 0x7, 0x8, 0x2, 0x2, 0x94, 0x95, 0x5, 0x2e, 0x18, 0x2, 0x95, 0x96, 
    0x8, 0xa, 0x1, 0x2, 0x96, 0x97, 0x7, 0x9, 0x2, 0x2, 0x97, 0x98, 0x5, 
    0x1c, 0xf, 0x2, 0x98, 0x99, 0x8, 0xa, 0x1, 0x2, 0x99, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x9b, 0x7, 0xa, 0x2, 0x2, 0x9b, 0x9f, 0x8, 0xb, 0x1, 
    0x2, 0x9c, 0x9d, 0x7, 0xb, 0x2, 0x2, 0x9d, 0x9f, 0x8, 0xb, 0x1, 0x2, 
    0x9e, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0xc, 0x2, 0x2, 0xa1, 0xa6, 
    0x8, 0xc, 0x1, 0x2, 0xa2, 0xa3, 0x5, 0x14, 0xb, 0x2, 0xa3, 0xa4, 0x8, 
    0xc, 0x1, 0x2, 0xa4, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa0, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa8, 0x5, 0x1a, 0xe, 0x2, 0xa8, 0xa9, 0x8, 0xd, 0x1, 0x2, 
    0xa9, 0xae, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x40, 0x21, 0x2, 0xab, 
    0xac, 0x8, 0xd, 0x1, 0x2, 0xac, 0xae, 0x3, 0x2, 0x2, 0x2, 0xad, 0xa7, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xae, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x23, 0x2, 0x2, 0xb0, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0xb1, 0xba, 0x7, 0xd, 0x2, 0x2, 0xb2, 0xb3, 0x5, 0xa, 0x6, 
    0x2, 0xb3, 0xb4, 0x8, 0xf, 0x1, 0x2, 0xb4, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xb6, 0x5, 0xe, 0x8, 0x2, 0xb6, 0xb7, 0x8, 0xf, 0x1, 0x2, 0xb7, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb5, 
    0x3, 0x2, 0x2, 0x2, 0xb9, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xc2, 0x3, 0x2, 
    0x2, 0x2, 0xbc, 0xba, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x1e, 0x10, 
    0x2, 0xbe, 0xbf, 0x8, 0xf, 0x1, 0x2, 0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc0, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc5, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x7, 
    0xe, 0x2, 0x2, 0xc6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x28, 
    0x15, 0x2, 0xc8, 0xc9, 0x8, 0x10, 0x1, 0x2, 0xc9, 0xca, 0x7, 0x5, 0x2, 
    0x2, 0xca, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x20, 0x11, 0x2, 
    0xcc, 0xcd, 0x8, 0x10, 0x1, 0x2, 0xcd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xce, 
    0xcf, 0x5, 0x22, 0x12, 0x2, 0xcf, 0xd0, 0x8, 0x10, 0x1, 0x2, 0xd0, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x5, 0x24, 0x13, 0x2, 0xd2, 0xd3, 0x8, 
    0x10, 0x1, 0x2, 0xd3, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x5, 0x26, 
    0x14, 0x2, 0xd5, 0xd6, 0x8, 0x10, 0x1, 0x2, 0xd6, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0xd7, 0xd8, 0x5, 0x1c, 0xf, 0x2, 0xd8, 0xd9, 0x8, 0x10, 0x1, 0x2, 
    0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xda, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xce, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xda, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd7, 0x3, 
    0x2, 0x2, 0x2, 0xdb, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x5, 0x2c, 
    0x17, 0x2, 0xdd, 0xde, 0x8, 0x11, 0x1, 0x2, 0xde, 0xdf, 0x7, 0xf, 0x2, 
    0x2, 0xdf, 0xe0, 0x5, 0x28, 0x15, 0x2, 0xe0, 0xe1, 0x8, 0x11, 0x1, 0x2, 
    0xe1, 0xe2, 0x7, 0x5, 0x2, 0x2, 0xe2, 0x21, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xe4, 0x7, 0x10, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x8, 0x2, 0x2, 0xe5, 0xe6, 
    0x5, 0x28, 0x15, 0x2, 0xe6, 0xe7, 0x7, 0x9, 0x2, 0x2, 0xe7, 0xe8, 0x5, 
    0x1e, 0x10, 0x2, 0xe8, 0xe9, 0x8, 0x12, 0x1, 0x2, 0xe9, 0xf4, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xeb, 0x7, 0x10, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x8, 0x2, 
    0x2, 0xec, 0xed, 0x5, 0x28, 0x15, 0x2, 0xed, 0xee, 0x7, 0x9, 0x2, 0x2, 
    0xee, 0xef, 0x5, 0x1e, 0x10, 0x2, 0xef, 0xf0, 0x7, 0x11, 0x2, 0x2, 0xf0, 
    0xf1, 0x5, 0x1e, 0x10, 0x2, 0xf1, 0xf2, 0x8, 0x12, 0x1, 0x2, 0xf2, 0xf4, 
    0x3, 0x2, 0x2, 0x2, 0xf3, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xea, 0x3, 
    0x2, 0x2, 0x2, 0xf4, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x12, 
    0x2, 0x2, 0xf6, 0xf7, 0x7, 0x8, 0x2, 0x2, 0xf7, 0xf8, 0x5, 0x28, 0x15, 
    0x2, 0xf8, 0xf9, 0x7, 0x9, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x1e, 0x10, 0x2, 
    0xfa, 0xfb, 0x8, 0x13, 0x1, 0x2, 0xfb, 0x25, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfd, 0x7, 0x13, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x28, 0x15, 0x2, 0xfe, 0xff, 
    0x7, 0x5, 0x2, 0x2, 0xff, 0x100, 0x8, 0x14, 0x1, 0x2, 0x100, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 0x13, 0x2, 0x2, 0x102, 0x103, 
    0x7, 0x5, 0x2, 0x2, 0x103, 0x105, 0x8, 0x14, 0x1, 0x2, 0x104, 0xfc, 
    0x3, 0x2, 0x2, 0x2, 0x104, 0x101, 0x3, 0x2, 0x2, 0x2, 0x105, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x106, 0x107, 0x8, 0x15, 0x1, 0x2, 0x107, 0x108, 0x5, 
    0x2a, 0x16, 0x2, 0x108, 0x109, 0x8, 0x15, 0x1, 0x2, 0x109, 0x11a, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x8, 0x2, 0x2, 0x10b, 0x10c, 0x5, 
    0x28, 0x15, 0x2, 0x10c, 0x10d, 0x8, 0x15, 0x1, 0x2, 0x10d, 0x10e, 0x7, 
    0x9, 0x2, 0x2, 0x10e, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x5, 
    0x3e, 0x20, 0x2, 0x110, 0x111, 0x7, 0x8, 0x2, 0x2, 0x111, 0x112, 0x5, 
    0x34, 0x1b, 0x2, 0x112, 0x113, 0x7, 0x9, 0x2, 0x2, 0x113, 0x114, 0x8, 
    0x15, 0x1, 0x2, 0x114, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 0x9, 
    0x2, 0x2, 0x2, 0x116, 0x117, 0x5, 0x28, 0x15, 0x7, 0x117, 0x118, 0x8, 
    0x15, 0x1, 0x2, 0x118, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x119, 0x106, 0x3, 
    0x2, 0x2, 0x2, 0x119, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x119, 0x10f, 0x3, 
    0x2, 0x2, 0x2, 0x119, 0x115, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x11b, 0x11c, 0xc, 0x6, 0x2, 0x2, 0x11c, 0x11d, 0x9, 
    0x3, 0x2, 0x2, 0x11d, 0x11e, 0x5, 0x28, 0x15, 0x7, 0x11e, 0x11f, 0x8, 
    0x15, 0x1, 0x2, 0x11f, 0x130, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0xc, 
    0x5, 0x2, 0x2, 0x121, 0x122, 0x9, 0x4, 0x2, 0x2, 0x122, 0x123, 0x5, 
    0x28, 0x15, 0x6, 0x123, 0x124, 0x8, 0x15, 0x1, 0x2, 0x124, 0x130, 0x3, 
    0x2, 0x2, 0x2, 0x125, 0x126, 0xc, 0x4, 0x2, 0x2, 0x126, 0x127, 0x7, 
    0x1c, 0x2, 0x2, 0x127, 0x128, 0x5, 0x28, 0x15, 0x5, 0x128, 0x129, 0x8, 
    0x15, 0x1, 0x2, 0x129, 0x130, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0xc, 
    0x3, 0x2, 0x2, 0x12b, 0x12c, 0x7, 0x1d, 0x2, 0x2, 0x12c, 0x12d, 0x5, 
    0x28, 0x15, 0x4, 0x12d, 0x12e, 0x8, 0x15, 0x1, 0x2, 0x12e, 0x130, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x120, 0x3, 
    0x2, 0x2, 0x2, 0x12f, 0x125, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x130, 0x133, 0x3, 0x2, 0x2, 0x2, 0x131, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x8, 0x16, 
    0x1, 0x2, 0x135, 0x136, 0x5, 0x2c, 0x17, 0x2, 0x136, 0x137, 0x8, 0x16, 
    0x1, 0x2, 0x137, 0x141, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 0x5, 0x18, 
    0xd, 0x2, 0x139, 0x13a, 0x8, 0x16, 0x1, 0x2, 0x13a, 0x141, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x13c, 0x7, 0x8, 0x2, 0x2, 0x13c, 0x13d, 0x5, 0x2a, 
    0x16, 0x2, 0x13d, 0x13e, 0x8, 0x16, 0x1, 0x2, 0x13e, 0x13f, 0x7, 0x9, 
    0x2, 0x2, 0x13f, 0x141, 0x3, 0x2, 0x2, 0x2, 0x140, 0x134, 0x3, 0x2, 
    0x2, 0x2, 0x140, 0x138, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0xc, 0x5, 
    0x2, 0x2, 0x143, 0x144, 0x9, 0x5, 0x2, 0x2, 0x144, 0x145, 0x5, 0x2a, 
    0x16, 0x6, 0x145, 0x146, 0x8, 0x16, 0x1, 0x2, 0x146, 0x14d, 0x3, 0x2, 
    0x2, 0x2, 0x147, 0x148, 0xc, 0x4, 0x2, 0x2, 0x148, 0x149, 0x9, 0x6, 
    0x2, 0x2, 0x149, 0x14a, 0x5, 0x2a, 0x16, 0x5, 0x14a, 0x14b, 0x8, 0x16, 
    0x1, 0x2, 0x14b, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x142, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x147, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x150, 0x3, 0x2, 
    0x2, 0x2, 0x14e, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x152, 0x5, 0x3a, 0x1e, 0x2, 0x152, 0x153, 0x8, 0x17, 0x1, 
    0x2, 0x153, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 0x5, 0x3c, 0x1f, 
    0x2, 0x155, 0x156, 0x8, 0x17, 0x1, 0x2, 0x156, 0x157, 0x7, 0x6, 0x2, 
    0x2, 0x157, 0x158, 0x5, 0x2a, 0x16, 0x2, 0x158, 0x159, 0x8, 0x17, 0x1, 
    0x2, 0x159, 0x15a, 0x7, 0x7, 0x2, 0x2, 0x15a, 0x15c, 0x3, 0x2, 0x2, 
    0x2, 0x15b, 0x151, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x154, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x32, 0x1a, 
    0x2, 0x15e, 0x15f, 0x8, 0x18, 0x1, 0x2, 0x15f, 0x162, 0x3, 0x2, 0x2, 
    0x2, 0x160, 0x162, 0x3, 0x2, 0x2, 0x2, 0x161, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x164, 0x5, 0x14, 0xb, 0x2, 0x164, 0x165, 0x8, 0x19, 0x1, 0x2, 
    0x165, 0x166, 0x5, 0x3a, 0x1e, 0x2, 0x166, 0x167, 0x8, 0x19, 0x1, 0x2, 
    0x167, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x5, 0x14, 0xb, 0x2, 
    0x169, 0x16a, 0x8, 0x19, 0x1, 0x2, 0x16a, 0x16b, 0x5, 0x3c, 0x1f, 0x2, 
    0x16b, 0x16c, 0x8, 0x19, 0x1, 0x2, 0x16c, 0x16d, 0x7, 0x21, 0x2, 0x2, 
    0x16d, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x163, 0x3, 0x2, 0x2, 0x2, 
    0x16e, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x31, 0x3, 0x2, 0x2, 0x2, 0x170, 
    0x171, 0x5, 0x30, 0x19, 0x2, 0x171, 0x172, 0x8, 0x1a, 0x1, 0x2, 0x172, 
    0x17a, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x5, 0x30, 0x19, 0x2, 0x174, 
    0x175, 0x8, 0x1a, 0x1, 0x2, 0x175, 0x176, 0x7, 0x22, 0x2, 0x2, 0x176, 
    0x177, 0x5, 0x32, 0x1a, 0x2, 0x177, 0x178, 0x8, 0x1a, 0x1, 0x2, 0x178, 
    0x17a, 0x3, 0x2, 0x2, 0x2, 0x179, 0x170, 0x3, 0x2, 0x2, 0x2, 0x179, 
    0x173, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x33, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 
    0x5, 0x38, 0x1d, 0x2, 0x17c, 0x17d, 0x8, 0x1b, 0x1, 0x2, 0x17d, 0x180, 
    0x3, 0x2, 0x2, 0x2, 0x17e, 0x180, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17b, 
    0x3, 0x2, 0x2, 0x2, 0x17f, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x180, 0x35, 0x3, 
    0x2, 0x2, 0x2, 0x181, 0x182, 0x5, 0x28, 0x15, 0x2, 0x182, 0x183, 0x8, 
    0x1c, 0x1, 0x2, 0x183, 0x37, 0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 0x5, 
    0x36, 0x1c, 0x2, 0x185, 0x186, 0x8, 0x1d, 0x1, 0x2, 0x186, 0x18e, 0x3, 
    0x2, 0x2, 0x2, 0x187, 0x188, 0x5, 0x36, 0x1c, 0x2, 0x188, 0x189, 0x8, 
    0x1d, 0x1, 0x2, 0x189, 0x18a, 0x7, 0x22, 0x2, 0x2, 0x18a, 0x18b, 0x5, 
    0x38, 0x1d, 0x2, 0x18b, 0x18c, 0x8, 0x1d, 0x1, 0x2, 0x18c, 0x18e, 0x3, 
    0x2, 0x2, 0x2, 0x18d, 0x184, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x187, 0x3, 
    0x2, 0x2, 0x2, 0x18e, 0x39, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x24, 
    0x2, 0x2, 0x190, 0x191, 0x8, 0x1e, 0x1, 0x2, 0x191, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x192, 0x193, 0x7, 0x24, 0x2, 0x2, 0x193, 0x194, 0x8, 0x1f, 
    0x1, 0x2, 0x194, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x7, 0x24, 
    0x2, 0x2, 0x196, 0x197, 0x8, 0x20, 0x1, 0x2, 0x197, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x198, 0x19c, 0x7, 0x25, 0x2, 0x2, 0x199, 0x19a, 0x7, 0x15, 
    0x2, 0x2, 0x19a, 0x19c, 0x7, 0x25, 0x2, 0x2, 0x19b, 0x198, 0x3, 0x2, 
    0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x46, 0x4d, 0x61, 0x6b, 0x7b, 0x9e, 0xa5, 0xad, 0xb8, 0xba, 
    0xc2, 0xda, 0xf3, 0x104, 0x119, 0x12f, 0x131, 0x140, 0x14c, 0x14e, 0x15b, 
    0x161, 0x16e, 0x179, 0x17f, 0x18d, 0x19b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

smallCParser::Initializer smallCParser::_init;
