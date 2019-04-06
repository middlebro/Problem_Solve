//
//  main.cpp
//  PS2019_Week3_CardErase
//
//  Created by 서형중 on 01/04/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

struct card{
    int x;
    int y;
};
struct Dist{
    card a;
    card b;
    int dist;
};
bool cmp(Dist a, Dist b){
    return (a.dist < b.dist)||(a.dist == b.dist && a.a.y + a.b.y < b.a.y + b.b.y)||
            (a.dist == b.dist && a.a.y + a.b.y == b.a.y + b.b.y && a.a.x + a.b.x <b.a.x + b.b.x);
}
bool CardCmp(Dist a, Dist b){
    if (a.a.x == b.a.x && a.a.y == b.a.y) {
        return true;
    }
    else if (a.b.x == b.a.x && a.b.y == b.a.y)
        return true;
    else if (a.a.x == b.b.x && a.a.y == b.b.y)
        return true;
    else if (a.b.x == b.b.x && a.b.y == b.b.y)
        return true;
    else
        return false;
}
void EraseCard(vector<card> seq[], int shape){
    vector<Dist> d_vec;
    for (int j = 0; j < seq[shape].size() - 1; ++j) {
        for (int k = j + 1; k < seq[shape].size(); ++k) {
            Dist tmp;
            if((seq[shape][k].y < seq[shape][j].y)||(seq[shape][k].y == seq[shape][j].y && seq[shape][k].x < seq[shape][j].x)){
                tmp.a.x = seq[shape][k].x;
                tmp.a.y = seq[shape][k].y;
                tmp.b.x = seq[shape][j].x;
                tmp.b.y = seq[shape][j].y;
            }
            else{
                tmp.b.x = seq[shape][k].x;
                tmp.b.y = seq[shape][k].y;
                tmp.a.x = seq[shape][j].x;
                tmp.a.y = seq[shape][j].y;
            }
            tmp.dist = (tmp.a.x - tmp.b.x)*(tmp.a.x - tmp.b.x) + (tmp.a.y - tmp.b.y)*(tmp.a.y - tmp.b.y);
            d_vec.push_back(tmp);
        }
    }
    sort(d_vec.begin(), d_vec.end(), cmp);
    for (int j = 0; j < d_vec.size(); ++j) {
        if(d_vec[j].dist != -1) {
            printf("%c %d %d %d %d\n", static_cast<char>(shape + 65), d_vec[j].a.x, d_vec[j].a.y, d_vec[j].b.x, d_vec[j].b.y);
            if (j != d_vec.size() - 1) {
                for (int k = j + 1; k < d_vec.size(); ++k) {
                    if(CardCmp(d_vec[j], d_vec[k]) == true){
                        d_vec[k].dist = -1;
                    }
                }
            }
        }
    }// end for print
}
int main() {
//    clock_t begin = clock();
    ios::sync_with_stdio(false);
    int t;  // t: 1 to 10
    cin >> t;
    while (t--) {
        vector<card> seq[27];
        for (int i = 0; i < 27; ++i) {
            vector<card> c_vec;
            seq[i] = c_vec;
        }
        int n, m;  // n : 2 to 100, m : 2 to n^2
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            char sig;
            card tmp;
            cin >> sig >> tmp.x >> tmp.y;
            seq[sig-65].push_back(tmp);
        }
        
        for (int i = 0; i < 27; ++i) {
            if (seq[i].size() > 0) {
                EraseCard(seq, i);
            }
        } // end for 0 to 26
    } //  end while
//    clock_t end = clock();
//    cout << "time : " << ((begin - end)/CLOCKS_PER_SEC) << endl;
    return 0;
}
