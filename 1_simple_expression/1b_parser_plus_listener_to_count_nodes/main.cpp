
#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseListener.h"
#include "tree/ParseTreeWalker.h"

#include <iostream>
#include <fstream>
#include <cstdio>    // fopen

// using namespace std;
// using namespace antlr4;


//////////////////////////////////////////////////////////////////////
// Sample information "collector"
class NodeCounterListener : public ExprBaseListener {
public:
  int interior = 0;
  int leaves = 0;

  void enterEveryRule(antlr4::ParserRuleContext *ctx) {
    interior++;
  }

  void visitTerminal(antlr4::tree::TerminalNode *node) {
    leaves++;
  }
};
// Sample information "collector"
//////////////////////////////////////////////////////////////////////


int main(int argc, const char* argv[]) {
  // check the correct use of the program
  if (argc > 2) {
    std::cout << "Usage: ./main [<file>]" << std::endl;
    return EXIT_FAILURE;
  }
  if (argc == 2 and not std::fopen(argv[1], "r")) {
    std::cout << "No such file: " << argv[1] << std::endl;
    return EXIT_FAILURE;
  }

  // open input file (or std::cin) and create a character stream
  antlr4::ANTLRInputStream input;
  if (argc == 2) {  // reads from <file>
    std::ifstream stream;
    stream.open(argv[1]);
    input = antlr4::ANTLRInputStream(stream);
  }
  else {            // reads fron std::cin
    input = antlr4::ANTLRInputStream(std::cin);
  }

  // create a lexer that consumes the character stream and produce a token stream
  ExprLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  // create a parser that consumes the token stream, and parses it.
  ExprParser parser(&tokens);

  // call the parser and get the parse tree
  antlr4::tree::ParseTree *tree = parser.s();

  // check for lexical or syntactical errors
  if (lexer.getNumberOfSyntaxErrors() > 0 or
      parser.getNumberOfSyntaxErrors() > 0) {
    std::cout << "Lexical and/or syntactical errors have been found." << std::endl;
    return EXIT_FAILURE;
  }
  
  // print the parse tree (for debugging purposes)
  std::cout << tree->toStringTree(&parser) << std::endl;

  ////////////////////////////////////////////////////////////////////
  
  // create a walker that will traverse the tree
  antlr4::tree::ParseTreeWalker walker;
  
  // Create a listener that counts interior and leave nodes
  NodeCounterListener counter;
  
  // Traverse the tree using this listener
  walker.walk(&counter, tree);

  // Dump collected information
  std::cout << counter.interior << " interior nodes" << std::endl;
  std::cout << counter.leaves << " leaf nodes" << std::endl;

  return EXIT_SUCCESS;
}
