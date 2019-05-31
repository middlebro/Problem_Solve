//
//  main.cpp
//  PS2019_Week13_AI_ROBOT
//
//  Created by 서형중 on 31/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    
    while (t--) {
        int l, b, v;
        cin >> l >> b >> v;
        bool village[50][50] = {{false}};
        bool visited[50][50]= {{false}};
        vector<pair<int, int> > start;
        for (int i = 0; i < v; ++i) {
            int x, y;
            cin >> x >> y;
            village[y][x] = true;
            start.push_back(make_pair(x, y));
        }
        
        queue<pair<int, int> > q;
        int cnt = 0;
        while (!start.empty()) {
            pair<int , int> u = start.back(); start.pop_back();
            if (village[u.second][u.first] == true && visited[u.second][u.first] == false ) {
                q.push(u);
                while (!q.empty()) {
                    pair<int, int> v = q.front(); q.pop();
                    if (v.first >= 0 && v.first < l && v.second >= 0 && v.second < b) {
                        if (village[v.second][v.first] == true && visited[v.second][v.first] == false) {
                            visited[v.second][v.first] = true;
                            q.push(make_pair(v.first, v.second + 1));   // up
                            q.push(make_pair(v.first, v.second - 1));   // down
                            q.push(make_pair(v.first - 1, v.second));   // left
                            q.push(make_pair(v.first + 1 , v.second));  // right
                        }
                    }
                }
                ++cnt;
            }
        }
        
        cout << cnt << "\n";
    }
    
    return 0;
}
