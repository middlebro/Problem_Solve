//
//  main.cpp
//  PS2019_Week9_Electing
//
//  Created by 서형중 on 06/06/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#define MOD 1000000007
#define _min(a, b) ((a < b) ? a : b)
using namespace std;

int memo[4001][4001] = {0};
int combination(int n, int k) {
    if (n == k || k == 0)
        return 1;
    else if (memo[n][k] == 0)
        return memo[n][k] = (combination(n-1, k) + combination(n-1, k-1)) % MOD;
    else
        return memo[n][k];
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int a, c;
        cin >> a >> c;
        int number_of_cases = combination(a, c);
        cout << number_of_cases << "\n";
    }
    return 0;
}
