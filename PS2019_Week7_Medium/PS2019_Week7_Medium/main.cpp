//
//  main.cpp
//  PS2019_Week7_Medium
//
//  Created by 서형중 on 16/04/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int> > min_heap;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int w;
            cin >> w;
            if (i == 0) {
                max_heap.push(w);
                cout << w << endl;
                continue;
            }
            if (w < max_heap.top()) {
                max_heap.push(w);
            }
            else {
                min_heap.push(w);
            }
            if (max_heap.size() - 1 > min_heap.size()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else if (max_heap.size() < min_heap.size()) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            cout << (i % 2 == 0 ? max_heap.top():(max_heap.top()<min_heap.top() ? max_heap.top():min_heap.top())) << endl;
        }
    }
    return 0;
}
