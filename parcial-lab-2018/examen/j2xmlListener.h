
#pragma once

#include "antlr4-runtime.h"
#include "jsonBaseListener.h"


class  j2xmlListener : public jsonBaseListener {

 private:
  // Use this property to create the XML at every node,
  // so the parent node can access it and compose the result appropriately.
  // -- Remember that you can set/get the property for each node with get/put methods, e.g.:
  // --     string s = XML.get(ctx);
  // --     XML.put(ctx, s);

  antlr4::tree::ParseTreeProperty<std::string> XML;

  // You may need to define other property maps to store other
  // information for some nodes:
  // antlr4::tree::ParseTreeProperty<some_type> something;
  
 public:

  // You'll need to declare here the methods from jsonBaseListener 
  // abstract class that you need to overwrite. (these are just examples,
  // adjust at will)

  //void exitDict(jsonParser::DictContext * ctx);
  //void exitList(jsonParser::ListContext * ctx);
  //void exitPair(jsonParser::PairContext * ctx);
  // ...

};

