//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
//
//    Copyright (C) 2017  Universitat Politecnica de Catalunya
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
//    contact: José Miguel Rivero (rivero@cs.upc.es)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' funcParams? ')' funcType? declarations statements ENDFUNC 
        ;

funcParams : ID ':' typeR (',' ID ':' typeR)* ;
funcType : ':' type ;

//retFunc: RETURN expr? ;

declarations  : (variable_decl)* ;

variable_decl : VAR ID (',' ID)* ':' typeR ;

typeR   : type | array ;

array   : ARRAY '[' expr ']' 'of' type ;
type    : INT | CHAR | FLOAT | BOOL ;


statements : (statement)* ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'           			# assignStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements elseStat? ENDIF       # ifStmt
        | WHILE expr DO statements ENDWHILE   # whileStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | funcConstruct ';'                   			# procCall
          // Read a variable
        | READ left_expr ';'                  			# readStmt
          // Write an expression
        | WRITE expr ';'                      			# writeExpr
          // Write a string
        | WRITE STRING ';'                    			# writeString
        | RETURN expr? ';' 								# retFunc
        ;
// Grammar for left expressions (l-values in C++)
left_expr 
		: ident 
		| arrayConstruct ;

elseStat : ELSE statements ;
//retFunc : RETURN expr? ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    
        : op=(NOT|MINUS|PLUS) expr            # unaryExpr
        | expr op=(MUL|DIV|MOD) expr          # arithmetic
        | expr op=(PLUS|MINUS) expr           # arithmetic
        | expr op=(LT|LE|GE|GT) expr          # relational
        | expr op=(EQ|NEQ) expr               # relational
        | expr op=AND expr                    # booleanExpr
        | expr op=OR  expr                    # booleanExpr
        | '(' expr ')' 						  # parExpr
        | atom                                # atomExpr
        | ident                               # exprIdent
        | arrayConstruct                      # arrayExpr
        | funcConstruct                       # funcExpr
        ;

arrayConstruct: ident '[' expr ']' ;
funcConstruct: ident '(' exprFunc? ')' ;
exprFunc: expr (',' expr)* ;

atom
        : boolExpr
        | chart
        | value
        | fval
        ;

chart   : CHARVAL ;
//cchart  : ID ;
value   : INTVAL ;
fval    : INTVAL '.' INTVAL ;
boolExpr: TRUE | FALSE ;
ident   : ID ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

ASSIGN    : '=' ;
EQ        : '==' ;
NEQ       : '!=' ;
GT        : '>' ;
GE        : '>=' ;
LT        : '<' ;
AP        : '"' ;
AT        : '\'' ;
LE        : '<=' ;
LP        : '(' ;
RP        : ')' ;
LSQ       : '[' ;
RSQ       : ']' ;
KEYL      : '{' ;
KEYR      : '}' ;
COLON     : ':' ;
SCOLON    : ';' ;
DOT       : '.' ;
COMMA     : ',' ;
HASH      : '#' ;
PLUS      : '+' ;
MUL       : '*' ;
MINUS     : '-' ;
DIV       : '/' ;
MOD       : '%' ;
AND       : 'and' ;
OR        : 'or' ;
NOT       : 'not' ;
VAR       : 'var' ; 
INT       : 'int' ;
FLOAT     : 'float' ;
BOOL      : 'bool' ;
CHAR      : 'char' ;
TRUE      : 'true' ;
FALSE     : 'false' ;
ARRAY     : 'array' ;
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
WHILE     : 'while' ;
DO        : 'do' ;
ENDWHILE  : 'endwhile' ;
ENDIF     : 'endif' ;
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
RETURN    : 'return' ;
READ      : 'read' ;
WRITE     : 'write' ;
//IDC       : '\'' ('a'..'z') '\'' ;
CHARVAL   : '\'' (ESC_SEQ | ~('\'' | '\\')) '\'';
ID        : ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;
INTVAL    : ('0'..'9')+ ;

// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style)
COMMENT   : '//' ~('\n'|'\r')* '\r'? '\n' -> skip ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// WS        : [ \t\r\n]+ -> skip ;

/*

void enterfff(AslParser::fffContext *ctx);
	void exitfff(AslParser::fffContext *ctx);

void TypeCheckListener::enterfff(AslParser::fffContext *ctx) {}
void TypeCheckListener::exitfff(AslParser::fffContext *ctx) {}

void CodeGenListener::enterfff(AslParser::fffContext *ctx) {}
void CodeGenListener::exitfff(AslParser::fffContext *ctx) {}

void SymbolsListener::enterfff(AslParser::fffContext *ctx) {}
void SymbolsListener::exitfff(AslParser::fffContext *ctx) {}

*/