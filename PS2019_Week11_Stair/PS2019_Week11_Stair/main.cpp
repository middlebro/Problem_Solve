//
//  main.cpp
//  PS2019_Week11_Stair
//
//  Created by 서형중 on 09/06/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
long long int steps[61];
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        memset(steps, 0, sizeof(steps));
        steps[1] = 1;
        int x, y;
        cin >> x >> y;
        if (x <= y) {
            for (int i = 1; i <= x; ++i) {
                long long int tmp = 1;
                for (int j = 1; j < i; ++j) {
                    tmp += steps[j];
                }
                steps[i] = tmp;
            }
        }
        else {
            for (int i = 1; i <= y; ++i) {
                long long int tmp = 1;
                for (int j = 1; j < i; ++j) {
                    tmp += steps[j];
                }
                steps[i] = tmp;
            }
            for (int i = y + 1; i <= x; ++i) {
                long long int tmp = 0;
                for (int j = 1; j <= y; ++j) {
                    tmp += steps[i - j];
                }
                steps[i] = tmp;
            }
        }
        cout << steps[x] << "\n";
    }
    
    return 0;
}
