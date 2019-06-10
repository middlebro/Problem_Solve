//
//  main.cpp
//  PS2019_Week12_Egg_Carton
//
//  Created by 서형중 on 09/06/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int solution[100001];
        
        for (int i = 1; i <= n; ++i) {
            solution[i] = 1000000;
        }

        vector<int> carton;
        for (int i = 0; i < m; ++i) {
            int size_of_carton;
            cin >> size_of_carton;
            carton.push_back(size_of_carton);
        }

        for (int i = 0; i < carton.size(); ++i) {
            for (int j = carton[i]; j <= n; ++j) {
                int rem = j - carton[i];
                if (rem != 0) {
                    int sum = solution[rem] + 1;
                    if (sum < solution[j])
                        solution[j] = sum;
                }
                else
                    solution[j] = 1;
            }
        }
        
        if (solution[n] < 1000000)
            cout << solution[n] << "\n";
        else
            cout << "0\n";
    }
    return 0;
}
