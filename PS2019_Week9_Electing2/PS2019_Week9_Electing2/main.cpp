//
//  main.cpp
//  PS2019_Week9_Electing2
//
//  Created by 서형중 on 06/06/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#define MOD 1000000007
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int memo[4001];
    while (t--) {
        int a, c;
        cin >> a >> c;
        if (c > a - c)
            c =  a - c;
        for (int i = 1; i <= a + 1; ++i) {
            memo[i] = 1;
        }
        for (int j = 1; j <= c; ++j) {
            for (int i = 2; i <= a - j + 1; ++i) {
                memo[i] = (memo[i] + memo[i - 1]) % MOD;
            }
        }
        int number_of_cases = memo[a - c + 1];
        cout << number_of_cases << "\n";
    }
    return 0;
}
