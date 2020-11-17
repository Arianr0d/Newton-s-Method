#pragma once
#include <sstream>
#include <vector>
using namespace std;

enum class TokenType {
	Value,
	Variable,
	Operatop,
	Function,
	Paren_LEFT,
	Paren_RIGHT,
};

struct Token {
	const string val;
	const TokenType type;
};

vector<Token> Tokenize(istream &input);