//
//  main.cpp
//  PS2019_Week1_Multitask
//
//  Created by 서형중 on 27/03/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;   // 0 < t <= 1,000
    while (t--) {
        int n;  // 2 <= n <= 1,000
        cin >> n;
        long long int gwt = 0, grt = 0, ct = 0; // gross waiting time, gross response time, current time
        for (int i = 0; i < n; ++i) {
            long long int t1, t2, wt;
            cin >> t1 >> t2;
            wt = ((ct-t1)<0? 0: ct-t1);
            gwt += wt;
            grt += wt + t2;
            if ((i == 0)||(ct < t1)) {
                ct = t1 + t2;
                continue;
            }
            ct += t2;
        }
        cout << gwt / n << " " << grt / n << endl;
    }
    return 0;
}

// time-complexity : O(t * n)
// space-complexity : O(c)
