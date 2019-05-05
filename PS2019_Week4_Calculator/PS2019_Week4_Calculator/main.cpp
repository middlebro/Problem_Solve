//
//  main.cpp
//  PS2019_Week4_Calculator
//
//  Created by 서형중 on 05/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int calculate(int a, int b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else
        return NULL;
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        char input = '\0';
        stack<char> op;
        stack<int> number;
        while (input != '$') {
            cin >> input;
            if ((input == '(') || (input == '+') || (input == '-')) {
                op.push(input);
            }
            else if (input == ')') {
                while (!op.empty()) {
                    char i_i_op = op.top();
                    op.pop();
                    int a, b;
                    if (i_i_op == '(')
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
            else
                number.push(atoi(&input));
        }
        while (!op.empty()) {
            char i_i_op = op.top();
            if (i_i_op == '(') {
                break;
            }
            op.pop();
            int a, b;
            a = number.top();
            number.pop();
            if (number.empty()) {
                op.push('(');
                break;
            }
            b = number.top();
            number.pop();
            number.push(calculate(b, a, i_i_op));
        }
        if (number.size() == 1 && op.empty())
            cout << number.top() << endl;
        else
            cout << 'N' << endl;
    }
    return 0;
}
