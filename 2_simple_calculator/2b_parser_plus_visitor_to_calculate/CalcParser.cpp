
// Generated from Calc.g4 by ANTLR 4.7.1


#include "CalcVisitor.h"

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

antlrcpp::Any CalcParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
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
      ((1ULL << _la) & ((1ULL << CalcParser::PL)
      | (1ULL << CalcParser::NOT)
      | (1ULL << CalcParser::ID)
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


size_t CalcParser::StatContext::getRuleIndex() const {
  return CalcParser::RuleStat;
}

void CalcParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlankContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::BlankContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::BlankContext::BlankContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::BlankContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitBlank(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::PrintExprContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::PrintExprContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::PrintExprContext::PrintExprContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::AssignContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::ExprContext* CalcParser::AssignContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::AssignContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
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
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::PrintExprContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(13);
      expr(0);
      setState(14);
      match(CalcParser::NEWLINE);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::AssignContext>(_localctx));
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
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<CalcParser::BlankContext>(_localctx));
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


size_t CalcParser::ExprContext::getRuleIndex() const {
  return CalcParser::RuleExpr;
}

void CalcParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::ParenthesisContext::PL() {
  return getToken(CalcParser::PL, 0);
}

CalcParser::ExprContext* CalcParser::ParenthesisContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::ParenthesisContext::PR() {
  return getToken(CalcParser::PR, 0);
}

CalcParser::ParenthesisContext::ParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::NotContext::NOT() {
  return getToken(CalcParser::NOT, 0);
}

CalcParser::ExprContext* CalcParser::NotContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

CalcParser::NotContext::NotContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::NotContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitNot(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusMinusContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::PlusMinusContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::PlusMinusContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::PlusMinusContext::ADD() {
  return getToken(CalcParser::ADD, 0);
}

tree::TerminalNode* CalcParser::PlusMinusContext::MIN() {
  return getToken(CalcParser::MIN, 0);
}

CalcParser::PlusMinusContext::PlusMinusContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::PlusMinusContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPlusMinus(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::OrContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::OrContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::OrContext::OR() {
  return getToken(CalcParser::OR, 0);
}

CalcParser::OrContext::OrContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::OrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::AndContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::AndContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::AndContext::AND() {
  return getToken(CalcParser::AND, 0);
}

CalcParser::AndContext::AndContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::AndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitAnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ProdDivContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::ProdDivContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::ProdDivContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::ProdDivContext::MUL() {
  return getToken(CalcParser::MUL, 0);
}

tree::TerminalNode* CalcParser::ProdDivContext::DIV() {
  return getToken(CalcParser::DIV, 0);
}

CalcParser::ProdDivContext::ProdDivContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::ProdDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitProdDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LtgtContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::LtgtContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::LtgtContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::LtgtContext::LT() {
  return getToken(CalcParser::LT, 0);
}

tree::TerminalNode* CalcParser::LtgtContext::GT() {
  return getToken(CalcParser::GT, 0);
}

tree::TerminalNode* CalcParser::LtgtContext::EQ() {
  return getToken(CalcParser::EQ, 0);
}

CalcParser::LtgtContext::LtgtContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::LtgtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitLtgt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IdContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::IdContext::IdContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IntContext::INT() {
  return getToken(CalcParser::INT, 0);
}

CalcParser::IntContext::IntContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any CalcParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
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
    setState(33);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcParser::PL: {
        _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(25);
        match(CalcParser::PL);
        setState(26);
        expr(0);
        setState(27);
        match(CalcParser::PR);
        break;
      }

      case CalcParser::NOT: {
        _localctx = _tracker.createInstance<NotContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(29);
        match(CalcParser::NOT);
        setState(30);
        expr(8);
        break;
      }

      case CalcParser::INT: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(31);
        match(CalcParser::INT);
        break;
      }

      case CalcParser::ID: {
        _localctx = _tracker.createInstance<IdContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(32);
        match(CalcParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(52);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(50);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ProdDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(35);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(36);
          _la = _input->LA(1);
          if (!(_la == CalcParser::MUL

          || _la == CalcParser::DIV)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(37);
          expr(8);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(38);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(39);
          _la = _input->LA(1);
          if (!(_la == CalcParser::ADD

          || _la == CalcParser::MIN)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(40);
          expr(7);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<LtgtContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(41);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(42);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << CalcParser::LT)
            | (1ULL << CalcParser::GT)
            | (1ULL << CalcParser::EQ))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(43);
          expr(6);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<OrContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(44);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(45);
          match(CalcParser::OR);
          setState(46);
          expr(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AndContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(47);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(48);
          match(CalcParser::AND);
          setState(49);
          expr(4);
          break;
        }

        } 
      }
      setState(54);
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
    case 0: return precpred(_ctx, 7);
    case 1: return precpred(_ctx, 6);
    case 2: return precpred(_ctx, 5);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

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
  "", "'='", "'*'", "'/'", "'+'", "'-'", "'('", "')'", "'!'", "'|'", "'&'", 
  "'<'", "'>'", "'=='"
};

std::vector<std::string> CalcParser::_symbolicNames = {
  "", "", "MUL", "DIV", "ADD", "MIN", "PL", "PR", "NOT", "OR", "AND", "LT", 
  "GT", "EQ", "ID", "INT", "NEWLINE", "WS"
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
    0x3, 0x13, 0x3a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x6, 0x2, 0xa, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xb, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x19, 0xa, 0x3, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x24, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x35, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x38, 0xb, 0x4, 0x3, 0x4, 0x2, 0x3, 0x6, 0x5, 0x2, 
    0x4, 0x6, 0x2, 0x5, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 0x6, 0x7, 0x3, 0x2, 
    0xd, 0xf, 0x2, 0x41, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4, 0x18, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x23, 0x3, 0x2, 0x2, 0x2, 0x8, 0xa, 0x5, 0x4, 0x3, 0x2, 
    0x9, 0x8, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0xb, 0xc, 0x3, 0x2, 0x2, 0x2, 0xc, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0xd, 0xe, 0x7, 0x2, 0x2, 0x3, 0xe, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0xf, 0x10, 0x5, 0x6, 0x4, 0x2, 0x10, 0x11, 0x7, 0x12, 0x2, 0x2, 0x11, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0x12, 0x13, 0x7, 0x10, 0x2, 0x2, 0x13, 0x14, 
    0x7, 0x3, 0x2, 0x2, 0x14, 0x15, 0x5, 0x6, 0x4, 0x2, 0x15, 0x16, 0x7, 
    0x12, 0x2, 0x2, 0x16, 0x19, 0x3, 0x2, 0x2, 0x2, 0x17, 0x19, 0x7, 0x12, 
    0x2, 0x2, 0x18, 0xf, 0x3, 0x2, 0x2, 0x2, 0x18, 0x12, 0x3, 0x2, 0x2, 
    0x2, 0x18, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x1a, 0x1b, 0x8, 0x4, 0x1, 0x2, 0x1b, 0x1c, 0x7, 0x8, 0x2, 0x2, 0x1c, 
    0x1d, 0x5, 0x6, 0x4, 0x2, 0x1d, 0x1e, 0x7, 0x9, 0x2, 0x2, 0x1e, 0x24, 
    0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 0xa, 0x2, 0x2, 0x20, 0x24, 0x5, 
    0x6, 0x4, 0xa, 0x21, 0x24, 0x7, 0x11, 0x2, 0x2, 0x22, 0x24, 0x7, 0x10, 
    0x2, 0x2, 0x23, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x23, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x22, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x36, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0xc, 0x9, 0x2, 0x2, 0x26, 
    0x27, 0x9, 0x2, 0x2, 0x2, 0x27, 0x35, 0x5, 0x6, 0x4, 0xa, 0x28, 0x29, 
    0xc, 0x8, 0x2, 0x2, 0x29, 0x2a, 0x9, 0x3, 0x2, 0x2, 0x2a, 0x35, 0x5, 
    0x6, 0x4, 0x9, 0x2b, 0x2c, 0xc, 0x7, 0x2, 0x2, 0x2c, 0x2d, 0x9, 0x4, 
    0x2, 0x2, 0x2d, 0x35, 0x5, 0x6, 0x4, 0x8, 0x2e, 0x2f, 0xc, 0x6, 0x2, 
    0x2, 0x2f, 0x30, 0x7, 0xb, 0x2, 0x2, 0x30, 0x35, 0x5, 0x6, 0x4, 0x7, 
    0x31, 0x32, 0xc, 0x5, 0x2, 0x2, 0x32, 0x33, 0x7, 0xc, 0x2, 0x2, 0x33, 
    0x35, 0x5, 0x6, 0x4, 0x6, 0x34, 0x25, 0x3, 0x2, 0x2, 0x2, 0x34, 0x28, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x34, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x31, 0x3, 0x2, 0x2, 0x2, 0x35, 0x38, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x37, 0x7, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x7, 0xb, 0x18, 0x23, 0x34, 0x36, 
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
