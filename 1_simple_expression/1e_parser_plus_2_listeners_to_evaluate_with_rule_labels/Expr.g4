grammar Expr;

s : e EOF ;
e : e MULT e    # prod
  | e ADD e     # plus
  | INT         # value
  ;

MULT: '*' ;
ADD : '+' ;
INT : [0-9]+ ;
WS : [ \t\n]+ -> skip ;
