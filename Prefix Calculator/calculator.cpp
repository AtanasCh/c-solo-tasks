

#include <string>
#include <vector>
#include <deque>

#include "calculator.h"

Calculator::Calculator(){
//
}

Calculator::~Calculator(){

//

}



vector<string> Calculator::lexer(string input) {

    vector<string> _return;
    istringstream iss(input);
    string chunk;
    while ( getline( iss, chunk, ' ' ) ) {
        _return.push_back( chunk.c_str() );
    }
    return _return;
}

bool Calculator::_isFactorial(string input) {
    return (input.substr(0,5) == "fact(" && input.substr(input.length() - 1) == ")");
}

float Calculator::parseFactorial(string input) {
    float _return = 1.0;
    string x = input.substr(5, (input.length() - 5 - 1));
    float n = atof( x.c_str() );
    for(float i = 1.0; i <= n; ++i)
    {
        _return *= i;
    }
    return _return;
}

void Calculator::parser(
    string input,
    vector<float> &numbers,
    deque<string> &operators
) {
    if (
        input == "+"
        || input == "-"
        || input == "*"
        || input == "/"
    ) operators.push_front(input);
    if ( _isFactorial(input) ) numbers.push_back( parseFactorial(input) );
    else numbers.push_back( atof( input.c_str() ) );
}
