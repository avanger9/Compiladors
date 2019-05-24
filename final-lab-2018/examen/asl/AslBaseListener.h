
// Generated from Asl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "AslListener.h"


/**
 * This class provides an empty implementation of AslListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AslBaseListener : public AslListener {
public:

  virtual void enterProgram(AslParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(AslParser::ProgramContext * /*ctx*/) override { }

  virtual void enterFunction(AslParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(AslParser::FunctionContext * /*ctx*/) override { }

  virtual void enterFuncParams(AslParser::FuncParamsContext * /*ctx*/) override { }
  virtual void exitFuncParams(AslParser::FuncParamsContext * /*ctx*/) override { }

  virtual void enterFuncType(AslParser::FuncTypeContext * /*ctx*/) override { }
  virtual void exitFuncType(AslParser::FuncTypeContext * /*ctx*/) override { }

  virtual void enterDeclarations(AslParser::DeclarationsContext * /*ctx*/) override { }
  virtual void exitDeclarations(AslParser::DeclarationsContext * /*ctx*/) override { }

  virtual void enterVariable_decl(AslParser::Variable_declContext * /*ctx*/) override { }
  virtual void exitVariable_decl(AslParser::Variable_declContext * /*ctx*/) override { }

  virtual void enterTypeR(AslParser::TypeRContext * /*ctx*/) override { }
  virtual void exitTypeR(AslParser::TypeRContext * /*ctx*/) override { }

  virtual void enterArray(AslParser::ArrayContext * /*ctx*/) override { }
  virtual void exitArray(AslParser::ArrayContext * /*ctx*/) override { }

  virtual void enterPair(AslParser::PairContext * /*ctx*/) override { }
  virtual void exitPair(AslParser::PairContext * /*ctx*/) override { }

  virtual void enterType(AslParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(AslParser::TypeContext * /*ctx*/) override { }

  virtual void enterStatements(AslParser::StatementsContext * /*ctx*/) override { }
  virtual void exitStatements(AslParser::StatementsContext * /*ctx*/) override { }

  virtual void enterAssignStmt(AslParser::AssignStmtContext * /*ctx*/) override { }
  virtual void exitAssignStmt(AslParser::AssignStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(AslParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(AslParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(AslParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(AslParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterProcCall(AslParser::ProcCallContext * /*ctx*/) override { }
  virtual void exitProcCall(AslParser::ProcCallContext * /*ctx*/) override { }

  virtual void enterReadStmt(AslParser::ReadStmtContext * /*ctx*/) override { }
  virtual void exitReadStmt(AslParser::ReadStmtContext * /*ctx*/) override { }

  virtual void enterWriteExpr(AslParser::WriteExprContext * /*ctx*/) override { }
  virtual void exitWriteExpr(AslParser::WriteExprContext * /*ctx*/) override { }

  virtual void enterWriteString(AslParser::WriteStringContext * /*ctx*/) override { }
  virtual void exitWriteString(AslParser::WriteStringContext * /*ctx*/) override { }

  virtual void enterRetFunc(AslParser::RetFuncContext * /*ctx*/) override { }
  virtual void exitRetFunc(AslParser::RetFuncContext * /*ctx*/) override { }

  virtual void enterLeft_expr(AslParser::Left_exprContext * /*ctx*/) override { }
  virtual void exitLeft_expr(AslParser::Left_exprContext * /*ctx*/) override { }

  virtual void enterElseStat(AslParser::ElseStatContext * /*ctx*/) override { }
  virtual void exitElseStat(AslParser::ElseStatContext * /*ctx*/) override { }

  virtual void enterParExpr(AslParser::ParExprContext * /*ctx*/) override { }
  virtual void exitParExpr(AslParser::ParExprContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(AslParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(AslParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterFuncExpr(AslParser::FuncExprContext * /*ctx*/) override { }
  virtual void exitFuncExpr(AslParser::FuncExprContext * /*ctx*/) override { }

  virtual void enterArrayExpr(AslParser::ArrayExprContext * /*ctx*/) override { }
  virtual void exitArrayExpr(AslParser::ArrayExprContext * /*ctx*/) override { }

  virtual void enterBooleanExpr(AslParser::BooleanExprContext * /*ctx*/) override { }
  virtual void exitBooleanExpr(AslParser::BooleanExprContext * /*ctx*/) override { }

  virtual void enterAtomExpr(AslParser::AtomExprContext * /*ctx*/) override { }
  virtual void exitAtomExpr(AslParser::AtomExprContext * /*ctx*/) override { }

  virtual void enterExprIdent(AslParser::ExprIdentContext * /*ctx*/) override { }
  virtual void exitExprIdent(AslParser::ExprIdentContext * /*ctx*/) override { }

  virtual void enterArithmetic(AslParser::ArithmeticContext * /*ctx*/) override { }
  virtual void exitArithmetic(AslParser::ArithmeticContext * /*ctx*/) override { }

  virtual void enterRelational(AslParser::RelationalContext * /*ctx*/) override { }
  virtual void exitRelational(AslParser::RelationalContext * /*ctx*/) override { }

  virtual void enterArrayConstruct(AslParser::ArrayConstructContext * /*ctx*/) override { }
  virtual void exitArrayConstruct(AslParser::ArrayConstructContext * /*ctx*/) override { }

  virtual void enterFuncConstruct(AslParser::FuncConstructContext * /*ctx*/) override { }
  virtual void exitFuncConstruct(AslParser::FuncConstructContext * /*ctx*/) override { }

  virtual void enterExprFunc(AslParser::ExprFuncContext * /*ctx*/) override { }
  virtual void exitExprFunc(AslParser::ExprFuncContext * /*ctx*/) override { }

  virtual void enterPairExpr(AslParser::PairExprContext * /*ctx*/) override { }
  virtual void exitPairExpr(AslParser::PairExprContext * /*ctx*/) override { }

  virtual void enterAtom(AslParser::AtomContext * /*ctx*/) override { }
  virtual void exitAtom(AslParser::AtomContext * /*ctx*/) override { }

  virtual void enterChart(AslParser::ChartContext * /*ctx*/) override { }
  virtual void exitChart(AslParser::ChartContext * /*ctx*/) override { }

  virtual void enterValue(AslParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(AslParser::ValueContext * /*ctx*/) override { }

  virtual void enterFval(AslParser::FvalContext * /*ctx*/) override { }
  virtual void exitFval(AslParser::FvalContext * /*ctx*/) override { }

  virtual void enterBoolExpr(AslParser::BoolExprContext * /*ctx*/) override { }
  virtual void exitBoolExpr(AslParser::BoolExprContext * /*ctx*/) override { }

  virtual void enterIdent(AslParser::IdentContext * /*ctx*/) override { }
  virtual void exitIdent(AslParser::IdentContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

