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
                int idx = (fk + sk) % 1013;
                while (hash[idx].open != true) {
                    money[j] -= 10000;
                    idx += sk % 1013;
                }
                money[j] -= 10000;
                if (hash[idx].bingo != true) {
                    continue;
                }
                else {
                    winner = j;
                    money[j] += 1000000;
                    break;
                }
            }
        }
        cout << (winner != -1 ? money[winner]:'N') << endl;
    }

    return 0;
}
