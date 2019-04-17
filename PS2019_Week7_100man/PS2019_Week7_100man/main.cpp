//
//  main.cpp
//  PS2019_Week7_100man
//
//  Created by 서형중 on 16/04/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
using namespace std;

struct bucket {
    bool open = false;
    bool bingo = false;
};
int hashfunc1(int k) {
    return k % 1013;
}

int hashfunc2(int k) {
    return 37 - (k % 37);
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // test case
    // input
    // 3
    // 10 3
    // 1 2 3 4 5 6 7 8 9 10
    // 10 46
    // 216 53 9 6 20 985 123 621 952 1998
    // 10 45
    // 216 53 9 6 20 985 123 621 952 1998
    // output
    // 1000000
    // 980000
    // N
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        int key[1000];
        int money[1000] = {0, };
        bucket hash[1013];
        hash[i].bingo = true;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            key[j] = x;
        }
        int winner = -1;
        for (int j = 0; j < n; ++j) {
            int fk = hashfunc1(key[j]);
            int sk = hashfunc2(key[j]);
            if (hash[fk].open == false) {
                hash[fk].open = true;
                if (hash[fk].bingo != true) {
                    continue;
                }
                else {
                    winner = j;
                    money[j] += 1000000;
                    break;
                }
            }
            else {
                int c = 1;
                while (hash[(fk + c * sk) % 1013].open == true) {
                    money[j] -= 10000;
                    c++;
                }
                hash[(fk + c * sk) % 1013].open = true;
                money[j] -= 10000;
                if (hash[(fk + c * sk) % 1013].bingo != true) {
                    continue;
                }
                else {
                    winner = j;
                    money[j] += 1000000;
                    break;
                }
            }
        }
        if (winner != -1) {
            cout << money[winner] << endl;
        }
        else
            cout << 'N' << endl;
    }

    return 0;
}
