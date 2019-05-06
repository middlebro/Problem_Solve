//
//  main.cpp
//  PS2019_Week4_Calculator
//
//  Created by 서형중 on 05/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <sstream>
using namespace std;

int calculate(int a, int b, string op) {
    if (op == "+")
        return a + b;
    else
        return a - b;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        string i, input = "";
        stack<string> op;
        stack<int> number;
        queue<string> formula;
        while (input != "$") {
            cin >> input;
            formula.push(input);
        }
        while (!formula.empty()) {
            input = formula.front();
            formula.pop();
            if (input == " " || input == "$") {
                continue;
            }
            if ((input == "(") || (input == "+") || (input == "-")) {
                op.push(input);
            }
            else if (input == ")") {
                while (!op.empty()) {
                    string i_i_op = op.top();
                    op.pop();
                    int a, b;
                    if (i_i_op == "(")
                        break;
                    else { // if (i_i_op == '+' || i_i_op == '-')
                        a = number.top();
                        number.pop();
                        b = number.top();
                        number.pop();
                        number.push(calculate(b, a, i_i_op));
                    }
                }
            }
            else {
                if (!op.empty() && op.top() == "-") {
                    number.push(-atoi(input.c_str()));
                    op.pop();
                    op.push("+");
                }
                else
                    number.push(atoi(input.c_str()));
            }
            
        }
        while (!op.empty()) {
            string i_i_op = op.top();
            if (i_i_op == "(") {
                break;
            }
            op.pop();
            int a, b;
            a = number.top();
            number.pop();
            if (number.empty()) {
                op.push("(");
                break;
            }
            b = number.top();
            number.pop();
            number.push(calculate(b, a, i_i_op));
        }
        if (number.size() == 1 && op.empty())
            cout << number.top() << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}
