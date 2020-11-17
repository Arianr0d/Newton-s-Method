#include <iostream>
#include <cmath>
#include <string>
#include<sstream>

#include "Token.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int a1, b1;
	long double eps;
	cout << "¬ведите границы интервала: " << endl << "a = ";
	cin >> a1;
	cout << endl << "b = ";
	cin >> b1;
	cout << "¬ведите точность вычислени€ точки экстремума: " << endl << "eps = ";
	cin >> eps;

	string b;
	vector<Token> v = Tokenize(cin);
	for(Token f : v){
		cout << f.val << endl;
	}
	return 0;
}



/*
template <class Iterator> 
void foo(Iterator token, Iterator end){ 
	char ch;
	While(token != end){ 
		ch = (*token);
		ch = (*next(token)); 
		token++;
	}
}
---------
string s;
foo(begin(s),end(s));*/





