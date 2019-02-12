
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

tree::TerminalNode* ExprParser::EContext::PL() {
  return getToken(ExprParser::PL, 0);
}

std::vector<ExprParser::EContext *> ExprParser::EContext::e() {
  return getRuleContexts<ExprParser::EContext>();
}

ExprParser::EContext* ExprParser::EContext::e(size_t i) {
  return getRuleContext<ExprParser::EContext>(i);
}

tree::TerminalNode* ExprParser::EContext::PR() {
  return getToken(ExprParser::PR, 0);
}

tree::TerminalNode* ExprParser::EContext::INT() {
  return getToken(ExprParser::INT, 0);
}

tree::TerminalNode* ExprParser::EContext::MULT() {
  return getToken(ExprParser::MULT, 0);
}

tree::TerminalNode* ExprParser::EContext::DIV() {
  return getToken(ExprParser::DIV, 0);
}

tree::TerminalNode* ExprParser::EContext::ADD() {
  return getToken(ExprParser::ADD, 0);
}

tree::TerminalNode* ExprParser::EContext::MINUS() {
  return getToken(ExprParser::MINUS, 0);
}


size_t ExprParser::EContext::getRuleIndex() const {
  return ExprParser::RuleE;
}

void ExprParser::EContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterE(this);
}

void ExprParser::EContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ExprListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitE(this);
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

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(13);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::PL: {
        setState(8);
        match(ExprParser::PL);
        setState(9);
        e(0);
        setState(10);
        match(ExprParser::PR);
        break;
      }

      case ExprParser::INT: {
        setState(12);
        match(ExprParser::INT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(23);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(21);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleE);
          setState(15);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(16);
          dynamic_cast<EContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ExprParser::MULT

          || _la == ExprParser::DIV)) {
            dynamic_cast<EContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(17);
          e(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleE);
          setState(18);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(19);
          dynamic_cast<EContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == ExprParser::ADD

          || _la == ExprParser::MINUS)) {
            dynamic_cast<EContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(20);
          e(3);
          break;
        }

        } 
      }
      setState(25);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
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
  "", "'*'", "'+'", "'-'", "'/'", "'('", "')'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "MULT", "ADD", "MINUS", "DIV", "PL", "PR", "INT", "WS"
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
    0x3, 0xa, 0x1d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x10, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x18, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1b, 
    0xb, 0x3, 0x3, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x4, 0x2, 0x4, 0x4, 0x2, 
    0x3, 0x3, 0x6, 0x6, 0x3, 0x2, 0x4, 0x5, 0x2, 0x1d, 0x2, 0x6, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x5, 0x4, 0x3, 0x2, 
    0x7, 0x8, 0x7, 0x2, 0x2, 0x3, 0x8, 0x3, 0x3, 0x2, 0x2, 0x2, 0x9, 0xa, 
    0x8, 0x3, 0x1, 0x2, 0xa, 0xb, 0x7, 0x7, 0x2, 0x2, 0xb, 0xc, 0x5, 0x4, 
    0x3, 0x2, 0xc, 0xd, 0x7, 0x8, 0x2, 0x2, 0xd, 0x10, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x10, 0x7, 0x9, 0x2, 0x2, 0xf, 0x9, 0x3, 0x2, 0x2, 0x2, 0xf, 0xe, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x19, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0xc, 
    0x5, 0x2, 0x2, 0x12, 0x13, 0x9, 0x2, 0x2, 0x2, 0x13, 0x18, 0x5, 0x4, 
    0x3, 0x6, 0x14, 0x15, 0xc, 0x4, 0x2, 0x2, 0x15, 0x16, 0x9, 0x3, 0x2, 
    0x2, 0x16, 0x18, 0x5, 0x4, 0x3, 0x5, 0x17, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x17, 0x14, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x19, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x5, 0xf, 0x17, 
    0x19, 
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
