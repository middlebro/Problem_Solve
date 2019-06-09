//
//  main.cpp
//  PS2019_Week11_Alcohol
//
//  Created by 서형중 on 19/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int b, l, n;
        cin >> b >> l >> n;
        double glass[401][401] = {{0}};
        glass[1][1] = 7 * b;
        
        for (int i = 1; i <= l ; ++i) {
            int number = 1;
            for (int j = 1; j <= i; ++j) {
                for (int k = 1; k <= j; ++k) {
                    double dump = glass[i][number]-1;
                    if (dump > 0) {
                        glass[i + 1][number] += dump / 3;
                        glass[i + 1][number + j] += dump / 3;
                        glass[i + 1][number + j + 1] += dump / 3;
                    }
                    ++number;
                }
            }
        }
        
        int answer;
        if (glass[l][n] >= 1)
            answer = 1;
        if (glass[l][n] > 0 && glass[l][n] < 1)
            answer = 2;
        if (glass[l][n] == 0)
            answer = 0;
        cout << answer << "\n";
    }
    return 0;
}
