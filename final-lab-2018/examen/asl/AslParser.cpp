
// Generated from Asl.g4 by ANTLR 4.7.1


#include "AslListener.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}

void AslParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void AslParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(50);
      function();
      setState(53); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(55);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::FuncParamsContext* AslParser::FunctionContext::funcParams() {
  return getRuleContext<AslParser::FuncParamsContext>(0);
}

AslParser::FuncTypeContext* AslParser::FunctionContext::funcType() {
  return getRuleContext<AslParser::FuncTypeContext>(0);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}

void AslParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void AslParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(AslParser::FUNC);
    setState(58);
    match(AslParser::ID);
    setState(59);
    match(AslParser::LP);
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::ID) {
      setState(60);
      funcParams();
    }
    setState(63);
    match(AslParser::RP);
    setState(65);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::COLON) {
      setState(64);
      funcType();
    }
    setState(67);
    declarations();
    setState(68);
    statements();
    setState(69);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncParamsContext ------------------------------------------------------------------

AslParser::FuncParamsContext::FuncParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AslParser::FuncParamsContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::FuncParamsContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

std::vector<AslParser::TypeRContext *> AslParser::FuncParamsContext::typeR() {
  return getRuleContexts<AslParser::TypeRContext>();
}

AslParser::TypeRContext* AslParser::FuncParamsContext::typeR(size_t i) {
  return getRuleContext<AslParser::TypeRContext>(i);
}


size_t AslParser::FuncParamsContext::getRuleIndex() const {
  return AslParser::RuleFuncParams;
}

void AslParser::FuncParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncParams(this);
}

void AslParser::FuncParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncParams(this);
}

AslParser::FuncParamsContext* AslParser::funcParams() {
  FuncParamsContext *_localctx = _tracker.createInstance<FuncParamsContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleFuncParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71);
    match(AslParser::ID);
    setState(72);
    match(AslParser::COLON);
    setState(73);
    typeR();
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::COMMA) {
      setState(74);
      match(AslParser::COMMA);
      setState(75);
      match(AslParser::ID);
      setState(76);
      match(AslParser::COLON);
      setState(77);
      typeR();
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncTypeContext ------------------------------------------------------------------

AslParser::FuncTypeContext::FuncTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::TypeContext* AslParser::FuncTypeContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::FuncTypeContext::getRuleIndex() const {
  return AslParser::RuleFuncType;
}

void AslParser::FuncTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncType(this);
}

void AslParser::FuncTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncType(this);
}

AslParser::FuncTypeContext* AslParser::funcType() {
  FuncTypeContext *_localctx = _tracker.createInstance<FuncTypeContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleFuncType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(AslParser::COLON);
    setState(84);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}

void AslParser::DeclarationsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarations(this);
}

void AslParser::DeclarationsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarations(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(86);
      variable_decl();
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeRContext* AslParser::Variable_declContext::typeR() {
  return getRuleContext<AslParser::TypeRContext>(0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}

void AslParser::Variable_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_decl(this);
}

void AslParser::Variable_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_decl(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(AslParser::VAR);
    setState(93);
    match(AslParser::ID);
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::COMMA) {
      setState(94);
      match(AslParser::COMMA);
      setState(95);
      match(AslParser::ID);
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(101);
    match(AslParser::COLON);
    setState(102);
    typeR();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeRContext ------------------------------------------------------------------

AslParser::TypeRContext::TypeRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::TypeContext* AslParser::TypeRContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}

AslParser::ArrayContext* AslParser::TypeRContext::array() {
  return getRuleContext<AslParser::ArrayContext>(0);
}

AslParser::PairContext* AslParser::TypeRContext::pair() {
  return getRuleContext<AslParser::PairContext>(0);
}


size_t AslParser::TypeRContext::getRuleIndex() const {
  return AslParser::RuleTypeR;
}

void AslParser::TypeRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeR(this);
}

void AslParser::TypeRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeR(this);
}

AslParser::TypeRContext* AslParser::typeR() {
  TypeRContext *_localctx = _tracker.createInstance<TypeRContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleTypeR);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(107);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::INT:
      case AslParser::FLOAT:
      case AslParser::BOOL:
      case AslParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(104);
        type();
        break;
      }

      case AslParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(105);
        array();
        break;
      }

      case AslParser::T__1: {
        enterOuterAlt(_localctx, 3);
        setState(106);
        pair();
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

//----------------- ArrayContext ------------------------------------------------------------------

AslParser::ArrayContext::ArrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ArrayContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

AslParser::ExprContext* AslParser::ArrayContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::TypeContext* AslParser::ArrayContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::ArrayContext::getRuleIndex() const {
  return AslParser::RuleArray;
}

void AslParser::ArrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray(this);
}

void AslParser::ArrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray(this);
}

AslParser::ArrayContext* AslParser::array() {
  ArrayContext *_localctx = _tracker.createInstance<ArrayContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleArray);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(109);
    match(AslParser::ARRAY);
    setState(110);
    match(AslParser::LSQ);
    setState(111);
    expr(0);
    setState(112);
    match(AslParser::RSQ);
    setState(113);
    match(AslParser::T__0);
    setState(114);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairContext ------------------------------------------------------------------

AslParser::PairContext::PairContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::TypeContext *> AslParser::PairContext::type() {
  return getRuleContexts<AslParser::TypeContext>();
}

AslParser::TypeContext* AslParser::PairContext::type(size_t i) {
  return getRuleContext<AslParser::TypeContext>(i);
}


size_t AslParser::PairContext::getRuleIndex() const {
  return AslParser::RulePair;
}

void AslParser::PairContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPair(this);
}

void AslParser::PairContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPair(this);
}

AslParser::PairContext* AslParser::pair() {
  PairContext *_localctx = _tracker.createInstance<PairContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RulePair);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    match(AslParser::T__1);
    setState(117);
    type();
    setState(118);
    match(AslParser::COMMA);
    setState(119);
    type();
    setState(120);
    match(AslParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::TypeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::TypeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}

tree::TerminalNode* AslParser::TypeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::TypeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}

void AslParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void AslParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}

void AslParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void AslParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::RETURN)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(124);
      statement();
      setState(129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RetFuncContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::RetFuncContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::RetFuncContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::RetFuncContext::RetFuncContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::RetFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRetFunc(this);
}
void AslParser::RetFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRetFunc(this);
}
//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::FuncConstructContext* AslParser::ProcCallContext::funcConstruct() {
  return getRuleContext<AslParser::FuncConstructContext>(0);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ProcCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcCall(this);
}
void AslParser::ProcCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcCall(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteExpr(this);
}
void AslParser::WriteExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteExpr(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WhileStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileStmt(this);
}
void AslParser::WhileStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileStmt(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

AslParser::ElseStatContext* AslParser::IfStmtContext::elseStat() {
  return getRuleContext<AslParser::ElseStatContext>(0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}
void AslParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::ReadStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReadStmt(this);
}
void AslParser::ReadStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReadStmt(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}
void AslParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }

void AslParser::WriteStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWriteString(this);
}
void AslParser::WriteStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWriteString(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 22, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(130);
      left_expr();
      setState(131);
      match(AslParser::ASSIGN);
      setState(132);
      expr(0);
      setState(133);
      match(AslParser::SCOLON);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(135);
      match(AslParser::IF);
      setState(136);
      expr(0);
      setState(137);
      match(AslParser::THEN);
      setState(138);
      statements();
      setState(140);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(139);
        elseStat();
      }
      setState(142);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(144);
      match(AslParser::WHILE);
      setState(145);
      expr(0);
      setState(146);
      match(AslParser::DO);
      setState(147);
      statements();
      setState(148);
      match(AslParser::ENDWHILE);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(150);
      funcConstruct();
      setState(151);
      match(AslParser::SCOLON);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(153);
      match(AslParser::READ);
      setState(154);
      left_expr();
      setState(155);
      match(AslParser::SCOLON);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(157);
      match(AslParser::WRITE);
      setState(158);
      expr(0);
      setState(159);
      match(AslParser::SCOLON);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(161);
      match(AslParser::WRITE);
      setState(162);
      match(AslParser::STRING);
      setState(163);
      match(AslParser::SCOLON);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::RetFuncContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(164);
      match(AslParser::RETURN);
      setState(166);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::AT)
        | (1ULL << AslParser::LP)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::NOT)
        | (1ULL << AslParser::TRUE)
        | (1ULL << AslParser::FALSE)
        | (1ULL << AslParser::ID)
        | (1ULL << AslParser::INTVAL))) != 0)) {
        setState(165);
        expr(0);
      }
      setState(168);
      match(AslParser::SCOLON);
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

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::Left_exprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ArrayConstructContext* AslParser::Left_exprContext::arrayConstruct() {
  return getRuleContext<AslParser::ArrayConstructContext>(0);
}

AslParser::PairExprContext* AslParser::Left_exprContext::pairExpr() {
  return getRuleContext<AslParser::PairExprContext>(0);
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}

void AslParser::Left_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeft_expr(this);
}

void AslParser::Left_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeft_expr(this);
}

AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 24, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(171);
      ident();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(172);
      arrayConstruct();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(173);
      pairExpr();
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

//----------------- ElseStatContext ------------------------------------------------------------------

AslParser::ElseStatContext::ElseStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ElseStatContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::StatementsContext* AslParser::ElseStatContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}


size_t AslParser::ElseStatContext::getRuleIndex() const {
  return AslParser::RuleElseStat;
}

void AslParser::ElseStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseStat(this);
}

void AslParser::ElseStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseStat(this);
}

AslParser::ElseStatContext* AslParser::elseStat() {
  ElseStatContext *_localctx = _tracker.createInstance<ElseStatContext>(_ctx, getState());
  enterRule(_localctx, 26, AslParser::RuleElseStat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(AslParser::ELSE);
    setState(177);
    statements();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParExprContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::ParExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ParExprContext::ParExprContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ParExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParExpr(this);
}
void AslParser::ParExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParExpr(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::UnaryExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::UnaryExprContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

tree::TerminalNode* AslParser::UnaryExprContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

tree::TerminalNode* AslParser::UnaryExprContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

AslParser::UnaryExprContext::UnaryExprContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}
void AslParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}
//----------------- FuncExprContext ------------------------------------------------------------------

AslParser::FuncConstructContext* AslParser::FuncExprContext::funcConstruct() {
  return getRuleContext<AslParser::FuncConstructContext>(0);
}

AslParser::FuncExprContext::FuncExprContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::FuncExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncExpr(this);
}
void AslParser::FuncExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncExpr(this);
}
//----------------- ArrayExprContext ------------------------------------------------------------------

AslParser::ArrayConstructContext* AslParser::ArrayExprContext::arrayConstruct() {
  return getRuleContext<AslParser::ArrayConstructContext>(0);
}

AslParser::ArrayExprContext::ArrayExprContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ArrayExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayExpr(this);
}
void AslParser::ArrayExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayExpr(this);
}
//----------------- BooleanExprContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::BooleanExprContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::BooleanExprContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::BooleanExprContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::BooleanExprContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::BooleanExprContext::BooleanExprContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::BooleanExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanExpr(this);
}
void AslParser::BooleanExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanExpr(this);
}
//----------------- AtomExprContext ------------------------------------------------------------------

AslParser::AtomContext* AslParser::AtomExprContext::atom() {
  return getRuleContext<AslParser::AtomContext>(0);
}

AslParser::AtomExprContext::AtomExprContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::AtomExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomExpr(this);
}
void AslParser::AtomExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomExpr(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ExprIdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprIdent(this);
}
void AslParser::ExprIdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprIdent(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::ArithmeticContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArithmetic(this);
}
void AslParser::ArithmeticContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArithmetic(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LE() {
  return getToken(AslParser::LE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GE() {
  return getToken(AslParser::GE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::EQ() {
  return getToken(AslParser::EQ, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NEQ() {
  return getToken(AslParser::NEQ, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }

void AslParser::RelationalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelational(this);
}
void AslParser::RelationalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelational(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(190);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(180);
      dynamic_cast<UnaryExprContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::PLUS)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::NOT))) != 0))) {
        dynamic_cast<UnaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(181);
      expr(12);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ParExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(182);
      match(AslParser::LP);
      setState(183);
      expr(0);
      setState(184);
      match(AslParser::RP);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      atom();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      ident();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ArrayExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(188);
      arrayConstruct();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<FuncExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(189);
      funcConstruct();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(212);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(210);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(192);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(193);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::MUL)
            | (1ULL << AslParser::DIV)
            | (1ULL << AslParser::MOD))) != 0))) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(194);
          expr(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(195);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(196);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::PLUS

          || _la == AslParser::MINUS)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(197);
          expr(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(198);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(199);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::GT)
            | (1ULL << AslParser::GE)
            | (1ULL << AslParser::LT)
            | (1ULL << AslParser::LE))) != 0))) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(200);
          expr(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(201);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(202);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::EQ

          || _la == AslParser::NEQ)) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(203);
          expr(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BooleanExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(204);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(205);
          dynamic_cast<BooleanExprContext *>(_localctx)->op = match(AslParser::AND);
          setState(206);
          expr(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BooleanExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(207);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(208);
          dynamic_cast<BooleanExprContext *>(_localctx)->op = match(AslParser::OR);
          setState(209);
          expr(7);
          break;
        }

        } 
      }
      setState(214);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ArrayConstructContext ------------------------------------------------------------------

AslParser::ArrayConstructContext::ArrayConstructContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::ArrayConstructContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprContext* AslParser::ArrayConstructContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}


size_t AslParser::ArrayConstructContext::getRuleIndex() const {
  return AslParser::RuleArrayConstruct;
}

void AslParser::ArrayConstructContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayConstruct(this);
}

void AslParser::ArrayConstructContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayConstruct(this);
}

AslParser::ArrayConstructContext* AslParser::arrayConstruct() {
  ArrayConstructContext *_localctx = _tracker.createInstance<ArrayConstructContext>(_ctx, getState());
  enterRule(_localctx, 30, AslParser::RuleArrayConstruct);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    ident();
    setState(216);
    match(AslParser::LSQ);
    setState(217);
    expr(0);
    setState(218);
    match(AslParser::RSQ);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncConstructContext ------------------------------------------------------------------

AslParser::FuncConstructContext::FuncConstructContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::FuncConstructContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprFuncContext* AslParser::FuncConstructContext::exprFunc() {
  return getRuleContext<AslParser::ExprFuncContext>(0);
}


size_t AslParser::FuncConstructContext::getRuleIndex() const {
  return AslParser::RuleFuncConstruct;
}

void AslParser::FuncConstructContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncConstruct(this);
}

void AslParser::FuncConstructContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncConstruct(this);
}

AslParser::FuncConstructContext* AslParser::funcConstruct() {
  FuncConstructContext *_localctx = _tracker.createInstance<FuncConstructContext>(_ctx, getState());
  enterRule(_localctx, 32, AslParser::RuleFuncConstruct);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    ident();
    setState(221);
    match(AslParser::LP);
    setState(223);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::AT)
      | (1ULL << AslParser::LP)
      | (1ULL << AslParser::PLUS)
      | (1ULL << AslParser::MINUS)
      | (1ULL << AslParser::NOT)
      | (1ULL << AslParser::TRUE)
      | (1ULL << AslParser::FALSE)
      | (1ULL << AslParser::ID)
      | (1ULL << AslParser::INTVAL))) != 0)) {
      setState(222);
      exprFunc();
    }
    setState(225);
    match(AslParser::RP);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprFuncContext ------------------------------------------------------------------

AslParser::ExprFuncContext::ExprFuncContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::ExprContext *> AslParser::ExprFuncContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ExprFuncContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}


size_t AslParser::ExprFuncContext::getRuleIndex() const {
  return AslParser::RuleExprFunc;
}

void AslParser::ExprFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprFunc(this);
}

void AslParser::ExprFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprFunc(this);
}

AslParser::ExprFuncContext* AslParser::exprFunc() {
  ExprFuncContext *_localctx = _tracker.createInstance<ExprFuncContext>(_ctx, getState());
  enterRule(_localctx, 34, AslParser::RuleExprFunc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(227);
    expr(0);
    setState(232);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::COMMA) {
      setState(228);
      match(AslParser::COMMA);
      setState(229);
      expr(0);
      setState(234);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PairExprContext ------------------------------------------------------------------

AslParser::PairExprContext::PairExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::IdentContext* AslParser::PairExprContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::PairExprContext::FIRST() {
  return getToken(AslParser::FIRST, 0);
}

tree::TerminalNode* AslParser::PairExprContext::SECOND() {
  return getToken(AslParser::SECOND, 0);
}


size_t AslParser::PairExprContext::getRuleIndex() const {
  return AslParser::RulePairExpr;
}

void AslParser::PairExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPairExpr(this);
}

void AslParser::PairExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPairExpr(this);
}

AslParser::PairExprContext* AslParser::pairExpr() {
  PairExprContext *_localctx = _tracker.createInstance<PairExprContext>(_ctx, getState());
  enterRule(_localctx, 36, AslParser::RulePairExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    ident();
    setState(236);
    match(AslParser::DOT);
    setState(237);
    _la = _input->LA(1);
    if (!(_la == AslParser::FIRST

    || _la == AslParser::SECOND)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

AslParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::BoolExprContext* AslParser::AtomContext::boolExpr() {
  return getRuleContext<AslParser::BoolExprContext>(0);
}

AslParser::PairExprContext* AslParser::AtomContext::pairExpr() {
  return getRuleContext<AslParser::PairExprContext>(0);
}

AslParser::ChartContext* AslParser::AtomContext::chart() {
  return getRuleContext<AslParser::ChartContext>(0);
}

AslParser::ValueContext* AslParser::AtomContext::value() {
  return getRuleContext<AslParser::ValueContext>(0);
}

AslParser::FvalContext* AslParser::AtomContext::fval() {
  return getRuleContext<AslParser::FvalContext>(0);
}


size_t AslParser::AtomContext::getRuleIndex() const {
  return AslParser::RuleAtom;
}

void AslParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void AslParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

AslParser::AtomContext* AslParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 38, AslParser::RuleAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(239);
      boolExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(240);
      pairExpr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(241);
      chart();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(242);
      value();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(243);
      fval();
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

//----------------- ChartContext ------------------------------------------------------------------

AslParser::ChartContext::ChartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AslParser::ChartContext::AT() {
  return getTokens(AslParser::AT);
}

tree::TerminalNode* AslParser::ChartContext::AT(size_t i) {
  return getToken(AslParser::AT, i);
}

tree::TerminalNode* AslParser::ChartContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::ChartContext::getRuleIndex() const {
  return AslParser::RuleChart;
}

void AslParser::ChartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChart(this);
}

void AslParser::ChartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChart(this);
}

AslParser::ChartContext* AslParser::chart() {
  ChartContext *_localctx = _tracker.createInstance<ChartContext>(_ctx, getState());
  enterRule(_localctx, 40, AslParser::RuleChart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    match(AslParser::AT);
    setState(247);
    match(AslParser::ID);
    setState(248);
    match(AslParser::AT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

AslParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}


size_t AslParser::ValueContext::getRuleIndex() const {
  return AslParser::RuleValue;
}

void AslParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void AslParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}

AslParser::ValueContext* AslParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 42, AslParser::RuleValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(AslParser::INTVAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FvalContext ------------------------------------------------------------------

AslParser::FvalContext::FvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AslParser::FvalContext::INTVAL() {
  return getTokens(AslParser::INTVAL);
}

tree::TerminalNode* AslParser::FvalContext::INTVAL(size_t i) {
  return getToken(AslParser::INTVAL, i);
}


size_t AslParser::FvalContext::getRuleIndex() const {
  return AslParser::RuleFval;
}

void AslParser::FvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFval(this);
}

void AslParser::FvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFval(this);
}

AslParser::FvalContext* AslParser::fval() {
  FvalContext *_localctx = _tracker.createInstance<FvalContext>(_ctx, getState());
  enterRule(_localctx, 44, AslParser::RuleFval);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(252);
    match(AslParser::INTVAL);
    setState(253);
    match(AslParser::DOT);
    setState(254);
    match(AslParser::INTVAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolExprContext ------------------------------------------------------------------

AslParser::BoolExprContext::BoolExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::BoolExprContext::TRUE() {
  return getToken(AslParser::TRUE, 0);
}

tree::TerminalNode* AslParser::BoolExprContext::FALSE() {
  return getToken(AslParser::FALSE, 0);
}


size_t AslParser::BoolExprContext::getRuleIndex() const {
  return AslParser::RuleBoolExpr;
}

void AslParser::BoolExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolExpr(this);
}

void AslParser::BoolExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolExpr(this);
}

AslParser::BoolExprContext* AslParser::boolExpr() {
  BoolExprContext *_localctx = _tracker.createInstance<BoolExprContext>(_ctx, getState());
  enterRule(_localctx, 46, AslParser::RuleBoolExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    _la = _input->LA(1);
    if (!(_la == AslParser::TRUE

    || _la == AslParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}

void AslParser::IdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdent(this);
}

void AslParser::IdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AslListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdent(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 48, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(258);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 14: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
    case 5: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "funcParams", "funcType", "declarations", "variable_decl", 
  "typeR", "array", "pair", "type", "statements", "statement", "left_expr", 
  "elseStat", "expr", "arrayConstruct", "funcConstruct", "exprFunc", "pairExpr", 
  "atom", "chart", "value", "fval", "boolExpr", "ident"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "'of'", "'pair'", "'endpair'", "'='", "'=='", "'!='", "'>'", "'>='", 
  "'<'", "'\"'", "'''", "'<='", "'('", "')'", "'['", "']'", "'{'", "'}'", 
  "':'", "';'", "'.'", "','", "'#'", "'+'", "'*'", "'-'", "'/'", "'%'", 
  "'and'", "'or'", "'not'", "'var'", "'int'", "'float'", "'bool'", "'char'", 
  "'true'", "'false'", "'array'", "'first'", "'second'", "'if'", "'then'", 
  "'else'", "'while'", "'do'", "'endwhile'", "'endif'", "'func'", "'endfunc'", 
  "'return'", "'read'", "'write'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "ASSIGN", "EQ", "NEQ", "GT", "GE", "LT", "AP", "AT", "LE", 
  "LP", "RP", "LSQ", "RSQ", "KEYL", "KEYR", "COLON", "SCOLON", "DOT", "COMMA", 
  "HASH", "PLUS", "MUL", "MINUS", "DIV", "MOD", "AND", "OR", "NOT", "VAR", 
  "INT", "FLOAT", "BOOL", "CHAR", "TRUE", "FALSE", "ARRAY", "FIRST", "SECOND", 
  "IF", "THEN", "ELSE", "WHILE", "DO", "ENDWHILE", "ENDIF", "FUNC", "ENDFUNC", 
  "RETURN", "READ", "WRITE", "ID", "INTVAL", "STRING", "COMMENT", "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
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
    0x3, 0x3c, 0x107, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x3, 0x2, 0x6, 0x2, 
    0x36, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x37, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x40, 0xa, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x44, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x7, 0x4, 0x51, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x54, 0xb, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x7, 0x6, 0x5a, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x5d, 0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 
    0x63, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x66, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6e, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xc, 0x7, 0xc, 0x80, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0x83, 0xb, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x8f, 0xa, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xa9, 0xa, 0xd, 0x3, 0xd, 0x5, 0xd, 0xac, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xb1, 0xa, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x5, 0x10, 0xc1, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x7, 0x10, 0xd5, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xd8, 
    0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xe2, 0xa, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xe9, 0xa, 0x13, 0xc, 
    0x13, 0xe, 0x13, 0xec, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
    0xf7, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x2, 0x3, 0x1e, 0x1b, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x2, 0xa, 
    0x3, 0x2, 0x23, 0x26, 0x5, 0x2, 0x1a, 0x1a, 0x1c, 0x1c, 0x21, 0x21, 
    0x4, 0x2, 0x1b, 0x1b, 0x1d, 0x1e, 0x4, 0x2, 0x1a, 0x1a, 0x1c, 0x1c, 
    0x4, 0x2, 0x9, 0xb, 0xe, 0xe, 0x3, 0x2, 0x7, 0x8, 0x3, 0x2, 0x2a, 0x2b, 
    0x3, 0x2, 0x27, 0x28, 0x2, 0x112, 0x2, 0x35, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x49, 0x3, 0x2, 0x2, 0x2, 0x8, 0x55, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x5b, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x76, 0x3, 0x2, 0x2, 0x2, 0x14, 0x7c, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x81, 0x3, 0x2, 0x2, 0x2, 0x18, 0xab, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x22, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xe5, 0x3, 0x2, 0x2, 0x2, 0x26, 0xed, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xfe, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x102, 0x3, 0x2, 0x2, 0x2, 0x32, 0x104, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x36, 0x5, 0x4, 0x3, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x2, 
    0x2, 0x3, 0x3a, 0x3, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x33, 0x2, 
    0x2, 0x3c, 0x3d, 0x7, 0x38, 0x2, 0x2, 0x3d, 0x3f, 0x7, 0xf, 0x2, 0x2, 
    0x3e, 0x40, 0x5, 0x6, 0x4, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 0x3, 0x2, 0x2, 0x2, 0x41, 0x43, 
    0x7, 0x10, 0x2, 0x2, 0x42, 0x44, 0x5, 0x8, 0x5, 0x2, 0x43, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x45, 0x46, 0x5, 0xa, 0x6, 0x2, 0x46, 0x47, 0x5, 0x16, 0xc, 
    0x2, 0x47, 0x48, 0x7, 0x34, 0x2, 0x2, 0x48, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4a, 0x7, 0x38, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x15, 0x2, 0x2, 0x4b, 
    0x52, 0x5, 0xe, 0x8, 0x2, 0x4c, 0x4d, 0x7, 0x18, 0x2, 0x2, 0x4d, 0x4e, 
    0x7, 0x38, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x15, 0x2, 0x2, 0x4f, 0x51, 0x5, 
    0xe, 0x8, 0x2, 0x50, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x7, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x56, 0x7, 0x15, 0x2, 0x2, 0x56, 0x57, 0x5, 0x14, 0xb, 0x2, 0x57, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 0x5, 0xc, 0x7, 0x2, 0x59, 0x58, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x22, 0x2, 
    0x2, 0x5f, 0x64, 0x7, 0x38, 0x2, 0x2, 0x60, 0x61, 0x7, 0x18, 0x2, 0x2, 
    0x61, 0x63, 0x7, 0x38, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x68, 0x7, 0x15, 0x2, 0x2, 0x68, 0x69, 0x5, 0xe, 
    0x8, 0x2, 0x69, 0xd, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6e, 0x5, 0x14, 0xb, 
    0x2, 0x6b, 0x6e, 0x5, 0x10, 0x9, 0x2, 0x6c, 0x6e, 0x5, 0x12, 0xa, 0x2, 
    0x6d, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 
    0x7, 0x29, 0x2, 0x2, 0x70, 0x71, 0x7, 0x11, 0x2, 0x2, 0x71, 0x72, 0x5, 
    0x1e, 0x10, 0x2, 0x72, 0x73, 0x7, 0x12, 0x2, 0x2, 0x73, 0x74, 0x7, 0x3, 
    0x2, 0x2, 0x74, 0x75, 0x5, 0x14, 0xb, 0x2, 0x75, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x77, 0x7, 0x4, 0x2, 0x2, 0x77, 0x78, 0x5, 0x14, 0xb, 0x2, 
    0x78, 0x79, 0x7, 0x18, 0x2, 0x2, 0x79, 0x7a, 0x5, 0x14, 0xb, 0x2, 0x7a, 
    0x7b, 0x7, 0x5, 0x2, 0x2, 0x7b, 0x13, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 
    0x9, 0x2, 0x2, 0x2, 0x7d, 0x15, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x80, 0x5, 
    0x18, 0xd, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x17, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x85, 0x5, 0x1a, 0xe, 0x2, 0x85, 0x86, 0x7, 0x6, 0x2, 0x2, 0x86, 
    0x87, 0x5, 0x1e, 0x10, 0x2, 0x87, 0x88, 0x7, 0x16, 0x2, 0x2, 0x88, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x2c, 0x2, 0x2, 0x8a, 0x8b, 0x5, 
    0x1e, 0x10, 0x2, 0x8b, 0x8c, 0x7, 0x2d, 0x2, 0x2, 0x8c, 0x8e, 0x5, 0x16, 
    0xc, 0x2, 0x8d, 0x8f, 0x5, 0x1c, 0xf, 0x2, 0x8e, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 
    0x90, 0x91, 0x7, 0x32, 0x2, 0x2, 0x91, 0xac, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x93, 0x7, 0x2f, 0x2, 0x2, 0x93, 0x94, 0x5, 0x1e, 0x10, 0x2, 0x94, 0x95, 
    0x7, 0x30, 0x2, 0x2, 0x95, 0x96, 0x5, 0x16, 0xc, 0x2, 0x96, 0x97, 0x7, 
    0x31, 0x2, 0x2, 0x97, 0xac, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x5, 0x22, 
    0x12, 0x2, 0x99, 0x9a, 0x7, 0x16, 0x2, 0x2, 0x9a, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0x9c, 0x7, 0x36, 0x2, 0x2, 0x9c, 0x9d, 0x5, 0x1a, 0xe, 0x2, 
    0x9d, 0x9e, 0x7, 0x16, 0x2, 0x2, 0x9e, 0xac, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0xa0, 0x7, 0x37, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x1e, 0x10, 0x2, 0xa1, 0xa2, 
    0x7, 0x16, 0x2, 0x2, 0xa2, 0xac, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 
    0x37, 0x2, 0x2, 0xa4, 0xa5, 0x7, 0x3a, 0x2, 0x2, 0xa5, 0xac, 0x7, 0x16, 
    0x2, 0x2, 0xa6, 0xa8, 0x7, 0x35, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0x1e, 0x10, 
    0x2, 0xa8, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 
    0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xac, 0x7, 0x16, 0x2, 0x2, 0xab, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0xab, 0x89, 0x3, 0x2, 0x2, 0x2, 0xab, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0xab, 0x98, 0x3, 0x2, 0x2, 0x2, 0xab, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0xab, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xac, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xb1, 0x5, 0x32, 0x1a, 0x2, 0xae, 0xb1, 0x5, 0x20, 0x11, 
    0x2, 0xaf, 0xb1, 0x5, 0x26, 0x14, 0x2, 0xb0, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x2e, 0x2, 0x2, 0xb3, 0xb4, 
    0x5, 0x16, 0xc, 0x2, 0xb4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x8, 
    0x10, 0x1, 0x2, 0xb6, 0xb7, 0x9, 0x3, 0x2, 0x2, 0xb7, 0xc1, 0x5, 0x1e, 
    0x10, 0xe, 0xb8, 0xb9, 0x7, 0xf, 0x2, 0x2, 0xb9, 0xba, 0x5, 0x1e, 0x10, 
    0x2, 0xba, 0xbb, 0x7, 0x10, 0x2, 0x2, 0xbb, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xbc, 0xc1, 0x5, 0x28, 0x15, 0x2, 0xbd, 0xc1, 0x5, 0x32, 0x1a, 0x2, 
    0xbe, 0xc1, 0x5, 0x20, 0x11, 0x2, 0xbf, 0xc1, 0x5, 0x22, 0x12, 0x2, 
    0xc0, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xbc, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xc0, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xd6, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0xc3, 0xc, 0xd, 0x2, 0x2, 0xc3, 0xc4, 0x9, 0x4, 
    0x2, 0x2, 0xc4, 0xd5, 0x5, 0x1e, 0x10, 0xe, 0xc5, 0xc6, 0xc, 0xc, 0x2, 
    0x2, 0xc6, 0xc7, 0x9, 0x5, 0x2, 0x2, 0xc7, 0xd5, 0x5, 0x1e, 0x10, 0xd, 
    0xc8, 0xc9, 0xc, 0xb, 0x2, 0x2, 0xc9, 0xca, 0x9, 0x6, 0x2, 0x2, 0xca, 
    0xd5, 0x5, 0x1e, 0x10, 0xc, 0xcb, 0xcc, 0xc, 0xa, 0x2, 0x2, 0xcc, 0xcd, 
    0x9, 0x7, 0x2, 0x2, 0xcd, 0xd5, 0x5, 0x1e, 0x10, 0xb, 0xce, 0xcf, 0xc, 
    0x9, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x1f, 0x2, 0x2, 0xd0, 0xd5, 0x5, 0x1e, 
    0x10, 0xa, 0xd1, 0xd2, 0xc, 0x8, 0x2, 0x2, 0xd2, 0xd3, 0x7, 0x20, 0x2, 
    0x2, 0xd3, 0xd5, 0x5, 0x1e, 0x10, 0x9, 0xd4, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd7, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x5, 0x32, 0x1a, 
    0x2, 0xda, 0xdb, 0x7, 0x11, 0x2, 0x2, 0xdb, 0xdc, 0x5, 0x1e, 0x10, 0x2, 
    0xdc, 0xdd, 0x7, 0x12, 0x2, 0x2, 0xdd, 0x21, 0x3, 0x2, 0x2, 0x2, 0xde, 
    0xdf, 0x5, 0x32, 0x1a, 0x2, 0xdf, 0xe1, 0x7, 0xf, 0x2, 0x2, 0xe0, 0xe2, 
    0x5, 0x24, 0x13, 0x2, 0xe1, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x10, 
    0x2, 0x2, 0xe4, 0x23, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xea, 0x5, 0x1e, 0x10, 
    0x2, 0xe6, 0xe7, 0x7, 0x18, 0x2, 0x2, 0xe7, 0xe9, 0x5, 0x1e, 0x10, 0x2, 
    0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xec, 0x3, 0x2, 0x2, 0x2, 0xea, 
    0xe8, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0xec, 0xea, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x5, 
    0x32, 0x1a, 0x2, 0xee, 0xef, 0x7, 0x17, 0x2, 0x2, 0xef, 0xf0, 0x9, 0x8, 
    0x2, 0x2, 0xf0, 0x27, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf7, 0x5, 0x30, 0x19, 
    0x2, 0xf2, 0xf7, 0x5, 0x26, 0x14, 0x2, 0xf3, 0xf7, 0x5, 0x2a, 0x16, 
    0x2, 0xf4, 0xf7, 0x5, 0x2c, 0x17, 0x2, 0xf5, 0xf7, 0x5, 0x2e, 0x18, 
    0x2, 0xf6, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf6, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x29, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 
    0x7, 0xd, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x38, 0x2, 0x2, 0xfa, 0xfb, 0x7, 
    0xd, 0x2, 0x2, 0xfb, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x39, 
    0x2, 0x2, 0xfd, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0x39, 0x2, 
    0x2, 0xff, 0x100, 0x7, 0x17, 0x2, 0x2, 0x100, 0x101, 0x7, 0x39, 0x2, 
    0x2, 0x101, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x9, 0x9, 0x2, 0x2, 
    0x103, 0x31, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x7, 0x38, 0x2, 0x2, 
    0x105, 0x33, 0x3, 0x2, 0x2, 0x2, 0x14, 0x37, 0x3f, 0x43, 0x52, 0x5b, 
    0x64, 0x6d, 0x81, 0x8e, 0xa8, 0xab, 0xb0, 0xc0, 0xd4, 0xd6, 0xe1, 0xea, 
    0xf6, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
