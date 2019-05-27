
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, ASSIGN = 4, EQ = 5, NEQ = 6, GT = 7, GE = 8, 
    LT = 9, AP = 10, AT = 11, LE = 12, LP = 13, RP = 14, LSQ = 15, RSQ = 16, 
    KEYL = 17, KEYR = 18, COLON = 19, SCOLON = 20, DOT = 21, COMMA = 22, 
    HASH = 23, PLUS = 24, MUL = 25, MINUS = 26, DIV = 27, MOD = 28, AND = 29, 
    OR = 30, NOT = 31, VAR = 32, INT = 33, FLOAT = 34, BOOL = 35, CHAR = 36, 
    TRUE = 37, FALSE = 38, ARRAY = 39, FIRST = 40, SECOND = 41, IF = 42, 
    THEN = 43, ELSE = 44, WHILE = 45, DO = 46, ENDWHILE = 47, ENDIF = 48, 
    FUNC = 49, ENDFUNC = 50, RETURN = 51, READ = 52, WRITE = 53, ID = 54, 
    INTVAL = 55, STRING = 56, COMMENT = 57, WS = 58
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

