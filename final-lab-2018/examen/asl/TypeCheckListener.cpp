//////////////////////////////////////////////////////////////////////
//
//    TypeCheckListener - Walk the parser tree to do the semantic
//                        typecheck for the Asl programming language
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

#include "TypeCheckListener.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
//#define DEBUG_BUILD
#include "../common/debug.h"

using namespace std;


// Constructor
TypeCheckListener::TypeCheckListener(TypesMgr &Types, SymTable &Symbols, 
                                    TreeDecoration &Decorations, SemErrors &Errors) :
    Types{Types}, Symbols {Symbols}, Decorations{Decorations}, Errors{Errors} {}

void TypeCheckListener::enterProgram(AslParser::ProgramContext *ctx) {
    DEBUG_ENTER();
    SymTable::ScopeId sc = getScopeDecor(ctx);
    Symbols.pushThisScope(sc);
}
void TypeCheckListener::exitProgram(AslParser::ProgramContext *ctx) {
    if (Symbols.noMainProperlyDeclared())
        Errors.noMainProperlyDeclared(ctx);
    Symbols.popScope();
    Errors.print();
    DEBUG_EXIT();
}

void TypeCheckListener::enterFunction(AslParser::FunctionContext *ctx) {
    DEBUG_ENTER();
    SymTable::ScopeId sc = getScopeDecor(ctx);
    Symbols.pushThisScope(sc);
    //Symbols.print();
}
void TypeCheckListener::exitFunction(AslParser::FunctionContext *ctx) {
    //Symbols.popScope();
    //TypesMgr::TypeId t1 = getTypeDecor(ctx->retFunc());
/*
    for (auto ct:ctx->retFunc()) {
        TypesMgr::TypeId t2 = getTypeDecor(ct->expr());
        TypesMgr::TypeId t3 = Symbols.getCurrentFunctionTy();
        TypesMgr::TypeId t4 = Types.TypesMgr::getFuncReturnType(t3);
        if (!ct->expr()) {
            t2 = Types.createVoidTy();
            if (not Types.equalTypes(t4, t2)) {
                Errors.incompatibleReturn(ct);
            }
        }
        else {
            if (not Types.equalTypes(t4, t2) and not (Types.isNumericTy(t4) and Types.isIntegerTy(t2)))
                Errors.incompatibleReturn(ct->expr());    
        }
        //cout << "type func: " << Types.to_string(t4) << " type ret: " << Types.to_string(t2) << endl;
    }
*/
    /*
    for (auto ct:ctx->expr()) {
        TypesMgr::TypeId t2 = getTypeDecor(ct);
        TypesMgr::TypeId t3 = Symbols.getCurrentFunctionTy();
        TypesMgr::TypeId t4 = Types.TypesMgr::getFuncReturnType(t3);
        if (not Types.equalTypes(t4, t2) and not Types.isErrorTy(t2) and (Types.isNumericTy(t4) and not Types.isIntegerTy(t2)))
            Errors.incompatibleReturn(ct);
    }
    */
    //cout << "equal types?: " << Types.equalTypes(t4,t2) << endl;
    //cout << "type func: " << Types.to_string(t3) << " type ret: " << Types.to_string(t2) << " type ret: " << Types.to_string(t4) << endl;
    //Symbols.print();
    Symbols.popScope();
    DEBUG_EXIT();
}

void TypeCheckListener::enterRetFunc(AslParser::RetFuncContext *ctx) {}
void TypeCheckListener::exitRetFunc(AslParser::RetFuncContext *ctx) {
    TypesMgr::TypeId t;
    if (!ctx->expr()) {
        t = Types.createVoidTy();
    }
    else {
        t = getTypeDecor(ctx->expr());
    }
    TypesMgr::TypeId t3 = Symbols.getCurrentFunctionTy();
    TypesMgr::TypeId t4 = Types.TypesMgr::getFuncReturnType(t3);
    if (not Types.copyableTypes(t4, t) and not (Types.isErrorTy(t4) and Types.isErrorTy(t))) {
        if (!ctx->expr()) 
            Errors.incompatibleReturn(ctx);    
        else
            Errors.incompatibleReturn(ctx->expr());
    }
}

void TypeCheckListener::enterDeclarations(AslParser::DeclarationsContext *ctx) { DEBUG_ENTER(); }
void TypeCheckListener::exitDeclarations(AslParser::DeclarationsContext *ctx) { DEBUG_EXIT(); }

void TypeCheckListener::enterVariable_decl(AslParser::Variable_declContext *ctx) { DEBUG_ENTER(); }
void TypeCheckListener::exitVariable_decl(AslParser::Variable_declContext *ctx) { DEBUG_EXIT(); }

void TypeCheckListener::enterType(AslParser::TypeContext *ctx) { DEBUG_ENTER(); }
void TypeCheckListener::exitType(AslParser::TypeContext *ctx) { }

void TypeCheckListener::enterArray(AslParser::ArrayContext *ctx) {}
void TypeCheckListener::exitArray(AslParser::ArrayContext *ctx) {
	TypesMgr::TypeId t = getTypeDecor(ctx->expr());
	if (not (Types.isIntegerTy(t))) {
		Errors.nonIntegerIndexInArrayAccess(ctx->expr());
    }
}

void TypeCheckListener::enterStatements(AslParser::StatementsContext *ctx) { DEBUG_ENTER(); } 
void TypeCheckListener::exitStatements(AslParser::StatementsContext *ctx) { DEBUG_EXIT(); }

void TypeCheckListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) { DEBUG_ENTER(); }

void TypeCheckListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) {
	TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
	TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
    //cout << "type LE: " << Types.to_string(t1) << " type expr: " << Types.to_string(t2) << endl;
	if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and (not Types.copyableTypes(t1, t2)) and (not Types.isVoidTy(t2)))
		Errors.incompatibleAssignment(ctx->ASSIGN());
	if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
		Errors.nonReferenceableLeftExpr(ctx->left_expr());
	DEBUG_EXIT();
}

void TypeCheckListener::enterIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitIfStmt(AslParser::IfStmtContext *ctx) {
	TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
	if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
		Errors.booleanRequired(ctx);
	DEBUG_EXIT();
}

void TypeCheckListener::enterWhileStmt(AslParser::WhileStmtContext *ctx) {}
void TypeCheckListener::exitWhileStmt(AslParser::WhileStmtContext *ctx) {
	TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
	if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
		Errors.booleanRequired(ctx);
	DEBUG_EXIT();
}


void TypeCheckListener::enterProcCall(AslParser::ProcCallContext *ctx) {
    DEBUG_ENTER();
}
void TypeCheckListener::exitProcCall(AslParser::ProcCallContext *ctx) {}

void TypeCheckListener::enterReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitReadStmt(AslParser::ReadStmtContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
    if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and (not Types.isFunctionTy(t1)))
        Errors.readWriteRequireBasic(ctx);
    if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
        Errors.nonReferenceableExpression(ctx);
    DEBUG_EXIT();
}

void TypeCheckListener::enterWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitWriteExpr(AslParser::WriteExprContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
        Errors.readWriteRequireBasic(ctx);
    DEBUG_EXIT();
}

void TypeCheckListener::enterWriteString(AslParser::WriteStringContext *ctx) {
    DEBUG_ENTER();
}
void TypeCheckListener::exitWriteString(AslParser::WriteStringContext *ctx) {
    DEBUG_EXIT();
}

void TypeCheckListener::enterLeft_expr(AslParser::Left_exprContext *ctx) {
    DEBUG_ENTER();
}
void TypeCheckListener::exitLeft_expr(AslParser::Left_exprContext *ctx) {
    if (ctx->ident()) {
        TypesMgr::TypeId t = getTypeDecor(ctx->ident());
        bool b = getIsLValueDecor(ctx->ident());
        putTypeDecor(ctx,t);
        putIsLValueDecor(ctx,b);
    }
    else if (ctx->arrayConstruct()) {
        TypesMgr::TypeId t = getTypeDecor(ctx->arrayConstruct());
        bool b = getIsLValueDecor(ctx->arrayConstruct());
        putTypeDecor(ctx,t);
        putIsLValueDecor(ctx,b);    
    }
    else {
        TypesMgr::TypeId t = getTypeDecor(ctx->pairExpr());
        bool b = getIsLValueDecor(ctx->pairExpr());
        putTypeDecor(ctx,t);
        putIsLValueDecor(ctx,b);   
    }
}

void TypeCheckListener::enterFuncExpr(AslParser::FuncExprContext *ctx) {}
void TypeCheckListener::exitFuncExpr(AslParser::FuncExprContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->funcConstruct());
    // comprovem que no sigui void ja que una variable no pot ser igual a un void
    if (Types.isVoidTy(t1) and not Types.isErrorTy(t1)) {
        Errors.isNotFunction(ctx);
    }
    else {
        putTypeDecor(ctx, t1);
    }
}

void TypeCheckListener::enterFuncConstruct(AslParser::FuncConstructContext *ctx) {}
void TypeCheckListener::exitFuncConstruct(AslParser::FuncConstructContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
    bool b = getIsLValueDecor(ctx->ident());
    if (not Types.isFunctionTy(t1) and not Types.isErrorTy(t1)) {
        Errors.isNotCallable(ctx->ident());
    }
    else if (not Types.isErrorTy(t1)) {
    //comprovem errors del numero de parametres i tipo
        if (ctx->exprFunc()) {
            vector<AslParser::ExprContext*> lpar = ctx->exprFunc()->expr();
            size_t s = Types.getNumOfParameters(t1);
            if (s != lpar.size()) 
                Errors.numberOfParameters(ctx);
            else {
                vector<TypesMgr::TypeId> v = Types.getFuncParamsTypes(t1);
                for (int i=0; i<s; ++i) {
                    TypesMgr::TypeId td = getTypeDecor(ctx->exprFunc()->expr(i));
                    //cout << "type func param: " << Types.to_string(v[i]) << " type local param: " << Types.to_string(td) << endl;
                    if (not Types.copyableTypes(Types.getParameterType(t1,i), td))
                        Errors.incompatibleParameter(ctx->exprFunc()->expr(i), i+1, ctx->ident());
                }
            }
        }
        else {
            size_t s = Types.getNumOfParameters(t1);
            if (s > 0) Errors.numberOfParameters(ctx);
        }
        t1 = Types.getFuncReturnType(t1);
        putTypeDecor(ctx,t1);
    }
    else {
        putTypeDecor(ctx,t1);
    }
    //cout << "arribo?" << endl;
}

void TypeCheckListener::enterArrayExpr(AslParser::ArrayExprContext *ctx) {}
void TypeCheckListener::exitArrayExpr(AslParser::ArrayExprContext *ctx) {
	putTypeDecor(ctx, getTypeDecor(ctx->arrayConstruct()));
    putIsLValueDecor(ctx, getIsLValueDecor(ctx->arrayConstruct()));
}

void TypeCheckListener::enterArrayConstruct(AslParser::ArrayConstructContext *ctx) {}
void TypeCheckListener::exitArrayConstruct(AslParser::ArrayConstructContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
    //cout << "type expr: " << Types.to_string(t2) << " es array? " << Types.isArrayTy(t1) << endl;
    if ((not Types.isArrayTy(t1)) and (not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2))) {
        Errors.nonArrayInArrayAccess(ctx);
        t1 = Types.createErrorTy();
    }
    if (not (Types.isIntegerTy(t2)) and not (Types.isErrorTy(t2))) {
        Errors.nonIntegerIndexInArrayAccess(ctx->expr());
        t1 = Types.createErrorTy();
    }
    if (Types.isArrayTy(t1) and Types.isIntegerTy(t2))
        t1 = Types.getArrayElemType(t1);
    bool b = getIsLValueDecor(ctx->ident());
    putIsLValueDecor(ctx, b);
    putTypeDecor(ctx, t1);
    DEBUG_EXIT();
}

void TypeCheckListener::enterArithmetic(AslParser::ArithmeticContext *ctx) { DEBUG_ENTER(); }
void TypeCheckListener::exitArithmetic(AslParser::ArithmeticContext *ctx) {
	TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
	TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    TypesMgr::TypeId t;
    if (ctx->MUL() and Types.isArrayTy(t1) and Types.isArrayTy(t2)) {
    	auto t11 = Types.getArrayElemType(t1);
    	auto t22 = Types.getArrayElemType(t2);
    	uint s1 = Types.getArraySize(t1);
    	uint s2 = Types.getArraySize(t2);
    	//cerr << s1 << ' ' << s2 << endl;
    	if (not Types.isErrorTy(t11) and not Types.isErrorTy(t22)) {
    		if (s1 != s2) Errors.incompatibleOperator(ctx->op);
    		if (Types.isIntegerTy(t11) and Types.isIntegerTy(t22)) {
    			t = Types.createIntegerTy();
    		}
    		else if (Types.isFloatTy(t11) and Types.isFloatTy(t22)) {
    			t = Types.createFloatTy();
    		}
    		else {
    			Errors.incompatibleOperator(ctx->op);
    			t = Types.createErrorTy();
    		}
    	}
    }
    else {
		if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
			((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
			Errors.incompatibleOperator(ctx->op);
	    if (Types.isFloatTy(t1) or Types.isFloatTy(t2))
	        t = Types.createFloatTy();
	    else
	        t = Types.createIntegerTy();
	}
	putTypeDecor(ctx, t);
	putIsLValueDecor(ctx, false);
	DEBUG_EXIT();
}

void TypeCheckListener::enterRelational(AslParser::RelationalContext *ctx) { DEBUG_ENTER(); }
void TypeCheckListener::exitRelational(AslParser::RelationalContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    string oper = ctx->op->getText();

    if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and 
      (not Types.comparableTypes(t1, t2, oper)))
    	Errors.incompatibleOperator(ctx->op);
    TypesMgr::TypeId t = Types.createBooleanTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    DEBUG_EXIT();
}

void TypeCheckListener::enterBooleanExpr(AslParser::BooleanExprContext *ctx) { DEBUG_ENTER(); }

void TypeCheckListener::exitBooleanExpr(AslParser::BooleanExprContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    string oper = ctx->op->getText();
    if ((not Types.isErrorTy(t1))   and (not Types.isBooleanTy(t1)) or 
        (not Types.isErrorTy(t2))   and (not Types.isBooleanTy(t2)) and
        (not Types.comparableTypes(t1, t2, oper)))
            Errors.incompatibleOperator(ctx->op);
    TypesMgr::TypeId t = Types.createBooleanTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    DEBUG_EXIT();
}

void TypeCheckListener::enterAtomExpr(AslParser::AtomExprContext *ctx) {}
void TypeCheckListener::exitAtomExpr(AslParser::AtomExprContext *ctx) {
    TypesMgr::TypeId t = getTypeDecor(ctx->atom());
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
}

void TypeCheckListener::enterAtom(AslParser::AtomContext *ctx) {}
void TypeCheckListener::exitAtom(AslParser::AtomContext *ctx) {
    TypesMgr::TypeId t;
    if (ctx->boolExpr())
        t = getTypeDecor(ctx->boolExpr());
    	//cout << Types.to_string(t) << endl;
    else if (ctx->chart())
        t = getTypeDecor(ctx->chart());
    else if (ctx->fval())
        t = getTypeDecor(ctx->fval());
    else if (ctx->value())
        t = getTypeDecor(ctx->value());
    else
        t = getTypeDecor(ctx->pairExpr());
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
}

void TypeCheckListener::enterPairExpr(AslParser::PairExprContext *ctx) {}
void TypeCheckListener::exitPairExpr(AslParser::PairExprContext *ctx) {
    TypesMgr::TypeId t = getTypeDecor(ctx->ident());
    TypesMgr::TypeId tp;
    if (ctx->FIRST())
        tp = Types.getFirstPairType(t);
    else
        tp = Types.getSecondPairType(t);
    putTypeDecor(ctx, tp);
    putIsLValueDecor(ctx, getIsLValueDecor(ctx->ident()));
}

void TypeCheckListener::enterUnaryExpr(AslParser::UnaryExprContext *ctx) {}
void TypeCheckListener::exitUnaryExpr(AslParser::UnaryExprContext *ctx) {
    TypesMgr::TypeId t = getTypeDecor(ctx->expr());
    if (ctx->NOT()) {
        if (not Types.isErrorTy(t) and not Types.isBooleanTy(t))
            Errors.incompatibleOperator(ctx->op);
        else
            putTypeDecor(ctx, t);
    }
    else
        putTypeDecor(ctx, t);
    putIsLValueDecor(ctx,false);
}


void TypeCheckListener::enterChart(AslParser::ChartContext *ctx) {}
void TypeCheckListener::exitChart(AslParser::ChartContext *ctx) {
    TypesMgr::TypeId t = Types.createCharacterTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    DEBUG_EXIT();
}

void TypeCheckListener::enterBoolExpr(AslParser::BoolExprContext *ctx) {}
void TypeCheckListener::exitBoolExpr(AslParser::BoolExprContext *ctx) {
    TypesMgr::TypeId t = Types.createBooleanTy();
    //cout << Types.to_string(t) << " <-> " << ctx->getText() << endl;
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    DEBUG_EXIT();    
}

void TypeCheckListener::enterFval(AslParser::FvalContext *ctx) {}
void TypeCheckListener::exitFval(AslParser::FvalContext *ctx) {
    TypesMgr::TypeId t = Types.createFloatTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    DEBUG_EXIT();    
}

void TypeCheckListener::enterValue(AslParser::ValueContext *ctx) { DEBUG_ENTER(); }
void TypeCheckListener::exitValue(AslParser::ValueContext *ctx) {
    TypesMgr::TypeId t = Types.createIntegerTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    DEBUG_EXIT();
}

void TypeCheckListener::enterExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
}
void TypeCheckListener::exitExprIdent(AslParser::ExprIdentContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
    putTypeDecor(ctx, t1);
    bool b = getIsLValueDecor(ctx->ident());
    putIsLValueDecor(ctx, b);
    DEBUG_EXIT();
}

void TypeCheckListener::enterParExpr(AslParser::ParExprContext *ctx) {}
void TypeCheckListener::exitParExpr(AslParser::ParExprContext *ctx) {
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    putTypeDecor(ctx, t1);
    putIsLValueDecor(ctx, false);
    DEBUG_EXIT();    
}

void TypeCheckListener::enterIdent(AslParser::IdentContext *ctx) {
    DEBUG_ENTER();
}
void TypeCheckListener::exitIdent(AslParser::IdentContext *ctx) {
    string ident = ctx->getText();
    if (Symbols.findInStack(ident) == -1) {
        Errors.undeclaredIdent(ctx->ID());
        TypesMgr::TypeId te = Types.createErrorTy();
        putTypeDecor(ctx, te);
        putIsLValueDecor(ctx, true);
    }
    else {
        TypesMgr::TypeId t1 = Symbols.getType(ident);
        putTypeDecor(ctx, t1);
        if (Symbols.isFunctionClass(ident))
            putIsLValueDecor(ctx, false);
        else
            putIsLValueDecor(ctx, true);
        }
    DEBUG_EXIT();
   }

// void TypeCheckListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_ENTER();
// }
// void TypeCheckListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_EXIT();
// }
// void TypeCheckListener::visitTerminal(antlr4::tree::TerminalNode *node) {
//   DEBUG("visitTerminal");
// }
// void TypeCheckListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
// }


// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckListener::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckListener::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckListener::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckListener::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckListener::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckListener::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}
