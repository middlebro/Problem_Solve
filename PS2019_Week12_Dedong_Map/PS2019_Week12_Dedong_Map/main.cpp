//
//  main.cpp
//  PS2019_Week12_Dedong_Map
//
//  Created by 서형중 on 10/06/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> city[1001];
        pair<int, int> root = make_pair(0, 1000000000);
        for (int i = 0; i < n; ++i) {
            int h;
            cin >> h;
            if (root.second > h) {
                root = make_pair(i, h);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            int p1, p2;
            cin >> p1 >> p2;
            city[p1].push_back(p2);
            city[p2].push_back(p1);
        }
        
        while (k--) {
            bool visited[1001] = {false};
            queue<int> q;
            int cost = 0;
            bool check = false;
            
            int dst;
            cin >> dst;
            if (root.first == dst) {
                check = true;
            }
            else if (!check) {
                q.push(root.first);
                visited[root.first] = true;
                
                while (!q.empty()) {
                    int size = (int)q.size();
                    ++cost;
                    for (int i = 0; i < size; ++i) {
                        int v = q.front();
                        q.pop();
                        for (int i = 0; i < city[v].size(); ++i) {
                            int tmp = city[v][i];
                            if (visited[tmp] == false) {
                                q.push(tmp);
                                visited[tmp] = true;
                                if (tmp == dst) {
                                    check = true;
                                    break;
                                }
                            }
                        }
                        if (check)
                            break;
                    }
                    if (check)
                        break;
                }
            }
            if (check)
                cout << cost << "\n";
            else
                cout <<-1 << "\n";
        }
    }
    return 0;
}
