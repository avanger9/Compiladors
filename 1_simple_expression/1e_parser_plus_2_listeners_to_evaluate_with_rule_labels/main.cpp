
#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseListener.h"
#include "tree/ParseTreeWalker.h"
#include "tree/ParseTreeProperty.h"

#include <iostream>
#include <fstream>
#include <stack>
#include <cstdio>    // fopen

// using namespace std;
// using namespace antlr4;


//////////////////////////////////////////////////////////////////////
// Sample "calculator" (special case of collector)
class Evaluator : public ExprBaseListener {
public:
  std::stack<int> stack;

  void exitProd(ExprParser::ProdContext *ctx) {  // e : e MULT e ;
    int right = stack.top();
    stack.pop();
    int left = stack.top();
    stack.pop();
    stack.push(left*right);
  }

  void exitPlus(ExprParser::PlusContext *ctx) {  // e : e ADD e ;
    int right = stack.top();
    stack.pop();
    int left = stack.top();
    stack.pop();
    stack.push(left+right);
  }

  void exitValue(ExprParser::ValueContext *ctx) {  // e : INT ;
    int val = std::stoi(ctx->INT()->getText());  // or: ctx->getText()
    stack.push(val);
  }

};
// Sample "calculator" (special case of collector)
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// Sample "calculator" using tree properties not stack
class EvaluatorWithProps : public ExprBaseListener {
public:
  antlr4::tree::ParseTreeProperty<int> values;

  void exitS(ExprParser::SContext *ctx) {  // s : e ;
    values.put(ctx, values.get(ctx->e()));
  }

  void exitProd(ExprParser::ProdContext *ctx) {  // e : e MULT e ;
    int left = values.get(ctx->e(0));
    int right = values.get(ctx->e(1));
    values.put(ctx, left*right);
  }

  void exitPlus(ExprParser::PlusContext *ctx) {  // e : e ADD e ;
    int left = values.get(ctx->e(0));
    int right = values.get(ctx->e(1));
    values.put(ctx, left+right);
  }

  void exitValue(ExprParser::ValueContext *ctx) {  // e : INT ;
    int val = std::stoi(ctx->INT()->getText());  // or: ctx->getText()
    values.put(ctx, val);
  }

};
// Sample "calculator" using tree properties not stack
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
  
  // Create a first listener (with stack) that will evaluate the expression
  Evaluator eval;

  // Traverse the tree using this Evaluator  
  walker.walk(&eval, tree);

  // Dump the result (on top of the stack)
  std::cout << "result = " << eval.stack.top() << std::endl;
  
  // Create a second listener (with Properties) that will evaluate the expression
  EvaluatorWithProps eval2;

  // Traverse the tree using this EvaluatorWithProps
  walker.walk(&eval2, tree);

  // Dump the result (accessing the root node property)
  std::cout << "result with tree props = " << eval2.values.get(tree) << std::endl;

  return EXIT_SUCCESS;
}
