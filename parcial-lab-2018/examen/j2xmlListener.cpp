
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
//void j2xmlListener::exitDict(jsonParser::DictContext * ctx) {

//}

// -------------------------------------------------------------
//void j2xmlListener::exitList(jsonParser::ListContext * ctx)  {

//}

// -------------------------------------------------------------
//void j2xmlListener::exitPair(jsonParser::PairContext * ctx) {

//}
