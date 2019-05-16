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
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID LP funcInside? RP funcType? declarations statements ENDFUNC
        ;

funcInside
		: ID ':' type (funcInside2)*
		;

funcInside2 : ',' ID ':' type ;

funcType
		: ':' type 
		;

declarations
        : (variable_decl)*
        ;

variable_decl
        : VAR ID (',' ID)* ':' type
        ;

type    : (INT|CHAR|FLOAT|BOOL|ARRAY)
        ;

statements
        : (statement)*
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'           					# assignStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements (ELSE statement)? ENDIF       # ifStmt
        | WHILE expr DO statements ENDWHILE   					# whileStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | ident '(' ')' ';'                   					# procCall
          // Read a variable
        | READ left_expr ';'                  					# readStmt
          // Write an expression
        | WRITE expr ';'                      					# writeExpr
          // Write a string
        | WRITE STRING ';'                    					# writeString
        ;
// Grammar for left expressions (l-values in C++)
left_expr
        : ident
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    
		: ID LP exprFunc? RP				  # call
		| expr '[' expr ']' 				  # index
		| op=(NOT|MINUS) expr    	          # unaryExpr
        | expr op=(MUL|DIV|PER) expr          # multExpr
        | expr op=(PLUS|MINUS) expr           # addExpr
        | expr op=(LT|LE|GE|GT) expr   		  # relational
        | expr op=(EQ|NEQ)					  # equality
        | expr AND expr                       # andExpr
        | expr OR  expr                    	  # orExpr
        | ident                               # exprIdent
        | atom			                      # value
        ;

exprFunc : expr (',' expr)* ;

atom
		: LP expr RP
		| (val|fval)
		| (FALSE|TRUE)
		| chart
		| ident
		| STRING
		;


val     : INTVAL
        ;

chart   : AT ID AT
        ;

fval	: INTVAL DOT (INTVAL)*
		;

ident  : ID ; 

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

ASSIGN    : '=' ;
EQ        : '==' ;
NEQ       : '!=' ;
GT        : '>' ;
GE        : '>=' ;
LT        : '<' ;
AP		  : '"' ;
AT 		  : '\'' ;
LE        : '<=' ;
LP        : '(' ;
RP 		  : ')' ;
LSQ       : '[' ;
RSQ		  : ']' ;
KEYL      : '{' ;
KEYR	  : '}' ;
COLON     : ':' ;
SCOLON    : ';' ;
DOT		  : '.' ;
COMMA     : ',' ;
HASH      : '#' ;
PLUS      : '+' ;
MUL       : '*' ;
MINUS     : '-' ;
DIV       : '/' ;
PER       : '%' ;
AND       : 'and' ;
OR        : 'or' ;
NOT       : 'not' ;
VAR       : 'var' ; 
INT       : 'int' ;
FLOAT     : 'float' ;
BOOL      : 'bool' ;
CHAR      : 'char' ;
TRUE 	  : 'true' ;
FALSE	  : 'false' ;
TYPE      : (INT|CHAR|FLOAT|BOOL) ;
ARRAY     : 'array' LSQ INTVAL RSQ 'of' TYPE ;
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
WHILE	  : 'while' ;
DO 		  : 'do' ;
ENDWHILE  : 'endwhile' ;
ENDIF     : 'endif' ;
FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;
RETURN    : 'return' ;
READ      : 'read' ;
WRITE     : 'write' ;
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
