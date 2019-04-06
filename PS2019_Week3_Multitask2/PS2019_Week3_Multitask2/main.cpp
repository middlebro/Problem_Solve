//
//  main.cpp
//  PS2019_Week3_Multitask2
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

struct task{
    int id;
    int ot;
    int rt;
    int p;
    bool cmd = false;
};
bool cmp(task t1, task t2){
    if (t1.p == t2.p) {
        return t1.ot > t2.ot;
    }
    return t1.p > t2.p;
}

void execute(task &t, long long int &time, long long int &wt, long long int &et){
    wt += (time - t.ot < 0)? 0:time - t.ot;
    time += t.rt + ((time - t.ot < 0)? t.ot - time:0);
    et += time - t.ot;
}
pair<int, int> Procedure_PR_process(int n, int m, task *p){
    vector<task> r_list;
    long long int time = 0, wt = 0, et = 0;
    for (int i = 0; i < n + m; ++i) {
        if (p[i].ot < time) {
            if (p[i].cmd) {
                for (int j = 0; j < r_list.size(); ++j) {
                    if (p[i].id == r_list[j].id){
                        r_list[j].p = p[i].p;
                        break;
                    }
                }
            }
            else
                r_list.push_back(p[i]);
        }
        else if (p[i].ot == time){
            // apply event
            if (p[i].cmd) {
                for (int j = 0; j < r_list.size(); ++j) {
                    if (p[i].id == r_list[j].id){
                        r_list[j].p = p[i].p;
                        break;
                    }
                }
            }
            else
                r_list.push_back(p[i]);
            // end apply
            sort(r_list.begin(), r_list.end(), cmp);
            task tmp = r_list.back();
            r_list.pop_back();
            execute(tmp, time, wt, et);
        }
        else if ((time < p[i].ot)&&!r_list.empty()) {
            while ((time < p[i].ot)&&!r_list.empty()) {
                sort(r_list.begin(), r_list.end(), cmp);
                task tmp = r_list.back();
                r_list.pop_back();
                execute(tmp, time, wt, et);
            }
            --i;
        }
        else {
            if (!p[i].cmd)
                execute(p[i], time, wt, et);
        }
    }
    // execute remining tasks in r_list
    sort(r_list.begin(), r_list.end(), cmp);
    vector<task>::iterator itr = r_list.end();
    for (; itr != r_list.begin(); --itr) {
        task tmp = r_list.back();
        r_list.pop_back();
        wt += (time - tmp.ot < 0)? 0:time - tmp.ot;
        time += tmp.rt;
        et += time - tmp.ot;
    }
    return make_pair(wt/n, et/n);
}
int main() {
    ios::sync_with_stdio(false);
    int t;  // t : 0 to 1,000
    cin >> t;
    while (t--) {
        int n, m;   // n : 2 to 1,000, m : 0 to 100 M <= N
        cin >> n >> m;
        task a_list[1100]; int idx = 0;
        for (int i = 0; i < n + m; ++i) {
            char cmd; int ot, rt, p;
            cin >> cmd >> ot >> rt >> p;
            if (cmd != 'N') {
                task tmp;
                tmp.id = atoi(&cmd); tmp.ot = ot; tmp.rt = rt; tmp.p = p;
                a_list[idx++] = tmp;
            }
            else {
                task tmp;
                tmp.id = rt; tmp.ot = ot; tmp.rt = -1; tmp.p = p; tmp.cmd = true;
                a_list[idx++] = tmp;
            }
        }
        // end input task, cmd
        pair<int, int> tmp = Procedure_PR_process(n , m, a_list);
        printf("%d %d\n", tmp.first, tmp.second);
    }
    return 0;
}
