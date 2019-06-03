//
//  main.cpp
//  PS2019_Week13_Training
//
//  Created by 서형중 on 31/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> adj[10001];
        int incoming[10001] = {0};
        
        for (int i = 0; i < m; ++i){
            vector<int> s;
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                s.push_back(x);
            }
            for (int j = 0; j < k - 1; ++j) {
                adj[s[j]].push_back(s[j + 1]);
                ++incoming[s[j + 1]];
            }
        }
        priority_queue<int, vector<int>, greater<int> > start;
        for (int i = 1; i <= n; ++i) {
            if (incoming[i] == 0) {
                start.push(i);
            }
        }
        
        vector<int> result;
        while (!start.empty()) {
            int v = start.top(); start.pop();
            result.push_back(v);
            for (int i = 0; i < adj[v].size(); ++i) {
                if (incoming[adj[v][i]] > 1) {
                    --incoming[adj[v][i]];
                }
                else if (incoming[adj[v][i]] > 0){
                    start.push(adj[v][i]);
                }
            }
        }
        
        if (result.size() == n) {
            for (int i = 0; i < n; ++i) {
                cout << result[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
