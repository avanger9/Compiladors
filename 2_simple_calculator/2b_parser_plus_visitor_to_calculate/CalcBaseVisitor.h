
// Generated from Calc.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "CalcVisitor.h"


/**
 * This class provides an empty implementation of CalcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CalcBaseVisitor : public CalcVisitor {
public:

  virtual antlrcpp::Any visitProg(CalcParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintExpr(CalcParser::PrintExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign(CalcParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlank(CalcParser::BlankContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesis(CalcParser::ParenthesisContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNot(CalcParser::NotContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlusMinus(CalcParser::PlusMinusContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOr(CalcParser::OrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnd(CalcParser::AndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProdDiv(CalcParser::ProdDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLtgt(CalcParser::LtgtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitId(CalcParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(CalcParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }


};

