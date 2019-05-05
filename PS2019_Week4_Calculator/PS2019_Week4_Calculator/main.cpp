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
        char input;
        cin >> input;
        stack<char> op;
        stack<int> number;
        while (input != '$') {
            if ((input == '(') || (input == '+') || (input == '-')) {
                op.push(input);
            }
            else if (input == ')') {
                while (!op.empty()) {
                    if (op.top() == '(') {
                        op.pop();
                        break;
                    }
                    if (number.empty()) {
                        cout << 'N' << endl;
                        break;
                    }
                    int a = number.top();
                    number.pop();
                    if (number.size() == 0) {
                        op.pop();
                        number.push(a);
                    }
                    else {
                        
                    }
                }
            }
            else
                number.push(atoi(&input));
        }
        if (number.size() == 1 && op.empty())
            cout << number.top() << endl;
        else
            cout << 'N' << endl;
    }
    return 0;
}
