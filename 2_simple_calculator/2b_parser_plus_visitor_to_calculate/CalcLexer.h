
// Generated from Calc.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  CalcLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, MUL = 2, DIV = 3, ADD = 4, MIN = 5, PL = 6, PR = 7, NOT = 8, 
    OR = 9, AND = 10, LT = 11, GT = 12, EQ = 13, ID = 14, INT = 15, NEWLINE = 16, 
    WS = 17
  };

  CalcLexer(antlr4::CharStream *input);
  ~CalcLexer();

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
