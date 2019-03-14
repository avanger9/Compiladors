

grammar json;

// The grammar start symbol expected by main.cpp is 'json'
// If you change it, adapt main.cpp accordingly.
json : program+ EOF;

program
		: string
//		| list
//		| dict
		;

string 
		: AP ident AP
		;

ident
		: ID
		;

list
		: CL (listS)* CR
		;

listS
		: (CM|string)
		;

/// complete the grammar rules to parse json files
/// ...
/// ...


PR 		  : ')' ;
PL 		  : '(' ;
KL 		  : '{' ;
KR 		  : '}' ;
CL 		  : '[' ;
CR 		  : ']' ;
CM 		  : ',' ;
PD 		  : ':' ;
AP 		  : '"' ;
ID        : ('a'..'z'|'A'..'Z'|'_'|','|' ')* ;
INTVAL    : ('0'..'9')+ ;
/// strings in double quotes are json tokens (apart from brackets, commas, colons, etc.)
ATOM 	  : '"' ~["]* '"';

/// skip white spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;