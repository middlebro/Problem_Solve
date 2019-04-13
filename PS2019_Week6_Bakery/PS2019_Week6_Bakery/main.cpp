//
//  main.cpp
//  PS2019_Week6_Bakery
//
//  Created by 서형중 on 13/04/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    long long int ing_num = NULL;
    long long int val = NULL;
    vector<Node*> chi;
};
struct tree {
    Node* root = new Node;
    vector<Node*> node_list;
    vector<pair<long long int, long long int> > ing;
    
    tree(long long int val){
        this->root->ing_num = val;
        this->root->val = 1;
        node_list.push_back(root);
    }
    
    void Insert(long long int par, long long int num, long long int val){
        Node* tmp = new Node;
        tmp->ing_num = num;
        tmp->val = val;
        vector<Node*>::iterator i = node_list.begin();
        for (; i != node_list.end(); ++i){
            if ((*i)->ing_num == par){
                (*i)->chi.push_back(tmp);
                node_list.push_back(tmp);
                break;
            }
        }
    }
    
    void setING(Node *t){
        if (t->chi.empty()){
            ing.push_back(make_pair(t->ing_num, t->val));
        }
        else {
            for (int i = 0; i < t->chi.size(); ++i){
                t->chi[i]->val *= t->val;
                setING(t->chi[i]);
            }
        }
    }
    
    void printING(){
        sort(ing.begin(), ing.end());
        for (unsigned int i = 0; i < ing.size(); ++i){
            cout << ing[i].first << " " << ing[i].second << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        tree ing_t(n);
        vector<pair<long long int, pair<long long int, long long int> > > v;
        for (int i = 0; i < m; ++i) {
            long long int x, y, k;
            cin >> x >> y >> k;
            typedef pair<long long int, long long int> tmp;
            typedef pair<long long int, tmp> temp;
            v.push_back(temp(x,tmp(y,k)));
        }
        sort(v.begin(), v.end());
        while (!v.empty()) {
            ing_t.Insert(v.back().first, v.back().second.first, v.back().second.second);
            v.pop_back();
        }
        ing_t.setING(ing_t.root);
        ing_t.printING();
    }
    return 0;
}
