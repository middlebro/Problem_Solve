//
//  main.cpp
//  PS_Week2 Quiz
//
//  Created by 서형중 on 12/03/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

// check out of range about position to breed
bool outOFrange(int x, int y, int size, vector<pair<int, int>> &none, vector<pair<int, int>> &germ) {
    bool f1 = true, f2 = true;
    
    // x range check
    if ((x < size)&&(x >= 0)) {
        // y range check
        if ((y < size)&&(y >= 0)){
            for (auto &i : none) {
                // check out (x,y) != none position
                if (!((x == i.first)&&(y == i.second)))
                    f1 = false;
            }
            for (auto &i : germ) {
                // check out (x,y) != none position
                if (!((x == i.first)&&(y == i.second)))
                    f2 = false;
            }
        }
    }
    return !(f1&&f2);
}

// check each position is full
bool check(vector<pair<int, int>> &germ, int &n, int &m) {
    // size of germ that can be i.e. whole size - size that germ cannot be
    if (germ.size() == n * n - m)
        return true;
    else
        return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> none; // position do not breed
        vector<pair<int, int>> germ; // position of germ
        
        // initialize none position
        for (int j = n - 1; j >= 0; j--) {
            for  (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                if(x == 1)
                    none.push_back(make_pair(i, j));
            }
        }
        
        // initialize germ position
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            germ.push_back(make_pair(x, y));
        }
        
        cout << germ.size() << endl;
        int t = 0; // set time
        
        // count up time to breed all the place
        while (true) {
            // break condition
            if (check(germ, n, m)) {
                cout << t << endl;
                break;
            }
            
            // if time were over the maxium full time, then end while
            if (t > (n - 1) * 2){
                cout << -1 << endl;
                break;
            }
            vector<pair<int, int>> tmp; // store temperary position to store increased germ
            
            // breeding to four direction
            // and store in tmp
            for (auto &i : germ) {
                if (!(outOFrange(i.first+1, i.second, n, none, germ)))
                    tmp.push_back(make_pair(i.first+1, i.second));  // breed right
                if (!(outOFrange(i.first-1, i.second, n, none, germ)))
                    tmp.push_back(make_pair(i.first-1, i.second));  // breed left
                if (!(outOFrange(i.first, i.second+1, n, none, germ)))
                    tmp.push_back(make_pair(i.first, i.second+1));  // breed up
                if (!(outOFrange(i.first, i.second-1, n, none, germ)))
                    tmp.push_back(make_pair(i.first, i.second-1));  // breed down
            }
            
            // add tmp to germ
            for (auto &i : tmp) {
                germ.push_back(make_pair(i.first, i.second));
            }
            tmp.clear(); // clear tmp
            t++;         // count up time
        }
    }
    return 0;
}

//class Point{
//public:
//    Point(int x, int y, int val): x(x), y(y), val(val) {}
//
//    int x;
//    int y;
//    int val;
//};
//
//bool checkF(vector<vector<int>> germ, int size){
//    for (int i =0 ; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            if (!((germ[i][j]==1)&&(germ[i][j]==-1)))
//                return false;
//        }
//    }
//    return true;
//}