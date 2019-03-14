
// Generated from Expr.g4 by ANTLR 4.7.1


#include "ExprListener.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SContext ------------------------------------------------------------------

ExprParser::SContext::SContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::EContext* ExprParser::SContext::e() {
  return getRuleContext<ExprParser::EContext>(0);
}

tree::TerminalNode* ExprParser::SContext::EOF() {
  return getToken(ExprParser::EOF, 0);
}


size_t ExprParser::SContext::getRuleIndex() const {
  return ExprParser::RuleS;
}

void ExprParser::SContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterS(this);
}

void ExprParser::SContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitS(this);
}

ExprParser::SContext* ExprParser::s() {
  SContext *_localctx = _tracker.createInstance<SContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleS);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    e(0);
    setState(5);
    match(ExprParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EContext ------------------------------------------------------------------

ExprParser::EContext::EContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::EContext::getRuleIndex() const {
  return ExprParser::RuleE;
}

void ExprParser::EContext::copyFrom(EContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProdContext ------------------------------------------------------------------

std::vector<ExprParser::EContext *> ExprParser::ProdContext::e() {
  return getRuleContexts<ExprParser::EContext>();
}

ExprParser::EContext* ExprParser::ProdContext::e(size_t i) {
  return getRuleContext<ExprParser::EContext>(i);
}

tree::TerminalNode* ExprParser::ProdContext::MULT() {
  return getToken(ExprParser::MULT, 0);
}

ExprParser::ProdContext::ProdContext(EContext *ctx) { copyFrom(ctx); }

void ExprParser::ProdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProd(this);
}
void ExprParser::ProdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProd(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ValueContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::ValueContext::ValueContext(EContext *ctx) { copyFrom(ctx); }

void ExprParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}
void ExprParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}
//----------------- PlusContext ------------------------------------------------------------------

std::vector<ExprParser::EContext *> ExprParser::PlusContext::e() {
  return getRuleContexts<ExprParser::EContext>();
}

ExprParser::EContext* ExprParser::PlusContext::e(size_t i) {
  return getRuleContext<ExprParser::EContext>(i);
}

tree::TerminalNode* ExprParser::PlusContext::ADD() {
  return getToken(ExprParser::ADD, 0);
}

ExprParser::PlusContext::PlusContext(EContext *ctx) { copyFrom(ctx); }

void ExprParser::PlusContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlus(this);
}
void ExprParser::PlusContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlus(this);
}

ExprParser::EContext* ExprParser::e() {
   return e(0);
}

ExprParser::EContext* ExprParser::e(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::EContext *_localctx = _tracker.createInstance<EContext>(_ctx, parentState);
  ExprParser::EContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ExprParser::RuleE, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    _localctx = _tracker.createInstance<ValueContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

    setState(8);
    match(ExprParser::INT);
    _ctx->stop = _input->LT(-1);
    setState(18);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(16);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ProdContext>(_tracker.createInstance<EContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleE);
          setState(10);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(11);
          match(ExprParser::MULT);
          setState(12);
          e(4);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusContext>(_tracker.createInstance<EContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleE);
          setState(13);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(14);
          match(ExprParser::ADD);
          setState(15);
          e(3);
          break;
        }

        } 
      }
      setState(20);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return eSempred(dynamic_cast<EContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::eSempred(EContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "s", "e"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'*'", "'+'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "MULT", "ADD", "INT", "WS"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
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
    0x3, 0x6, 0x18, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x13, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x16, 0xb, 0x3, 0x3, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x4, 0x2, 
    0x2, 0x2, 0x17, 0x2, 0x6, 0x3, 0x2, 0x2, 0x2, 0x4, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x7, 0x5, 0x4, 0x3, 0x2, 0x7, 0x8, 0x7, 0x2, 0x2, 0x3, 0x8, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x9, 0xa, 0x8, 0x3, 0x1, 0x2, 0xa, 0xb, 0x7, 
    0x5, 0x2, 0x2, 0xb, 0x14, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0xc, 0x5, 0x2, 
    0x2, 0xd, 0xe, 0x7, 0x3, 0x2, 0x2, 0xe, 0x13, 0x5, 0x4, 0x3, 0x6, 0xf, 
    0x10, 0xc, 0x4, 0x2, 0x2, 0x10, 0x11, 0x7, 0x4, 0x2, 0x2, 0x11, 0x13, 
    0x5, 0x4, 0x3, 0x5, 0x12, 0xc, 0x3, 0x2, 0x2, 0x2, 0x12, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x13, 0x16, 0x3, 0x2, 0x2, 0x2, 0x14, 0x12, 0x3, 0x2, 0x2, 
    0x2, 0x14, 0x15, 0x3, 0x2, 0x2, 0x2, 0x15, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x12, 0x14, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
