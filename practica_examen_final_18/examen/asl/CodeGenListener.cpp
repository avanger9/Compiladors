//////////////////////////////////////////////////////////////////////
//
//    CodeGenListener - Walk the parser tree to do
//                             the generation of code
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

#include "CodeGenListener.h"

#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <cstddef>    // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

using namespace std;


// Constructor
CodeGenListener::CodeGenListener(TypesMgr &Types, SymTable &Symbols, 
								 TreeDecoration &Decorations, code &Code) :
	Types{Types}, Symbols{Symbols}, Decorations{Decorations}, Code{Code} {

}

void CodeGenListener::enterProgram(AslParser::ProgramContext *ctx) {
	DEBUG_ENTER();
	SymTable::ScopeId sc = getScopeDecor(ctx);
	Symbols.pushThisScope(sc);
}
void CodeGenListener::exitProgram(AslParser::ProgramContext *ctx) {
	Symbols.popScope();
	DEBUG_EXIT();
}

void CodeGenListener::enterFunction(AslParser::FunctionContext *ctx) {
	DEBUG_ENTER();
	subroutine subr(ctx->ID()->getText());

	if (ctx->funcType()) {
		subr.add_param("_result");
	}
	if (ctx->funcParams()) {
		for (auto ct:ctx->funcParams()->ID()) {
			subr.add_param(ct->getText());
		}
	}
	Code.add_subroutine(subr);
	SymTable::ScopeId sc = getScopeDecor(ctx);
	Symbols.pushThisScope(sc);
	codeCounters.reset();
}
void CodeGenListener::exitFunction(AslParser::FunctionContext *ctx) {
	subroutine & subrRef = Code.get_last_subroutine();
	instructionList code = getCodeDecor(ctx->statements());
	code = code || instruction::RETURN();
	subrRef.set_instructions(code);
	Symbols.popScope();
	DEBUG_EXIT();
}

void CodeGenListener::enterDeclarations(AslParser::DeclarationsContext *ctx) { DEBUG_ENTER(); }
void CodeGenListener::exitDeclarations(AslParser::DeclarationsContext *ctx) { DEBUG_EXIT(); }

void CodeGenListener::enterVariable_decl(AslParser::Variable_declContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitVariable_decl(AslParser::Variable_declContext *ctx) {
	subroutine       & subrRef = Code.get_last_subroutine();
    TypesMgr::TypeId        t1 = getTypeDecor(ctx->typeR());
    std::size_t           size = Types.getSizeOfType(t1);
    for (auto varCt : ctx->ID()) {
        subrRef.add_var(varCt->getText(), size);
    }
}

void CodeGenListener::enterTypeR(AslParser::TypeRContext *ctx) {}
void CodeGenListener::exitTypeR(AslParser::TypeRContext *ctx) {}

void CodeGenListener::enterType(AslParser::TypeContext *ctx) {}
void CodeGenListener::exitType(AslParser::TypeContext *ctx) {}

void CodeGenListener::enterStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitStatements(AslParser::StatementsContext *ctx) {
	instructionList code;
	for (auto stCtx : ctx->statement()) {
	code = code || getCodeDecor(stCtx);
	}
	putCodeDecor(ctx, code);
	DEBUG_EXIT();
}

void CodeGenListener::enterAssignStmt(AslParser::AssignStmtContext *ctx) { DEBUG_ENTER(); }
void CodeGenListener::exitAssignStmt(AslParser::AssignStmtContext *ctx) {
	instructionList  code;
	// left_expr = ...

	string          addr1 = getAddrDecor(ctx->left_expr());
	string          offs1 = getOffsetDecor(ctx->left_expr());
	instructionList code1 = getCodeDecor(ctx->left_expr());
	TypesMgr::TypeId   t1 = getTypeDecor(ctx->left_expr());

	// ... = expr
	string          addr2 = getAddrDecor(ctx->expr());
	string          offs2 = getOffsetDecor(ctx->expr());
	instructionList code2 = getCodeDecor(ctx->expr());
	TypesMgr::TypeId   t2 = getTypeDecor(ctx->expr());

	if (ctx->left_expr()->arrayConstruct()) {
		if (not Symbols.isParameterClass(ctx->left_expr()->arrayConstruct()->ident()->ID()->getText())) {
			code = code1 || code2 || instruction::XLOAD(addr1, offs1, addr2);	
		}
		else {
			string tmp = "%"+codeCounters.newTEMP();
			code = code1 || code2 || instruction::LOAD(tmp, addr1) || instruction::XLOAD(tmp, offs1, addr2);
		}
	}
	else if (Types.isArrayTy(t1)){
		int size = Types.getArraySize(t1);
		instructionList codeaux = instructionList();
		size_t s = Types.getSizeOfType(Types.getArrayElemType(t1));
		std::string index = "%"+codeCounters.newTEMP();
		std::string temp1 = "%"+codeCounters.newTEMP();
		std::string temp2 = "%"+codeCounters.newTEMP();
		codeaux = codeaux || instruction::ILOAD(index, "0");
		codeaux = codeaux || instruction::ILOAD(temp1, std::to_string(s));
		if (not Symbols.isParameterClass(ctx->left_expr()->ident()->ID()->getText()) and
			not Symbols.isParameterClass(addr2)) {
			for(int i = 0; i < size; i++){
				codeaux = codeaux || instruction::LOADX(temp2, addr2,index) ||
					instruction::XLOAD(addr1, index,temp2) ||
					instruction::ADD(index, index, temp1);
			}
		}
		else if (not Symbols.isParameterClass(ctx->left_expr()->ident()->ID()->getText())){
			std::string temp3 = "%"+codeCounters.newTEMP();
			for(int i = 0; i < size; i++){
				codeaux = codeaux || instruction::LOAD(temp3, addr2);
				codeaux = codeaux || instruction::LOADX(temp2, temp3, index);
				codeaux = codeaux || instruction::XLOAD(addr1, index,temp2);
				codeaux = codeaux || instruction::ADD(index, index, temp1);
			}
		}
		else if (not Symbols.isParameterClass(addr2)){
			std::string temp3 = "%"+codeCounters.newTEMP();
			for(int i = 0; i < size; i++){
				codeaux = codeaux || instruction::LOADX(temp2, addr2,index) ||
					instruction::LOAD(temp3, addr1) ||
					instruction::XLOAD(temp3, index,temp2) ||
					instruction::ADD(index, index, temp1);
			}
		}
		else {
			std::string temp3 = "%"+codeCounters.newTEMP();
			for(int i = 0; i < size; i++){
				codeaux = codeaux || instruction::LOAD(temp3, addr2);
				codeaux = codeaux || instruction::LOADX(temp2, temp3,index);
				codeaux = codeaux || instruction::LOAD(temp3, addr1);
				codeaux = codeaux || instruction::XLOAD(temp3, index,temp2);
				codeaux = codeaux || instruction::ADD(index, index, temp1);
			}
		}
		code = code || codeaux;
	}
	else {
		code = code1 || code2 || instruction::LOAD(addr1, addr2);
	}
	putCodeDecor(ctx, code);
	DEBUG_EXIT();
}

void CodeGenListener::enterIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitIfStmt(AslParser::IfStmtContext *ctx) {
	instructionList  code;
	std::string      addr1 = getAddrDecor(ctx->expr());
	instructionList  code1 = getCodeDecor(ctx->expr());
	instructionList  code2 = getCodeDecor(ctx->statements());
	std::string      label = codeCounters.newLabelIF();
	std::string labelEndIf = "endif"+label;
	if (!ctx->elseStat()) {
		code = code1 || instruction::FJUMP(addr1, labelEndIf);
		code = code  || code2 ;
		code = code  || instruction::LABEL(labelEndIf);
	}
	else {
		string labelThen = "else"+label;
		instructionList  code3 = getCodeDecor(ctx->elseStat()->statements());
		code = code1 || instruction::FJUMP(addr1, labelThen);
		code = code  || code2 || instruction::UJUMP(labelEndIf);
		code = code  || instruction::LABEL(labelThen);
		code = code  || code3 || instruction::LABEL(labelEndIf);;
	}
	putCodeDecor(ctx, code);
	DEBUG_EXIT();
}

void CodeGenListener::enterWhileStmt(AslParser::WhileStmtContext *ctx) {}
void CodeGenListener::exitWhileStmt(AslParser::WhileStmtContext *ctx) {
	instructionList  code;
	std::string      addr  = getAddrDecor(ctx->expr());
	instructionList  code1 = getCodeDecor(ctx->expr());
	instructionList  code2 = getCodeDecor(ctx->statements());
	string           label = codeCounters.newLabelWHILE();
	string labelEndWhile   = "endWhile"+label;
	string labelWhile      = "while"+label;

	// || instruction::NOT(tmp, addr) 
	code = instruction::LABEL(labelWhile);
	code = code || code1;
	string tmp = "%"+codeCounters.newTEMP();
	code = code || instruction::FJUMP(addr, labelEndWhile);
	code = code || code2 || instruction::UJUMP(labelWhile);
	code = code || instruction::LABEL(labelEndWhile);

	putCodeDecor(ctx, code);
}

void CodeGenListener::enterProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitProcCall(AslParser::ProcCallContext *ctx) {
    //instructionList code;
    // std::string name = ctx->ident()->ID()->getSymbol()->getText();
    //std::string name = ctx->ident()->getText();
    //code = instruction::CALL(name);
    //putCodeDecor(ctx, code);
    DEBUG_EXIT();

    //std::string name = ctx->funcConstruct()->getText();
    //instructionList code = instruction::CALL(name);

    string          addr = getAddrDecor(ctx->funcConstruct());
    instructionList code = getCodeDecor(ctx->funcConstruct());
    //instructionList code = instruction::CALL(ad);
    putCodeDecor(ctx, code);
    putAddrDecor(ctx, addr);
}

void CodeGenListener::enterReadStmt(AslParser::ReadStmtContext *ctx) {
    DEBUG_ENTER();
}
void CodeGenListener::exitReadStmt(AslParser::ReadStmtContext *ctx) {
    TypesMgr::TypeId t = getTypeDecor(ctx->left_expr());
    instructionList  code;
    std::string      addr1 = getAddrDecor(ctx->left_expr());
    instructionList  code1 = getCodeDecor(ctx->left_expr());
    bool isArray = false;
    string tmp;
    if (ctx->left_expr()->arrayConstruct()) {
    	tmp = addr1;
    	addr1 = "%"+codeCounters.newTEMP();
    	isArray = true;
    }
    if (Types.isCharacterTy(t))
    	code = code1 || instruction::READC(addr1);
    else if (Types.isFloatTy(t))
    	code = code1 || instruction::READF(addr1);
    else if (Types.isIntegerTy(t) or Types.isBooleanTy(t))
    	code = code1 || instruction::READI(addr1);
    if (isArray) {
    	// lectura dels arrays a[a1] = ...
    	TypesMgr::TypeId tA = getTypeDecor(ctx->left_expr()->arrayConstruct()->expr());
    	string     offs1 = getOffsetDecor(ctx->left_expr()->arrayConstruct());
    	code = code || instruction::XLOAD(tmp, offs1, addr1);

    }
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterWriteExpr(AslParser::WriteExprContext *ctx) { DEBUG_ENTER(); }
void CodeGenListener::exitWriteExpr(AslParser::WriteExprContext *ctx) {
    // std::string     offs1 = getOffsetDecor(ctx->expr());
    TypesMgr::TypeId t = getTypeDecor(ctx->expr());
    std::string     addr1 = getAddrDecor(ctx->expr());
    instructionList code = getCodeDecor(ctx->expr());
    if (Types.isCharacterTy(t))
        code = code || instruction::WRITEC(addr1);
    else if (Types.isFloatTy(t))
        code = code || instruction::WRITEF(addr1);
    else
        code = code || instruction::WRITEI(addr1);

    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterWriteString(AslParser::WriteStringContext *ctx) {
    DEBUG_ENTER();
}
void CodeGenListener::exitWriteString(AslParser::WriteStringContext *ctx) {
	instructionList code;
	std::string s = ctx->STRING()->getText();
	std::string temp = "%"+codeCounters.newTEMP();
	int i = 1;
	while (i < int(s.size())-1) {
		if (s[i] != '\\') {
			code = code ||
			instruction::CHLOAD(temp, s.substr(i,1)) ||
			instruction::WRITEC(temp);
			i += 1;
		}
		else {
			assert(i < int(s.size())-2);
			if (s[i+1] == 'n') {
				code = code || instruction::WRITELN();
				i += 2;
			}
			else if (s[i+1] == 't' or s[i+1] == '"' or s[i+1] == '\\') {
				code = code ||
				instruction::CHLOAD(temp, s.substr(i,2)) ||
				instruction::WRITEC(temp);
				i += 2;
			}
			else {
				code = code ||
				instruction::CHLOAD(temp, s.substr(i,1)) ||
				instruction::WRITEC(temp);
				i += 1;
			}
		}
	}
	putCodeDecor(ctx, code);
	DEBUG_EXIT();
}
/*
void CodeGenListener::enterRetF(AslParser::RetFContext *ctx) {}
void CodeGenListener::exitRetF(AslParser::RetFContext *ctx) {
	putCodeDecor(ctx, getCodeDecor(ctx->retFunc()));
	putAddrDecor(ctx, getAddrDecor(ctx->retFunc()));
	putOffsetDecor(ctx, getOffsetDecor(ctx->retFunc()));
}
*/
void CodeGenListener::enterRetFunc(AslParser::RetFuncContext *ctx) {}
void CodeGenListener::exitRetFunc(AslParser::RetFuncContext *ctx) {
	if (ctx->expr()) {
		instructionList code = getCodeDecor(ctx->expr());
    	string temp = getAddrDecor(ctx->expr());
    	code = code || instruction::LOAD("_result", temp);
    	putCodeDecor(ctx, code);
	}
}

void CodeGenListener::enterLeft_expr(AslParser::Left_exprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitLeft_expr(AslParser::Left_exprContext *ctx) {
	if (ctx->arrayConstruct()) {
		/*
		TypesMgr::TypeId t   = getTypeDecor(ctx->arrayConstruct()->ident());
		instructionList code = getCodeDecor(ctx->arrayConstruct()->expr());
		string          addr = getAddrDecor(ctx->arrayConstruct()->expr());
		string          addi = getAddrDecor(ctx->arrayConstruct()->ident());
		size_t          size = Types.getArraySize(t);

		 l'offset s'obte de multiplicar la mida pel contingut de l'expr 
		string          tmp    = "%"+codeCounters.newTEMP();
		string          offset = "%"+codeCounters.newTEMP();
		code = code || instruction::ILOAD(tmp, to_string(size));
		code = code || instruction::MUL(offset, tmp, addr);
		*/
		putAddrDecor(ctx, getAddrDecor(ctx->arrayConstruct()));
		putOffsetDecor(ctx, getOffsetDecor(ctx->arrayConstruct()));
		putCodeDecor(ctx, getCodeDecor(ctx->arrayConstruct()));
	}
	else {
		putAddrDecor(ctx, getAddrDecor(ctx->ident()));
		putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
		putCodeDecor(ctx, getCodeDecor(ctx->ident()));
	}
}

void CodeGenListener::enterFuncExpr(AslParser::FuncExprContext *ctx) {}
void CodeGenListener::exitFuncExpr(AslParser::FuncExprContext *ctx) {    
    string          addr = getAddrDecor(ctx->funcConstruct());
    instructionList code = getCodeDecor(ctx->funcConstruct());
    putCodeDecor(ctx, code);
    putAddrDecor(ctx, addr);
    
}

void CodeGenListener::enterFuncConstruct(AslParser::FuncConstructContext *ctx) {}
void CodeGenListener::exitFuncConstruct(AslParser::FuncConstructContext *ctx) {
    instructionList code = instructionList();
    std::string   name = ctx->ident()->ID()->getText();
    string        addr = getAddrDecor(ctx->ident());
    TypesMgr::TypeId t = getTypeDecor(ctx->ident());

    if (not Types.isVoidFunction(t)) {
    	code = code || instruction::PUSH();
    }

    if (ctx->exprFunc()) {
    	int i = 0;
    	for (auto ct:ctx->exprFunc()->expr()) {
    		// Per cada parametre obtenim el codi i l'adreça i fem un push
    		instructionList codeParam = getCodeDecor(ct);
    		string              addrP = getAddrDecor(ct);
    		TypesMgr::TypeId     tPar = getTypeDecor(ct);
    		TypesMgr::TypeId     tCal = Types.getParameterType(t, i++);

    		if (Types.isFloatTy(tCal) and Types.isIntegerTy(tPar)) {
    			string tmpAddr = "%"+codeCounters.newTEMP();
    			codeParam = codeParam || instruction::FLOAT(tmpAddr, addrP);
    			addrP = tmpAddr;
    		}

    		if (Types.isArrayTy(tCal)) {
    			string tmpAddr = "%"+codeCounters.newTEMP();
    			codeParam = codeParam || instruction::ALOAD(tmpAddr, addrP);
    			addrP = tmpAddr;	
    		}

    		code = code || codeParam || instruction::PUSH(addrP);
    	}
   	    code = code || instruction::CALL(name);
	    for (auto ct:ctx->exprFunc()->expr()) {
	    	code = code || instruction::POP();
	    }
		if (not Types.isVoidFunction(t)) {
			string tmpAddr = "%"+codeCounters.newTEMP();
	    	code = code || instruction::POP(tmpAddr);
	    	putAddrDecor(ctx, tmpAddr);
	    }    
	    putCodeDecor(ctx, code);
    }
    
    else {
    	code = code || instruction::CALL(name);
    	putCodeDecor(ctx, code);
    }
    DEBUG_EXIT();
}

void CodeGenListener::enterArrayExpr(AslParser::ArrayExprContext *ctx) {}
void CodeGenListener::exitArrayExpr(AslParser::ArrayExprContext *ctx) {
	instructionList  code = getCodeDecor(ctx->arrayConstruct());
	string           addr = getAddrDecor(ctx->arrayConstruct());
	string           offs = getOffsetDecor(ctx->arrayConstruct());
	//TypesMgr::TypeId type = getTypeDecor(ctx->arrayConstruct());

	string tmp = "%"+codeCounters.newTEMP();
	if (not Symbols.isParameterClass(ctx->arrayConstruct()->ident()->getText())) {
		code = code || instruction::LOADX(tmp, addr, offs);
	}
	else {
		code = code || instruction::LOAD(tmp, addr);
		code = code || instruction::LOADX(tmp, tmp, offs);
	}

	putAddrDecor(ctx, tmp);
	putCodeDecor(ctx, code);
	putOffsetDecor(ctx, offs);
}

void CodeGenListener::enterArrayConstruct(AslParser::ArrayConstructContext *ctx) {}
void CodeGenListener::exitArrayConstruct(AslParser::ArrayConstructContext *ctx) {
	string           addr = getAddrDecor(ctx->expr());
	string           addi = getAddrDecor(ctx->ident());
	instructionList  code = getCodeDecor(ctx->expr());
	TypesMgr::TypeId type = getTypeDecor(ctx->ident());
	size_t           size = Types.getSizeOfType(Types.getArrayElemType(type));

	//string tmp = "%"+codeCounters.newTEMP();
	string off = "%"+codeCounters.newTEMP();
	code = code || instruction::ILOAD(off, to_string(size));
	code = code || instruction::MUL(off, off, addr);
	// addi[off]
	//code = code || instruction::LOADX(tmp, addi, off);

	putCodeDecor(ctx, code);
	putAddrDecor(ctx, addi);
	putOffsetDecor(ctx, off);
}

void CodeGenListener::enterArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitArithmetic(AslParser::ArithmeticContext *ctx) {
    std::string     addr1 = getAddrDecor(ctx->expr(0));
    instructionList code1 = getCodeDecor(ctx->expr(0));
    std::string     addr2 = getAddrDecor(ctx->expr(1));
    instructionList code2 = getCodeDecor(ctx->expr(1));
    instructionList code  = code1 || code2;
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    std::string temp = "%"+codeCounters.newTEMP();

    if (Types.isIntegerTy(getTypeDecor(ctx))){// TODO: keep doing...
        //Both parameters ARE integers
        if (ctx->MUL())
            code = code || instruction::MUL(temp, addr1, addr2);
        else if (ctx->PLUS())
            code = code || instruction::ADD(temp, addr1, addr2);
        else if (ctx->MINUS())
            code = code || instruction::SUB(temp, addr1, addr2);
        else if (ctx->DIV())
            code = code || instruction::DIV(temp, addr1, addr2);
        else if (ctx->MOD()) {
            std::string temp1 = "%"+codeCounters.newTEMP();
            std::string temp2 = "%"+codeCounters.newTEMP();
            code = code || instruction::DIV(temp1, addr1, addr2);
            code = code || instruction::MUL(temp2, temp1, addr2);
            code = code || instruction::SUB(temp, addr1, temp2);
        }
    } 
    else {
        std::string faddr1, faddr2;

        if (Types.isIntegerTy(getTypeDecor(ctx->expr(0))) ){
            faddr1 = "%"+codeCounters.newTEMP();
            faddr2 = addr2;
            code = code || instruction::FLOAT(faddr1, addr1);
        }
        else if (Types.isIntegerTy(getTypeDecor(ctx->expr(1))) ){
            faddr1 = addr1;
            faddr2 = "%"+codeCounters.newTEMP();
            code = code || instruction::FLOAT(faddr2, addr2);
        }
        else {
            faddr1 = addr1;
            faddr2 = addr2;
        }

        if (ctx->MUL())
            code = code || instruction::FMUL(temp, faddr1, faddr2);
        else if (ctx->PLUS())
            code = code || instruction::FADD(temp, faddr1, faddr2);
        else if (ctx->MINUS())
            code = code || instruction::FSUB(temp, faddr1, faddr2);
        else if (ctx->DIV())
            code = code || instruction::FDIV(temp, faddr1, faddr2);

    }  
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
}

void CodeGenListener::enterRelational(AslParser::RelationalContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitRelational(AslParser::RelationalContext *ctx) {
    std::string     addr1 = getAddrDecor(ctx->expr(0));
    instructionList code1 = getCodeDecor(ctx->expr(0));
    std::string     addr2 = getAddrDecor(ctx->expr(1));
    instructionList code2 = getCodeDecor(ctx->expr(1));
    instructionList code  = code1 || code2;
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

    std::string temp = "%"+codeCounters.newTEMP();
    if ((Types.isIntegerTy(t1) and Types.isIntegerTy(t2)) or (Types.isCharacterTy(t1) and Types.isCharacterTy(t2))) {
        if (ctx->LE()) {
            code = code || instruction::LE(temp, addr1, addr2);
        }
        else if (ctx->EQ()) {
            code = code || instruction::EQ(temp, addr1, addr2);
        }
        else if (ctx->NEQ()) {
            string temp1 = "%"+codeCounters.newTEMP();
            code = code || instruction::EQ(temp1, addr1, addr2);
            code = code || instruction::NOT(temp, temp1);
        }
        else if (ctx->LT()) {
            code = code || instruction::LT(temp, addr1, addr2);
        }
        else if (ctx->GE()) {
            string temp1 = "%"+codeCounters.newTEMP();
            code = code || instruction::LT(temp1, addr1, addr2);
            code = code || instruction::NOT(temp, temp1);
        }
        else { //ctx->GT
            string temp1 = "%"+codeCounters.newTEMP();
            code = code || instruction::LE(temp1, addr1, addr2);
            code = code || instruction::NOT(temp, temp1);
        }
    }
    else if (Types.isBooleanTy(t1) and Types.isBooleanTy(t2)) {
        if (ctx->EQ()) {
            code = code || instruction::EQ(temp, addr1, addr2);
        }
        else {
            string temp1 = "%"+codeCounters.newTEMP();
            code = code || instruction::EQ(temp1, addr1, addr2);
            code = code || instruction::NOT(temp, temp1);
        }
    }
    else {
        string faddr1, faddr2;
        if (Types.isIntegerTy(t1)) {
            faddr1 = "%"+codeCounters.newTEMP();
            faddr2 = addr2;
            code = code || instruction::FLOAT(faddr1, addr1);
        }
        else if (Types.isIntegerTy(t2)) {
            faddr2 = "%"+codeCounters.newTEMP();
            faddr1 = addr1;
            code = code || instruction::FLOAT(faddr2, addr2);   
        }
        else {
            faddr2 = addr2;
            faddr1 = addr1;
        }
        if (ctx->LE()) {
            code = code || instruction::FLE(temp, faddr1, faddr2);
        }
        else if (ctx->EQ()) {
            code = code || instruction::FEQ(temp, faddr1, faddr2);
        }
        else if (ctx->NEQ()) {
            string temp1 = "%"+codeCounters.newTEMP();
            code = code || instruction::FEQ(temp1, faddr1, faddr2);
            code = code || instruction::NOT(temp, temp1);
        }
        else if (ctx->LT()) {
            code = code || instruction::FLT(temp, faddr1, faddr2);
        }
        else if (ctx->GE()) {
            string temp1 = "%"+codeCounters.newTEMP();
            code = code || instruction::FLT(temp1, faddr1, faddr2);
            code = code || instruction::NOT(temp, temp1);
        }
        else { //ctx->GT
            string temp1 = "%"+codeCounters.newTEMP();
            code = code || instruction::FLE(temp1, faddr1, faddr2);
            code = code || instruction::NOT(temp, temp1);
        }
    }

    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterBooleanExpr(AslParser::BooleanExprContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitBooleanExpr(AslParser::BooleanExprContext *ctx) {
    std::string     addr1 = getAddrDecor(ctx->expr(0));
    instructionList code1 = getCodeDecor(ctx->expr(0));
    std::string     addr2 = getAddrDecor(ctx->expr(1));
    instructionList code2 = getCodeDecor(ctx->expr(1));
    instructionList code  = code1 || code2;
    // TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    // TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    // TypesMgr::TypeId t  = getTypeDecor(ctx);
    std::string temp = "%"+codeCounters.newTEMP();
    if (ctx->AND()) 
        code = code || instruction::AND(temp, addr1, addr2);
    else 
        code = code || instruction::OR(temp, addr1, addr2);

    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterParExpr(AslParser::ParExprContext *ctx) {}
void CodeGenListener::exitParExpr(AslParser::ParExprContext *ctx) {
    string          addr = getAddrDecor(ctx->expr());
    instructionList code = getCodeDecor(ctx->expr());

    putOffsetDecor(ctx, "");
    putAddrDecor(ctx,addr);
    putCodeDecor(ctx,code);
}

void CodeGenListener::enterUnaryExpr(AslParser::UnaryExprContext *ctx) {}
void CodeGenListener::exitUnaryExpr(AslParser::UnaryExprContext *ctx) {
    string          addr = getAddrDecor(ctx->expr());
    instructionList code = getCodeDecor(ctx->expr());
    TypesMgr::TypeId t   = getTypeDecor(ctx->expr());

    string temp;
    if (Types.isIntegerTy(t)) {
        if (ctx->MINUS()) {
            temp = "%"+codeCounters.newTEMP();
            code = code || instruction::NEG(temp, addr);
        }
        else if (ctx->PLUS()) {
            temp = addr;
        }
    }
    else if (Types.isFloatTy(t)) {
        if (ctx->MINUS()) {
            temp = "%"+codeCounters.newTEMP();
            code = code || instruction::FNEG(temp, addr);
        }
        else if (ctx->PLUS()) {
            temp = addr;
        }
    }
    else {
        if (ctx->NOT()) {
            temp = "%"+codeCounters.newTEMP();
            code = code || instruction::NOT(temp, addr);
        }
    }

    putOffsetDecor(ctx, "");
    putAddrDecor(ctx,temp);
    putCodeDecor(ctx,code);
}

void CodeGenListener::enterAtomExpr(AslParser::AtomExprContext *ctx) {}
void CodeGenListener::exitAtomExpr(AslParser::AtomExprContext *ctx) {
    putCodeDecor(ctx, getCodeDecor(ctx->atom()));
    putAddrDecor(ctx, getAddrDecor(ctx->atom()));
    putOffsetDecor(ctx, getOffsetDecor(ctx->atom()));
}

//void CodeGenListener::enterParExpr(AslParser::ParExprContext *ctx) {}
//void CodeGenListener::exitParExpr(AslParser::ParExprContext *ctx) {}

void CodeGenListener::enterAtom(AslParser::AtomContext *ctx) {}
void CodeGenListener::exitAtom(AslParser::AtomContext *ctx) {
    if (ctx->boolExpr()) {
        putCodeDecor(ctx, getCodeDecor(ctx->boolExpr()));
        putAddrDecor(ctx, getAddrDecor(ctx->boolExpr()));
        putOffsetDecor(ctx, getOffsetDecor(ctx->boolExpr()));
    }
    else if (ctx->value()) {
        putCodeDecor(ctx, getCodeDecor(ctx->value()));
        putAddrDecor(ctx, getAddrDecor(ctx->value()));
        putOffsetDecor(ctx, getOffsetDecor(ctx->value()));
    }
    else if (ctx->chart()) {
        putCodeDecor(ctx, getCodeDecor(ctx->chart()));
        putAddrDecor(ctx, getAddrDecor(ctx->chart()));
        putOffsetDecor(ctx, getOffsetDecor(ctx->chart()));
    }
    else if (ctx->fval()) {
        putCodeDecor(ctx, getCodeDecor(ctx->fval()));
        putAddrDecor(ctx, getAddrDecor(ctx->fval()));
        putOffsetDecor(ctx, getOffsetDecor(ctx->fval()));    
    }
}

void CodeGenListener::enterValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitValue(AslParser::ValueContext *ctx) {
    instructionList code;
    std::string temp = "%"+codeCounters.newTEMP();
    code = instruction::ILOAD(temp, ctx->getText());
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterChart(AslParser::ChartContext *ctx) {}
void CodeGenListener::exitChart(AslParser::ChartContext *ctx) {
    instructionList code;
    std::string temp = "%"+codeCounters.newTEMP();
    code = instruction::CHLOAD(temp, ctx->ID()->getText());
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterBoolExpr(AslParser::BoolExprContext *ctx) {}
void CodeGenListener::exitBoolExpr(AslParser::BoolExprContext *ctx) {
    instructionList code;
    std::string temp = "%"+codeCounters.newTEMP();
    string boolVal = "0";
    if (ctx->getText() == "true") boolVal = "1";
    code = instruction::ILOAD(temp, boolVal);
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterFval(AslParser::FvalContext *ctx) {}
void CodeGenListener::exitFval(AslParser::FvalContext *ctx) {
    instructionList code;
    std::string temp = "%"+codeCounters.newTEMP();
    code = instruction::FLOAD(temp, ctx->getText());
    putAddrDecor(ctx, temp);
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, code);
    DEBUG_EXIT();
}

void CodeGenListener::enterExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
}
void CodeGenListener::exitExprIdent(AslParser::ExprIdentContext *ctx) {
    putAddrDecor(ctx, getAddrDecor(ctx->ident()));
    putOffsetDecor(ctx, getOffsetDecor(ctx->ident()));
    putCodeDecor(ctx, getCodeDecor(ctx->ident()));
    DEBUG_EXIT();
}

void CodeGenListener::enterIdent(AslParser::IdentContext *ctx) {
    DEBUG_ENTER();
}
void CodeGenListener::exitIdent(AslParser::IdentContext *ctx) {
    putAddrDecor(ctx, ctx->ID()->getText());
    putOffsetDecor(ctx, "");
    putCodeDecor(ctx, instructionList());
    DEBUG_EXIT();
}

// void CodeGenListener::enterEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_ENTER();
// }
// void CodeGenListener::exitEveryRule(antlr4::ParserRuleContext *ctx) {
//   DEBUG_EXIT();
// }
// void CodeGenListener::visitTerminal(antlr4::tree::TerminalNode *node) {
//   DEBUG(">>> visit " << node->getSymbol()->getLine() << ":" << node->getSymbol()->getCharPositionInLine() << " CodeGen TerminalNode");
// }
// void CodeGenListener::visitErrorNode(antlr4::tree::ErrorNode *node) {
// }


// Getters for the necessary tree node atributes:
//   Scope, Type, Addr, Offset and Code
SymTable::ScopeId CodeGenListener::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenListener::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
std::string CodeGenListener::getAddrDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getAddr(ctx);
}
std::string  CodeGenListener::getOffsetDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getOffset(ctx);
}
instructionList CodeGenListener::getCodeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getCode(ctx);
}

// Setters for the necessary tree node attributes:
//   Addr, Offset and Code
void CodeGenListener::putAddrDecor(antlr4::ParserRuleContext *ctx, const std::string & a) {
  Decorations.putAddr(ctx, a);
}
void CodeGenListener::putOffsetDecor(antlr4::ParserRuleContext *ctx, const std::string & o) {
  Decorations.putOffset(ctx, o);
}
void CodeGenListener::putCodeDecor(antlr4::ParserRuleContext *ctx, const instructionList & c) {
  Decorations.putCode(ctx, c);
}
