

grammar json;

// The grammar start symbol expected by main.cpp is 'json'
// If you change it, adapt main.cpp accordingly.
json : objecte
	 ;

objecte	
		: string
		| llista
		| diccionari
		;

string 
		: ATOM
		;

llista
		: CL objecte (CM objecte)* CR		# list
		;

diccionari
		: KL elem_dic (CM elem_dic)* KR		# dict
		;

elem_dic
		: string PD objecte
		;

// [ object ]

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
//AP 		  : '"' ;
//ID        : ('a'..'z'|'A'..'Z'|'_'|','|' ')* ;
//INTVAL    : ('0'..'9')+ ;
/// strings in double quotes are json tokens (apart from brackets, commas, colons, etc.)
ATOM 	  : '"' ~["]* '"';

/// skip white spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;