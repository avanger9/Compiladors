grammar Calc;

prog:   stat+ EOF ;

stat:   expr NEWLINE                # printExpr
    |   ID '=' expr NEWLINE         # assign
    |   NEWLINE                     # blank
    ;

expr:   PL expr PR 					# Parenthesis
	|	NOT expr 					# Not
	|   expr (MUL|DIV) expr         # prodDiv
    |   expr (ADD|MIN) expr         # plusMinus
    |	expr (LT|GT|EQ)   expr 		# ltgt
    |	expr OR  expr 				# Or
    |	expr AND expr 				# And
    |   INT                         # int
    |   ID                          # id
    ;

MUL :    '*' ;
DIV :    '/' ;
ADD :    '+' ;
MIN :    '-' ;
PL  :	 '(' ;
PR  :	 ')' ;
NOT :	 '!' ;
OR  :	 '|' ;
AND :	 '&' ;
LT  :	 '<' ;
GT	:	 '>' ;
EQ 	:	 '==';
ID  :    [a-zA-Z]+ ;      // match identifiers
INT :    [0-9]+ ;         // match integers
NEWLINE: '\r'? '\n' ;     // return newlines to parser (is end-statement signal)
WS  :    [ \t]+ -> skip ; // toss out whitespace