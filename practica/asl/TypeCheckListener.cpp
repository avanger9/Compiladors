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
    if (ctx->funcType()){
	    auto a = ctx->funcType()->type();
	    if (a->INT()) Symbols.setCurrentFunctionTy(Types.createIntegerTy());
	    else if (a->FLOAT()) Symbols.setCurrentFunctionTy(Types.createFloatTy());
	    else if (a->CHAR()) Symbols.setCurrentFunctionTy(Types.createCharacterTy());
	    else Symbols.setCurrentFunctionTy(Types.createBooleanTy());
  	}
  	else Symbols.setCurrentFunctionTy(Types.createVoidTy());
    //Symbols.print();
}
void TypeCheckListener::exitFunction(AslParser::FunctionContext *ctx) {
    Symbols.popScope();
    DEBUG_EXIT();
}

void TypeCheckListener::enterRetFunc(AslParser::RetFuncContext *ctx) {}
void TypeCheckListener::exitRetFunc(AslParser::RetFuncContext *ctx) {
    TypesMgr::TypeId t;
    if (!ctx->expr()) 
    	t = Types.createVoidTy();
    else 
    	t = getTypeDecor(ctx->expr());
    TypesMgr::TypeId t3 = Symbols.getCurrentFunctionTy();
    if (not Types.equalTypes(t3, t) and not (Types.isErrorTy(t3)) and not (Types.isIntegerTy(t) and Types.isFloatTy(t3))) {
        Errors.incompatibleReturn(ctx->RETURN());
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
	if (not Types.isIntegerTy(t) and not Types.isErrorTy(t)) {
		Errors.nonIntegerIndexInArrayAccess(ctx->expr());
    }
}

void TypeCheckListener::enterStatements(AslParser::StatementsContext *ctx) { DEBUG_ENTER(); } 
void TypeCheckListener::exitStatements(AslParser::StatementsContext *ctx) { DEBUG_EXIT(); }

void TypeCheckListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) { DEBUG_ENTER(); }

void TypeCheckListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) {
	TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
	TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
	if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and (not Types.copyableTypes(t1, t2)))
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
	if (not Types.isErrorTy(t1) and not Types.isBooleanTy(t1))
		Errors.booleanRequired(ctx);
	DEBUG_EXIT();
}

void TypeCheckListener::enterWhileStmt(AslParser::WhileStmtContext *ctx) {}
void TypeCheckListener::exitWhileStmt(AslParser::WhileStmtContext *ctx) {
	TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
	if (not Types.isErrorTy(t1) and not Types.isBooleanTy(t1))
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
        if (ctx->exprFunc()) {
            vector<AslParser::ExprContext*> lpar = ctx->exprFunc()->expr();
            size_t s = Types.getNumOfParameters(t1);
            if (s != lpar.size()) 
                Errors.numberOfParameters(ctx);
            else {
                vector<TypesMgr::TypeId> v = Types.getFuncParamsTypes(t1);
                for (int i=0; i<s; ++i) {
                    TypesMgr::TypeId td = getTypeDecor(ctx->exprFunc()->expr(i));
                    if (not Types.copyableTypes(v[i], td))
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
	if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
		((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))) or
		(not Types.isErrorTy(t2) and ctx->op->getText() == "\%" and (Types.isFloatTy(t1) or Types.isFloatTy(t2)))) 
		Errors.incompatibleOperator(ctx->op);
    if (Types.isFloatTy(t1) or Types.isFloatTy(t2))
        t = Types.createFloatTy();
    else
        t = Types.createIntegerTy();
	putTypeDecor(ctx, t);
	putIsLValueDecor(ctx, false);
	DEBUG_EXIT();
}

void TypeCheckListener::enterRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
}
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

void TypeCheckListener::enterBooleanExpr(AslParser::BooleanExprContext *ctx) {
  DEBUG_ENTER();
}

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

void TypeCheckListener::enterUnaryExpr(AslParser::UnaryExprContext *ctx) {}
void TypeCheckListener::exitUnaryExpr(AslParser::UnaryExprContext *ctx) {
	TypesMgr::TypeId t = getTypeDecor(ctx->expr());
	if (ctx->NOT()) {
		if (not Types.isErrorTy(t) and not Types.isBooleanTy(t))
			Errors.incompatibleOperator(ctx->op);
		else
			putTypeDecor(ctx, t);
	}
	else { // PLUS & MINUS
		if (not Types.isErrorTy(t) and not Types.isNumericTy(t))
			Errors.incompatibleOperator(ctx->op);
		else
			putTypeDecor(ctx, t);
	}
    putIsLValueDecor(ctx,false);
}

void TypeCheckListener::enterAtom(AslParser::AtomContext *ctx) {}
void TypeCheckListener::exitAtom(AslParser::AtomContext *ctx) {
    TypesMgr::TypeId t;
    if (ctx->boolExpr())
        t = Types.createBooleanTy();
    	//cout << Types.to_string(t) << endl;
    else if (ctx->chart())
        t = Types.createCharacterTy();
    else if (ctx->fval())
        t = Types.createFloatTy();
    else
        t = Types.createIntegerTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx,false);
}


void TypeCheckListener::enterChart(AslParser::ChartContext *ctx) {}
void TypeCheckListener::exitChart(AslParser::ChartContext *ctx) {}

void TypeCheckListener::enterBoolExpr(AslParser::BoolExprContext *ctx) {}
void TypeCheckListener::exitBoolExpr(AslParser::BoolExprContext *ctx) {}

void TypeCheckListener::enterFval(AslParser::FvalContext *ctx) {}
void TypeCheckListener::exitFval(AslParser::FvalContext *ctx) {}

void TypeCheckListener::enterValue(AslParser::ValueContext *ctx) {}
void TypeCheckListener::exitValue(AslParser::ValueContext *ctx) {}

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
