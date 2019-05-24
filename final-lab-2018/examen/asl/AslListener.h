
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AslParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AslParser.
 */
class  AslListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(AslParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(AslParser::ProgramContext *ctx) = 0;

  virtual void enterFunction(AslParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(AslParser::FunctionContext *ctx) = 0;

  virtual void enterFuncParams(AslParser::FuncParamsContext *ctx) = 0;
  virtual void exitFuncParams(AslParser::FuncParamsContext *ctx) = 0;

  virtual void enterFuncType(AslParser::FuncTypeContext *ctx) = 0;
  virtual void exitFuncType(AslParser::FuncTypeContext *ctx) = 0;

  virtual void enterDeclarations(AslParser::DeclarationsContext *ctx) = 0;
  virtual void exitDeclarations(AslParser::DeclarationsContext *ctx) = 0;

  virtual void enterVariable_decl(AslParser::Variable_declContext *ctx) = 0;
  virtual void exitVariable_decl(AslParser::Variable_declContext *ctx) = 0;

  virtual void enterTypeR(AslParser::TypeRContext *ctx) = 0;
  virtual void exitTypeR(AslParser::TypeRContext *ctx) = 0;

  virtual void enterArray(AslParser::ArrayContext *ctx) = 0;
  virtual void exitArray(AslParser::ArrayContext *ctx) = 0;

  virtual void enterPair(AslParser::PairContext *ctx) = 0;
  virtual void exitPair(AslParser::PairContext *ctx) = 0;

  virtual void enterType(AslParser::TypeContext *ctx) = 0;
  virtual void exitType(AslParser::TypeContext *ctx) = 0;

  virtual void enterStatements(AslParser::StatementsContext *ctx) = 0;
  virtual void exitStatements(AslParser::StatementsContext *ctx) = 0;

  virtual void enterAssignStmt(AslParser::AssignStmtContext *ctx) = 0;
  virtual void exitAssignStmt(AslParser::AssignStmtContext *ctx) = 0;

  virtual void enterIfStmt(AslParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(AslParser::IfStmtContext *ctx) = 0;

  virtual void enterWhileStmt(AslParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(AslParser::WhileStmtContext *ctx) = 0;

  virtual void enterProcCall(AslParser::ProcCallContext *ctx) = 0;
  virtual void exitProcCall(AslParser::ProcCallContext *ctx) = 0;

  virtual void enterReadStmt(AslParser::ReadStmtContext *ctx) = 0;
  virtual void exitReadStmt(AslParser::ReadStmtContext *ctx) = 0;

  virtual void enterWriteExpr(AslParser::WriteExprContext *ctx) = 0;
  virtual void exitWriteExpr(AslParser::WriteExprContext *ctx) = 0;

  virtual void enterWriteString(AslParser::WriteStringContext *ctx) = 0;
  virtual void exitWriteString(AslParser::WriteStringContext *ctx) = 0;

  virtual void enterRetFunc(AslParser::RetFuncContext *ctx) = 0;
  virtual void exitRetFunc(AslParser::RetFuncContext *ctx) = 0;

  virtual void enterLeft_expr(AslParser::Left_exprContext *ctx) = 0;
  virtual void exitLeft_expr(AslParser::Left_exprContext *ctx) = 0;

  virtual void enterElseStat(AslParser::ElseStatContext *ctx) = 0;
  virtual void exitElseStat(AslParser::ElseStatContext *ctx) = 0;

  virtual void enterParExpr(AslParser::ParExprContext *ctx) = 0;
  virtual void exitParExpr(AslParser::ParExprContext *ctx) = 0;

  virtual void enterUnaryExpr(AslParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(AslParser::UnaryExprContext *ctx) = 0;

  virtual void enterFuncExpr(AslParser::FuncExprContext *ctx) = 0;
  virtual void exitFuncExpr(AslParser::FuncExprContext *ctx) = 0;

  virtual void enterArrayExpr(AslParser::ArrayExprContext *ctx) = 0;
  virtual void exitArrayExpr(AslParser::ArrayExprContext *ctx) = 0;

  virtual void enterBooleanExpr(AslParser::BooleanExprContext *ctx) = 0;
  virtual void exitBooleanExpr(AslParser::BooleanExprContext *ctx) = 0;

  virtual void enterAtomExpr(AslParser::AtomExprContext *ctx) = 0;
  virtual void exitAtomExpr(AslParser::AtomExprContext *ctx) = 0;

  virtual void enterExprIdent(AslParser::ExprIdentContext *ctx) = 0;
  virtual void exitExprIdent(AslParser::ExprIdentContext *ctx) = 0;

  virtual void enterArithmetic(AslParser::ArithmeticContext *ctx) = 0;
  virtual void exitArithmetic(AslParser::ArithmeticContext *ctx) = 0;

  virtual void enterRelational(AslParser::RelationalContext *ctx) = 0;
  virtual void exitRelational(AslParser::RelationalContext *ctx) = 0;

  virtual void enterArrayConstruct(AslParser::ArrayConstructContext *ctx) = 0;
  virtual void exitArrayConstruct(AslParser::ArrayConstructContext *ctx) = 0;

  virtual void enterFuncConstruct(AslParser::FuncConstructContext *ctx) = 0;
  virtual void exitFuncConstruct(AslParser::FuncConstructContext *ctx) = 0;

  virtual void enterExprFunc(AslParser::ExprFuncContext *ctx) = 0;
  virtual void exitExprFunc(AslParser::ExprFuncContext *ctx) = 0;

  virtual void enterPairExpr(AslParser::PairExprContext *ctx) = 0;
  virtual void exitPairExpr(AslParser::PairExprContext *ctx) = 0;

  virtual void enterAtom(AslParser::AtomContext *ctx) = 0;
  virtual void exitAtom(AslParser::AtomContext *ctx) = 0;

  virtual void enterChart(AslParser::ChartContext *ctx) = 0;
  virtual void exitChart(AslParser::ChartContext *ctx) = 0;

  virtual void enterValue(AslParser::ValueContext *ctx) = 0;
  virtual void exitValue(AslParser::ValueContext *ctx) = 0;

  virtual void enterFval(AslParser::FvalContext *ctx) = 0;
  virtual void exitFval(AslParser::FvalContext *ctx) = 0;

  virtual void enterBoolExpr(AslParser::BoolExprContext *ctx) = 0;
  virtual void exitBoolExpr(AslParser::BoolExprContext *ctx) = 0;

  virtual void enterIdent(AslParser::IdentContext *ctx) = 0;
  virtual void exitIdent(AslParser::IdentContext *ctx) = 0;


};

