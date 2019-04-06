//
//  main.cpp
//  PS2019_Week2_Germ
//
//  Created by 서형중 on 31/03/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    
    int t;  // 0 to 1,000
    cin >> t;
    while (t--) {
        int n, m;   // n : 2 to 100, m : 2 to 100
        cin >> n >> m;
        
        // initailize map N+2 * N+2, edge = 1
        int map[102][102];
        
        for (int i = 0; i < n + 2; ++i) {
            map[0][i] = 1;
        }
        for (int i = 0; i < n + 2; ++i) {
            map[i][0] = 1;
        }
        for (int i = 0; i < n + 2; ++i) {
            map[n + 1][i] = 1;
        }
        for (int i = 0; i < n + 2; ++i) {
            map[i][n + 1] = 1;
        }
        
        // number of black area
        int b_size = 0;
        // set black space to map
        for (int y = n; y > 0; --y) {
            for (int x = 1; x <= n; ++x) {
                int g;
                cin >> g;
                map[x][y] = g;
                if(g == 1)
                    ++b_size;
            }
        }
        
        // size of queue
        int remain_area =  n * n;
        // number of first germ
        int g_size = 0;
        // push first germs to queue
        queue<pair<int, int> > q;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            q.push(make_pair(x + 1, y + 1));
            map[x + 1][y + 1] = 1;
            ++g_size;
        }
        remain_area -=  b_size + g_size;
        
        int time = 0; // time to full
        while (!q.empty()) {
            int n_germ = g_size;    // number of new germs
            g_size = 0;
            
            // breed
            for (int i = 0; i < n_germ; ++i) {
                // left
                if (map[q.front().first - 1][q.front().second] != 1) {
                    map[q.front().first - 1][q.front().second] = 1;
                    q.push(make_pair(q.front().first - 1, q.front().second));
                    ++g_size;
                    --remain_area;
                }
                // right
                if (map[q.front().first + 1][q.front().second] != 1) {
                    map[q.front().first + 1][q.front().second] = 1;
                    q.push(make_pair(q.front().first + 1, q.front().second));
                    ++g_size;
                    --remain_area;
                }
                // up
                if (map[q.front().first][q.front().second + 1] != 1) {
                    map[q.front().first][q.front().second + 1] = 1;
                    q.push(make_pair(q.front().first, q.front().second + 1));
                    ++g_size;
                    --remain_area;
                }
                // down
                if (map[q.front().first][q.front().second - 1] != 1) {
                    map[q.front().first][q.front().second - 1] = 1;
                    q.push(make_pair(q.front().first, q.front().second - 1));
                    ++g_size;
                    --remain_area;
                }
                q.pop();
            }
            ++time;
        }
        
        if (remain_area != 0) {
            cout << -1 << endl;
        }
        else
            cout << time - 1 << endl;
    }
    return 0;
}
