
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stdlib.h>

using namespace std;

#include "calculator.h"
#include "calculator.cpp"

int main() {
    Calculator calc;
    vector<float> numbers;
    deque<string> operators;

    cout << "Enter:" << endl;
    string input;
    getline(cin, input);

    vector<string> lexed = calc.lexer(input);

    for (vector<string>::const_iterator i = lexed.begin(); i != lexed.end(); ++i) {
      //  cout << *i << endl;
        calc.parser(*i, numbers, operators);
    }

    for (deque<string>::const_iterator i = operators.begin(); i != operators.end(); ++i){
        // cout << *i << endl;
         numbers.erase(numbers.begin());
    }

        float results = 0;
        results = numbers[0];
        for(deque<string>::const_iterator i = operators.begin(); i != operators.end(); ++i){
                    if(*i == "+"){
                        results = results + numbers[1];
                        numbers.erase(numbers.begin());
                    } else if(*i == "-"){
                        results = results - numbers[1];
                        numbers.erase(numbers.begin());
                    } else if(*i == "/"){
                        results = results / numbers[1];
                        numbers.erase(numbers.begin());
                    } else if(*i == "*"){
                        results = results * numbers[1];
                        numbers.erase(numbers.begin());
                    }
        }

    cout << results << endl;

    return 0;
}
