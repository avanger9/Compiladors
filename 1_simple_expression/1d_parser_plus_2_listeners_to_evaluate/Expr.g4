grammar Expr;

s : e EOF ;
e : PL e PR 
  | e op=(MULT|DIV) e    // MULT is '*'
  | e op=(ADD|MINUS) e     // ADD is '+'
  | INT
  ;

MULT: '*' ;
ADD : '+' ;
MINUS: '-' ;
DIV: '/' ;
PL: '(' ;
PR: ')' ;
INT : [0-9]+ ;
WS : [ \t\n]+ -> skip ;
