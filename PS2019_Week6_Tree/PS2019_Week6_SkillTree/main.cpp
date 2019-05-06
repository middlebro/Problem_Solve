//
//  main.cpp
//  PS2019_Week6_SkillTree
//
//  Created by 서형중 on 13/04/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> m;
        
        
        typedef pair<int, int> p;
        for (int i = 0; i < n - 1; ++i) {
            int s1, s2;
            cin >> s1 >> s2;
            m.insert(p(s2, s1));
        }
        
        for (int i = 0; i < k; ++i) {
            vector<int> s1_path;
            vector<int> s2_path;
            int s1, s2, tmp;
            cin >> s1 >> s2;
            s1_path.push_back(s1);
            s2_path.push_back(s2);

            tmp = s1;
            while (m.find(tmp) != m.end()) {
                tmp = m.find(tmp)->second;
                s1_path.push_back(tmp);
            }

            tmp = s2;
            while (m.find(tmp) != m.end()) {
                tmp = m.find(tmp)->second;
                s2_path.push_back(tmp);
            }
            /////////////////////////////////
            /////////////////////////////////
//            cout << "s1 path : ";
//            for (auto &j : s1_path) {
//                cout << j << " ";
//            }
//            cout << endl;
//            cout << "s2 path : ";
//            for (auto &j : s2_path) {
//                cout << j << " ";
//            }
//            cout << endl;
            /////////////////////////////////
            /////////////////////////////////
            unsigned long int itr1 = s1_path.size() - 1;
            unsigned long int itr2 = s2_path.size() - 1;
            if (itr1 != 0 && itr2 != 0) {
                while (true) {
                    if (s1_path[itr1] != s2_path[itr2]) {
                        cout << s2_path[++itr2] << endl;
                        break;
                    }
                    if (itr1 == 0) {
                        cout << s1_path[itr1] << endl;
                        break;
                    }
                    if (itr2 == 0) {
                        cout << s2_path[itr2] << endl;
                        break;
                    }
                    --itr1; --itr2;
                }
            }
            else{
                if (itr1 == 0)
                    cout << s1_path[0] << endl;
                else
                    cout << s2_path[0] << endl;
            }

        }
    }
    return 0;
}
