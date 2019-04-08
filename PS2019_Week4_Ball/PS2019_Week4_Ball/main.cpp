//
//  main.cpp
//  PS2019_Week4_Ball
//
//  Created by 서형중 on 07/04/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int t;      // t < 50
    cin >> t;
    while (t--) {
        int n, l, k;
        cin >> n >> l >> k;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x > 0)
                v.push_back(l - x);
            else
                v.push_back(abs(x));
        }
        sort(v.begin(), v.end());
        cout << v[k - 1] << endl;
    }
    return 0;
}
