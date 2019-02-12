grammar Expr;

s : e ;
e : e MULT e    // MULT is '*'
  | e ADD e     // ADD is '+'
  | INT
  ;

MULT: '*' ;
ADD : '+' ;
INT : [0-9]+ ;
WS : [ \t\n]+ -> skip ;
