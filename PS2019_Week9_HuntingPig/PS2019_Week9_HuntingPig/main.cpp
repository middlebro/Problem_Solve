//
//  main.cpp
//  PS2019_Week9_HuntingPig
//
//  Created by 서형중 on 06/06/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct area {
    int height;
    int idx;
    bool visited;
    area(int idx, int height) : idx(idx), height(height), visited(false) {}
    area() {
        idx = -1;
        height = 0;
        visited = false;
    }
    ~area() {
        for (int i = 0; i < chi.size(); ++i) {
            delete chi[i];
        }
    }
    vector<area*> chi;
};

bool cmp(area *A, area *B) {
    return A->height < B->height;
}

void DFS(vector<area*> &adj, int i) {
    if (adj.size() != 0) {
        sort(adj.begin(), adj.end(), cmp);
        for (int j = 0; j < adj.size(); ++j) {
            if (adj[j]->visited == false) {
                adj[j]->visited = true;
                cout << adj[j]->idx << "\n";
                DFS(adj[j]->chi, j);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m; // n : area that exist possible of food . m : #path
        cin >> n >> m;
        vector<area*> matrix(n);
        
        for (int i = 0; i < n; ++i) {
            int h;
            cin >> h;
            area* tmp = new area(i, h);
            matrix[i] = tmp;
        }
        for (int i = 0; i < m; ++i) {
            int p1, p2;
            cin >> p1 >> p2;
            // init dist[p1][p2] = 1
            matrix[p1]->chi.push_back(matrix[p2]);
            matrix[p2]->chi.push_back(matrix[p1]);
        }
        // find area that dist is 1 and lowest height among them
        sort(matrix.begin(), matrix.end(), cmp);
        
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i]->visited == false) {
                cout << matrix[i]->idx << "\n";
                matrix[i]->visited = true;
                DFS(matrix[i]->chi, i);
            }
        }
    }
    return 0;
}


