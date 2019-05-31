//
//  main.cpp
//  PS2019_Week11_Alcohol
//
//  Created by 서형중 on 19/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct glass {
    bool empty = true;
    bool full = false;
    double quantity = 0;
    void set_status() {
        if (this->quantity == 1) {
            this->empty = false;
            this->full = true;
        }
        else if (this->quantity > 0)
            this->empty = false;
    }
};
struct alcohol {
    int b, l, n;
    int total_number_of_drop;
    vector<vector<int>> next_glass;
//    vector<vector<int>> ratio;
    vector<vector<glass>> layer;
    alcohol(int b, int l, int n) : b(b), l(l), n(n) {
        total_number_of_drop = 7 * b;
        for (int i = 0; i <= l; ++i) {
            vector<int> tmp;
            vector<glass> number_of_glass(i * (i + 1) / 2 + 1);
            next_glass.push_back(tmp);
//            ratio.push_back(tmp);
            layer.push_back(number_of_glass);
        }
        set_next_glass(l);
//        set_ratio(l);
    }
    void set_next_glass(int layer) {
        int glass_num = 1;
        for (int i = 1; i < layer; ++i) {
            for (int j = 0; j < i; ++j) {
                next_glass[glass_num].push_back(glass_num + i);
                next_glass[glass_num].push_back(glass_num + i + 1);
                ++glass_num;
            }
        }
    }
    void drop_water(int num_drop) {
//        int pre_layer = 0, cur_layer = 1;
        for (int i = 0; i < num_drop; ++i) {
            insert(1, 1, 1);
        }
    }
    void insert(int cur_layer, int glass_num, double quantity) {
        if (layer[cur_layer][glass_num].full == false) {
            layer[cur_layer][glass_num].quantity += quantity;
            layer[cur_layer][glass_num].set_status();
            return;
        }
        insert(cur_layer + 1, glass_num, quantity/3);
        insert(cur_layer + 1, next_glass[glass_num][0], quantity/3);
        insert(cur_layer + 1, next_glass[glass_num][1], quantity/3);
        
    }
    int get_status(int l, int n) {
        if (layer[l][n].empty == true)
            return 0;
        else if (layer[l][n].full == false)
            return 2;
        else
            return 1;
    }
//    ~alcohol() {
//        for (int i = 0; i < layer.size(); ++i) {
//            layer[i].erase(layer[i].begin(), layer[i].end());
//        }
//        for (int i = 0; i < next_glass.size(); ++i) {
//            next_glass.erase(next_glass.begin(), next_glass.end());
//        }
//    }
};

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int b, l, n;
        cin >> b >> l >> n;
        alcohol T(b, l, n);
        T.drop_water(7 * b);
        cout << T.get_status(l, n) << "\n";
//        T.~alcohol();
    }
    return 0;
}
