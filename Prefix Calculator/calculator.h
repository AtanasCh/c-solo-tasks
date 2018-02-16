#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stdlib.h>

using namespace std;


class Calculator
{
public:

	 Calculator();
	~Calculator();

	vector<string> lexer(string input);
	bool _isFactorial(string input);
	float parseFactorial(string input);
	void parser(string input,
                vector<float> &numbers,
                deque<string> &operators);


};



#endif
