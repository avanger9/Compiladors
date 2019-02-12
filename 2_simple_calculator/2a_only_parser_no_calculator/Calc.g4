grammar Calc;

prog:   stat+ EOF ; 

stat:   expr NEWLINE                
    |   ID '=' expr NEWLINE        
    |   NEWLINE                   
    ;

expr:   expr MUL expr   
    |   expr ADD expr   
    |   INT               
    |   ID                    
    ;

MUL : '*' ;
ADD : '+' ;
ID  :   [a-zA-Z]+ ;      // match identifiers
INT :   [0-9]+ ;         // match integers
NEWLINE:'\r'? '\n' ;     // return newlines to parser (is end-statement signal)
WS  :   [ \t]+ -> skip ; // toss out whitespace
