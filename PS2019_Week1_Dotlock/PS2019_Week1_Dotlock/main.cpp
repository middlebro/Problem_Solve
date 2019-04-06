//
//  main.cpp
//  PS2019_Week1_Dotlock
//
//  Created by 서형중 on 27/03/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &a, int &b){
    return a > b;
}
int main() {
    ios::sync_with_stdio(false);
    int t;      // t : 1 to 10
    cin >> t;
    while (t--) {
        int n, m;   // n : 10 to 10^6, m : 1 to 3,000
        cin >> n >> m;
        vector<int> hair;
        for (int i = 0; i < n; ++i) {
            int len;
            cin >> len;
            hair.push_back(len);
        }
        while (m--) {
            int s;
            cin >> s;
//            for (int i = 0; i < hair.size(); i++) {
//                if (hair[i] == s) {
//                    cout << i << endl;
//                    break;
//                }
//            }
            cout <<  lower_bound(hair.begin(), hair.end(), s) - hair.begin() + 1 << endl;
        }
    }
    return 0;
}
