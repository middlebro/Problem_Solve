//
//  main.cpp
//  PS2019_Week2_Event
//
//  Created by 서형중 on 28/03/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
 
    int t;
    cin >> t;
    while (t--) {
        int n, idx = 0;      // 0 to 100
        cin >> n;
        pair<int, int> b[500000];
        vector<int> e;
        for (int i = 0; i < n; ++i) {
            int h;
            cin >> h;
            if (i == 0) {
                b[idx].first = h;
                b[idx++].second = i + 1;
                e.push_back(0);
                continue;
            }
            while (idx != 0) { // 비어있으면 끝 또는 탑이 높이보다 크거나 같으면 끝
                if (b[idx - 1].first < h) {
                    idx--;
                }
                else
                    break;
            }
            if (idx == 0)
                e.push_back(0);
            else
                e.push_back(b[idx - 1].second);
            b[idx].first = h;
            b[idx++].second = i + 1;
        }
        for (int i = 0; i < n; ++i) {
            cout << e[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
