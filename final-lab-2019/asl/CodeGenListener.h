//////////////////////////////////////////////////////////////////////
//
//    CodeGenListener - Walk the parser tree to do
//                      the generation of code
//
//    Copyright (C) 2018  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "antlr4-runtime.h"
#include "AslBaseListener.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>

// using namespace std;


//////////////////////////////////////////////////////////////////////
// Class CodeGenListener: derived from AslBaseListener.
// The tree walker go through the parser tree and call the methods of
// this listener to generate the code of the program. This is done
// once the SymbolsListener and TypeCheckListener have finish with no
// semantic error. So all the symbols of the program has been added to
// their respective scope and the type of each expresion has also be
// computed and decorate the parse tree. If an enter/exit method does
// not have an associated task, it does not have to be redefined.

class  CodeGenListener : public AslBaseListener {

public:

  // Constructor
    CodeGenListener(TypesMgr &Types, SymTable &Symbols, TreeDecoration &TreeNodeProps, code &Code);

    void enterProgram(AslParser::ProgramContext *ctx);
    void exitProgram(AslParser::ProgramContext *ctx);

    void enterFunction(AslParser::FunctionContext *ctx);
    void exitFunction(AslParser::FunctionContext *ctx);

    void enterDeclarations(AslParser::DeclarationsContext *ctx);
    void exitDeclarations(AslParser::DeclarationsContext *ctx);

    void enterVariable_decl(AslParser::Variable_declContext *ctx);
    void exitVariable_decl(AslParser::Variable_declContext *ctx);

    void enterTypeR(AslParser::TypeRContext *ctx);
    void exitTypeR(AslParser::TypeRContext *ctx);

    void enterType(AslParser::TypeContext *ctx);
    void exitType(AslParser::TypeContext *ctx);

    void enterStatements(AslParser::StatementsContext *ctx);
    void exitStatements(AslParser::StatementsContext *ctx);

    void enterAssignStmt(AslParser::AssignStmtContext *ctx);
    void exitAssignStmt(AslParser::AssignStmtContext *ctx);

    void enterIfStmt(AslParser::IfStmtContext *ctx);
    void exitIfStmt(AslParser::IfStmtContext *ctx);

    void enterWhileStmt(AslParser::WhileStmtContext *ctx);
	void exitWhileStmt(AslParser::WhileStmtContext *ctx);

    void enterProcCall(AslParser::ProcCallContext *ctx);
    void exitProcCall(AslParser::ProcCallContext *ctx);

    void enterReadStmt(AslParser::ReadStmtContext *ctx);
    void exitReadStmt(AslParser::ReadStmtContext *ctx);

    void enterWriteExpr(AslParser::WriteExprContext *ctx);
    void exitWriteExpr(AslParser::WriteExprContext *ctx);

    void enterWriteString(AslParser::WriteStringContext *ctx);
    void exitWriteString(AslParser::WriteStringContext *ctx);

/*
    void enterRetF(AslParser::RetFContext *ctx);
	void exitRetF(AslParser::RetFContext *ctx);
*/
	void enterRetFunc(AslParser::RetFuncContext *ctx);
	void exitRetFunc(AslParser::RetFuncContext *ctx);

    void enterLeft_expr(AslParser::Left_exprContext *ctx);
    void exitLeft_expr(AslParser::Left_exprContext *ctx);

    void enterFuncExpr(AslParser::FuncExprContext *ctx);
    void exitFuncExpr(AslParser::FuncExprContext *ctx);

    void enterFuncConstruct(AslParser::FuncConstructContext *ctx);
    void exitFuncConstruct(AslParser::FuncConstructContext *ctx);

    void enterArrayExpr(AslParser::ArrayExprContext *ctx);
	void exitArrayExpr(AslParser::ArrayExprContext *ctx);

	void enterArrayConstruct(AslParser::ArrayConstructContext *ctx);
	void exitArrayConstruct(AslParser::ArrayConstructContext *ctx);

    void enterArithmetic(AslParser::ArithmeticContext *ctx);
    void exitArithmetic(AslParser::ArithmeticContext *ctx);

    void enterRelational(AslParser::RelationalContext *ctx);
    void exitRelational(AslParser::RelationalContext *ctx);

    void enterBooleanExpr(AslParser::BooleanExprContext *ctx);
    void exitBooleanExpr(AslParser::BooleanExprContext *ctx);

    void enterParExpr(AslParser::ParExprContext *ctx);
    void exitParExpr(AslParser::ParExprContext *ctx);

    void enterAtomExpr(AslParser::AtomExprContext *ctx);
    void exitAtomExpr(AslParser::AtomExprContext *ctx);

    void enterAtom(AslParser::AtomContext *ctx);
    void exitAtom(AslParser::AtomContext *ctx);

    void enterUnaryExpr(AslParser::UnaryExprContext *ctx);
    void exitUnaryExpr(AslParser::UnaryExprContext *ctx);

    void enterChart(AslParser::ChartContext *ctx);
    void exitChart(AslParser::ChartContext *ctx);

    void enterBoolExpr(AslParser::BoolExprContext *ctx);
    void exitBoolExpr(AslParser::BoolExprContext *ctx);

    void enterFval(AslParser::FvalContext *ctx);
    void exitFval(AslParser::FvalContext *ctx);

    void enterValue(AslParser::ValueContext *ctx);
    void exitValue(AslParser::ValueContext *ctx);

    void enterExprIdent(AslParser::ExprIdentContext *ctx);
    void exitExprIdent(AslParser::ExprIdentContext *ctx);

    void enterIdent(AslParser::IdentContext *ctx);
    void exitIdent(AslParser::IdentContext *ctx);

    void enterMaxim(AslParser::MaximContext *ctx);
	void exitMaxim(AslParser::MaximContext *ctx);

	void enterMaximExpr(AslParser::MaximExprContext *ctx);
	void exitMaximExpr(AslParser::MaximExprContext *ctx);

    // void enterEveryRule(antlr4::ParserRuleContext *ctx);
    // void exitEveryRule(antlr4::ParserRuleContext *ctx);
    // void visitTerminal(antlr4::tree::TerminalNode *node);
    // void visitErrorNode(antlr4::tree::ErrorNode *node);

private:

    // Attributes
    TypesMgr        & Types;
    SymTable        & Symbols;
    TreeDecoration  & Decorations;
    code            & Code;
    counters          codeCounters;

    // Getters for the necessary tree node atributes:
    //   Scope, Type, Addr, Offset and Code
    SymTable::ScopeId getScopeDecor  (antlr4::ParserRuleContext *ctx);
    TypesMgr::TypeId  getTypeDecor   (antlr4::ParserRuleContext *ctx);
    std::string       getAddrDecor   (antlr4::ParserRuleContext *ctx);
    std::string       getOffsetDecor (antlr4::ParserRuleContext *ctx);
    instructionList   getCodeDecor   (antlr4::ParserRuleContext *ctx);

    // Setters for the necessary tree node attributes:
    //   Addr, Offset and Code
    void putAddrDecor   (antlr4::ParserRuleContext *ctx, const std::string & a);
    void putOffsetDecor (antlr4::ParserRuleContext *ctx, const std::string & o);
    void putCodeDecor   (antlr4::ParserRuleContext *ctx, const instructionList & c);

};
