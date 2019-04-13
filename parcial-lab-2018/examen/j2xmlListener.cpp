
#include "j2xmlListener.h"

using namespace std;

/// utility function, handy to remove quotes from a json string
string remove_quotes (const string &s) {
	if (s.length() < 2) return s;
	else return s.substr(1,s.length()-2);
}

/////////////////////////////////////////////////////////////////
/// Implementation of the methods from the base listener
/// overwritten by j2xmlListener.h
/// (these are just examples, adjust at will)

// -------------------------------------------------------------
void j2xmlListener::enterList(jsonParser::ListContext *ctx) {
	if (XML.get(ctx)==LLISTA) {
		cout<<"<ITEM>";
	}
	else if(XML.get(ctx)==VALOR) {
		cout<<">";
	}
	cout<<"<LIST>";
	for (auto x:ctx->objecte()) XML.put(x,LLISTA);
	//XML.put(ctx->objecte(),LLISTA);
}

void j2xmlListener::exitList(jsonParser::ListContext *ctx) {
	cout<<"</LIST>";
	if (XML.get(ctx)==LLISTA) {
		cout<<"</ITEM>";
	}
	else if(XML.get(ctx)==VALOR) {
		cout<<"</ENTRY>";
	}
}

void j2xmlListener::enterDict(jsonParser::DictContext *ctx) {
	if (XML.get(ctx)==LLISTA) {
		cout<<"<ITEM>";
	}
	else if(XML.get(ctx)==VALOR) {
		cout<<">";
	}
	cout<<"<DICT>";
	//for(auto x:ctx->elem_dic()) XML.put(x,DICT)
	//XML.put(ctx,DICT);
}

void j2xmlListener::exitDict(jsonParser::DictContext *ctx) {
	cout<<"</DICT>";
	if (XML.get(ctx)==LLISTA) {
		cout<<"</ITEM>";
	}
	else if(XML.get(ctx)==VALOR) {
		cout<<"</ENTRY>";
	}
}

void j2xmlListener::enterString(jsonParser::StringContext *ctx) {
	//cout<<"<ENTRY key="<<'"'<<remove_quotes(ctx->getText())<<'"'<<'>'<<endl;
	if (XML.get(ctx)==LLISTA) {
		cout<<"<ITEM value="<<'"'<<remove_quotes(ctx->getText())<<'"'<<"/>";
	}
	else if(XML.get(ctx)==DICT) {
		cout<<"ENTRY key="<<ctx->getText();
	}
	else if (XML.get(ctx)==VALOR) {
		cout<<" value="<<ctx->getText()<<"/>";
	}
	else cout<<ctx->getText();
}

void j2xmlListener::exitString(jsonParser::StringContext *ctx) {}

void j2xmlListener::enterObjecte(jsonParser::ObjecteContext *ctx) {
	//if (XML.get(ctx)==LLISTA) cout<<"
	auto x=XML.get(ctx);
	//XML.put(ctx->objecte,x);
	XML.put(ctx->llista(),x);
	XML.put(ctx->diccionari(),x);
	XML.put(ctx->string(),x);
}

void j2xmlListener::exitObjecte(jsonParser::ObjecteContext *ctx) {}

void j2xmlListener::enterElem_dic(jsonParser::Elem_dicContext *ctx){
	XML.put(ctx->string(),DICT);
	XML.put(ctx->objecte(),VALOR);
	cout<<"<";
}

void j2xmlListener::exitElem_dic(jsonParser::Elem_dicContext *ctx) {}

void j2xmlListener::enterJson(jsonParser::JsonContext *ctx) {
	cout<<"<OBJECT>";
}

void j2xmlListener::exitJson(jsonParser::JsonContext *ctx) {
	cout<<"</OBJECT>";
}

