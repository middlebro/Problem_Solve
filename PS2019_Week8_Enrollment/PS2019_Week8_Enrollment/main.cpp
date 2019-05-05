//
//  main.cpp
//  PS2019_Week8_Enrollment
//
//  Created by 서형중 on 05/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, set<unsigned int> > name_to_number_set;     // store set of std_num for name
        set<unsigned int> dup_set;  // store duplicated std_num
        for (int i = 0; i < n; ++i) {
            unsigned int std_num;
            string name;
            cin >> std_num >> name;
            if (name_to_number_set.find(name) == name_to_number_set.end()) {
                set<unsigned int> tmp;
                tmp.insert(std_num);
                name_to_number_set.insert(make_pair(name, tmp));
                tmp.clear();
            }
            else {
                if (name_to_number_set[name].find(std_num) == name_to_number_set[name].end()) {// If the student number does not exist in the map, insert the student number in the set of that name
                    name_to_number_set[name].insert(std_num);
                }
                else {
                    if (dup_set.find(std_num) == dup_set.end()) {
                        dup_set.insert(std_num);
                    }
                }
            }
        }
        map<string, set<unsigned int> >::iterator itr = name_to_number_set.begin();
        int cnt = 0;
        for (; itr != name_to_number_set.end(); ++itr) {
            if ((*itr).second.size() > 1) {
                cnt += (*itr).second.size();
            }
        }
        cout << dup_set.size() << " " << cnt << endl;
    }
    return 0;
}
