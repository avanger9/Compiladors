
// Generated from Calc.g4 by ANTLR 4.7.1



#include "CalcParser.h"


using namespace antlrcpp;
using namespace antlr4;

CalcParser::CalcParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

CalcParser::~CalcParser() {
  delete _interpreter;
}

std::string CalcParser::getGrammarFileName() const {
  return "Calc.g4";
}

const std::vector<std::string>& CalcParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& CalcParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

CalcParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalcParser::ProgContext::EOF() {
  return getToken(CalcParser::EOF, 0);
}

std::vector<CalcParser::StatContext *> CalcParser::ProgContext::stat() {
  return getRuleContexts<CalcParser::StatContext>();
}

CalcParser::StatContext* CalcParser::ProgContext::stat(size_t i) {
  return getRuleContext<CalcParser::StatContext>(i);
}


size_t CalcParser::ProgContext::getRuleIndex() const {
  return CalcParser::RuleProg;
}


CalcParser::ProgContext* CalcParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, CalcParser::RuleProg);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(7); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(6);
      stat();
      setState(9); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << CalcParser::ID)
      | (1ULL << CalcParser::INT)
      | (1ULL << CalcParser::NEWLINE))) != 0));
    setState(11);
    match(CalcParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

CalcParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

CalcParser::ExprContext* CalcParser::StatContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::StatContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

tree::TerminalNode* CalcParser::StatContext::ID() {
  return getToken(CalcParser::ID, 0);
}


size_t CalcParser::StatContext::getRuleIndex() const {
  return CalcParser::RuleStat;
}


CalcParser::StatContext* CalcParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, CalcParser::RuleStat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(22);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(13);
      expr(0);
      setState(14);
      match(CalcParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(16);
      match(CalcParser::ID);
      setState(17);
      match(CalcParser::T__0);
      setState(18);
      expr(0);
      setState(19);
      match(CalcParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(21);
      match(CalcParser::NEWLINE);
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

CalcParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalcParser::ExprContext::INT() {
  return getToken(CalcParser::INT, 0);
}

tree::TerminalNode* CalcParser::ExprContext::ID() {
  return getToken(CalcParser::ID, 0);
}

std::vector<CalcParser::ExprContext *> CalcParser::ExprContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::ExprContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::ExprContext::MUL() {
  return getToken(CalcParser::MUL, 0);
}

tree::TerminalNode* CalcParser::ExprContext::DIV() {
  return getToken(CalcParser::DIV, 0);
}

tree::TerminalNode* CalcParser::ExprContext::ADD() {
  return getToken(CalcParser::ADD, 0);
}

tree::TerminalNode* CalcParser::ExprContext::MIN() {
  return getToken(CalcParser::MIN, 0);
}


size_t CalcParser::ExprContext::getRuleIndex() const {
  return CalcParser::RuleExpr;
}



CalcParser::ExprContext* CalcParser::expr() {
   return expr(0);
}

CalcParser::ExprContext* CalcParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalcParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CalcParser::ExprContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CalcParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(27);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcParser::INT: {
        setState(25);
        match(CalcParser::INT);
        break;
      }

      case CalcParser::ID: {
        setState(26);
        match(CalcParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(37);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(35);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(29);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(30);
          _la = _input->LA(1);
          if (!(_la == CalcParser::MUL

          || _la == CalcParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(31);
          expr(5);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(32);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(33);
          _la = _input->LA(1);
          if (!(_la == CalcParser::ADD

          || _la == CalcParser::MIN)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(34);
          expr(4);
          break;
        }

        } 
      }
      setState(39);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CalcParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalcParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> CalcParser::_decisionToDFA;
atn::PredictionContextCache CalcParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN CalcParser::_atn;
std::vector<uint16_t> CalcParser::_serializedATN;

std::vector<std::string> CalcParser::_ruleNames = {
  "prog", "stat", "expr"
};

std::vector<std::string> CalcParser::_literalNames = {
  "", "'='", "'*'", "'/'", "'+'", "'-'"
};

std::vector<std::string> CalcParser::_symbolicNames = {
  "", "", "MUL", "DIV", "ADD", "MIN", "ID", "INT", "NEWLINE", "WS"
};

dfa::Vocabulary CalcParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> CalcParser::_tokenNames;

CalcParser::Initializer::Initializer() {
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
    0x3, 0xb, 0x2b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x6, 0x2, 0xa, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xb, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x1e, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x26, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x29, 0xb, 0x4, 0x3, 0x4, 0x2, 0x3, 0x6, 0x5, 0x2, 0x4, 0x6, 
    0x2, 0x4, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0x6, 0x7, 0x2, 0x2d, 0x2, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xa, 0x5, 0x4, 0x3, 0x2, 0x9, 0x8, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0xb, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 
    0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x3, 0x2, 0x2, 0x2, 0xd, 0xe, 0x7, 0x2, 
    0x2, 0x3, 0xe, 0x3, 0x3, 0x2, 0x2, 0x2, 0xf, 0x10, 0x5, 0x6, 0x4, 0x2, 
    0x10, 0x11, 0x7, 0xa, 0x2, 0x2, 0x11, 0x19, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x13, 0x7, 0x8, 0x2, 0x2, 0x13, 0x14, 0x7, 0x3, 0x2, 0x2, 0x14, 0x15, 
    0x5, 0x6, 0x4, 0x2, 0x15, 0x16, 0x7, 0xa, 0x2, 0x2, 0x16, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x17, 0x19, 0x7, 0xa, 0x2, 0x2, 0x18, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x12, 0x3, 0x2, 0x2, 0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0x19, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x8, 0x4, 0x1, 0x2, 
    0x1b, 0x1e, 0x7, 0x9, 0x2, 0x2, 0x1c, 0x1e, 0x7, 0x8, 0x2, 0x2, 0x1d, 
    0x1a, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0xc, 0x6, 0x2, 0x2, 0x20, 0x21, 0x9, 
    0x2, 0x2, 0x2, 0x21, 0x26, 0x5, 0x6, 0x4, 0x7, 0x22, 0x23, 0xc, 0x5, 
    0x2, 0x2, 0x23, 0x24, 0x9, 0x3, 0x2, 0x2, 0x24, 0x26, 0x5, 0x6, 0x4, 
    0x6, 0x25, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x25, 0x22, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x29, 0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 
    0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x7, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 
    0x3, 0x2, 0x2, 0x2, 0x7, 0xb, 0x18, 0x1d, 0x25, 0x27, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

CalcParser::Initializer CalcParser::_init;
