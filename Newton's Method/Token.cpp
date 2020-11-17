#define _USE_MATH_DEFINES
#include "Token.h"
#include <stdexcept>
using namespace std;

vector<Token> Tokenize(istream &input) {
	vector<Token> tokens;
	char ch;
	while (input >> ch) {
		// определение константных выражений
		if ((isdigit(ch)) || (ch == '.')) {
			string values;
			while ((isdigit(input.peek())) || input.peek() == '.') {
				values += input.get();
			}
			tokens.push_back({values, TokenType::Value});
		}
		// определение функции
		else if (ch == 's') {
			if (input.get() == 'i' && input.get() == 'n') {
				tokens.push_back({ "sin", TokenType::Function});
			}
			else if (input.get() == 'q' && input.get() == 'r' && input.get() == 't') {
				tokens.push_back({ "sqrt", TokenType::Function });
			}
			else {
				throw logic_error("Unknow token");
			}
		}
		else if (ch == 'c') {
			if (input.get() == 'o' && input.get() == 's') {
				tokens.push_back({ "cos", TokenType::Function});
			}
			else if(input.get() == 't' && input.get() == 'a' && input.get() == 'n') {
				tokens.push_back({ "ctan", TokenType::Function});
			}
			else {
				throw logic_error("Unknow token");
			}
		}
		else if (ch == 't') {
			if (input.get() == 'a' && input.get() == 'n') {
				tokens.push_back({ "tan", TokenType::Function });
			}
			else {
				throw logic_error("Unknow token");
			}
		}
		else if (ch == 'a') {
			if (input.get() == 'c' && input.get() == 'o' && input.get() == 's') {
				tokens.push_back({ "acos", TokenType::Function });
			}
			else if (input.get() == 's' && input.get() == 'i' && input.get() == 'n') {
				tokens.push_back({ "asin", TokenType::Function});
			}
			else if (input.get() == 't' && input.get() == 'a' && input.get() == 'n') {
				tokens.push_back({ "atan", TokenType::Function });
			}
			else if (input.get() == 'c' && input.get() == 't' && input.get() == 'a' && input.get() == 'n') {
				tokens.push_back({ "actan", TokenType::Function });
			}
			else {
				throw logic_error("Unknow token");
			}
		}
		else if (ch == 'e') {
			if (input.get() == 'x' && input.get() == 'p') {
				tokens.push_back({ "exp", TokenType::Function});
			}
			else {
				throw logic_error("Unknow token");
			}
		}
		else if (ch == 'l') {
			if (input.get() == 'o' && input.get() == 'g' && input.get() == '1' && input.get() == '0') {
				tokens.push_back({ "log10", TokenType::Function});
			}
			else if (input.get() == 'o' && input.get() == 'g') {
				tokens.push_back({ "log", TokenType::Function });
			}
			else {
				throw logic_error("Unknow token");
			}
		}
		// определение переменной
		else if (ch == 'x') {
			tokens.push_back({ "x", TokenType::Variable });
		}
		// определение операций
		else if (ch == '*') {
			tokens.push_back({ "*", TokenType::Operatop});
		}
		else if (ch == '/') {
			tokens.push_back({ "/", TokenType::Operatop});
		}
		else if (ch == '%') {
			tokens.push_back({ "%", TokenType::Operatop});
		}
		else if (ch == '-') {
			tokens.push_back({ "-", TokenType::Operatop});
		}
		else if (ch == '+') {
			tokens.push_back({ "+", TokenType::Operatop});
		}
		else if (ch == '^') {
			tokens.push_back({ "^", TokenType::Operatop });
		}
		// определение операторов скобок(левой и правой)
		else if (ch == '(') {
			tokens.push_back({ "(", TokenType::Paren_LEFT});
		}
		else if (ch == ')') {
			tokens.push_back({ ")", TokenType::Paren_RIGHT});
		}
	}
	return tokens;
}