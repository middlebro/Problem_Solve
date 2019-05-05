//
//  main.cpp
//  PS2019_Week8_AVL
//
//  Created by 서형중 on 05/05/2019.
//  Copyright © 2019 Hyeongjung Seo. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    int std_num;
    string name;
    Node* par;
    Node* left;
    Node* right;
    Node(int key, string value) : std_num(key), name(value), par(NULL), left(NULL), right(NULL) {}
    Node() : std_num(NULL), name(NULL),par(NULL), left(NULL), right(NULL) {}
};

struct AVL {
    Node* root;
    int get_height(Node*);
    int get_diff(Node*);
    Node* find(Node*, int);
    void insert(int, string);
    Node* rotation_RR(Node*);
    Node* rotation_LL(Node*);
    Node* rotation_RL(Node*);
    Node* rotation_LR(Node*);
    Node* restructure(Node*);
    AVL() : root(NULL) {}
    
};
int AVL::get_height(Node* Node) {
    int height = 0;
    if (Node != NULL)
        height = 1 + max(get_height(Node->left), get_height(Node->right));
    return height;
}
int AVL::get_diff(Node* Node) {
    if (Node == NULL)
        return 0;
    return get_height(Node->left) - get_height(Node->right);
}
Node* AVL::find(Node* node, int key) {
    if (node->left == NULL && node->right == NULL) return node;
    if (node->std_num > key)
        return find(node->left, key);
    else if(node->std_num <= key)
        return find(node->right, key);
    else
        return node;
}
void AVL::insert(int key, string value) {
    Node* curLeafNode = find(root, key);
    Node* newNode = new Node(key, value);
    if (key < curLeafNode->std_num)
        curLeafNode->left = newNode;
    else
        curLeafNode->right = newNode;
    newNode->par = curLeafNode;
    restructure(newNode);
    cout << value << " " << get_height(newNode) << endl;
}
Node* AVL::rotation_RR(Node* par) {
    Node* chi = par->right;
    par->right = chi->left;
    chi->left = par;
    return chi;
}
Node* AVL::rotation_LL(Node* par) {
    Node* chi = par->left;
    par->left = chi->right;
    chi->right = par;
    return chi;
}
Node* AVL::rotation_RL(Node* par) {
    Node* chi = par->right;
    par->right = rotation_LL(chi);
    return rotation_RR(par);
}
Node* AVL::rotation_LR(Node* par) {
    Node* chi = par->left;
    par->left = rotation_RR(chi);
    return rotation_LL(par);
}

Node* AVL::restructure(Node * x) {
    if (x->par == NULL || x->par->par == NULL)
        return NULL;
    Node* y = x->par;
    Node* z = y->par;
    if (x == y->left) {
        if (y == z->left)
            return rotation_LL(z);
        else
            return rotation_RL(z);
    }
    else {
        if (y == z->left)
            return rotation_LR(z);
        else
            return rotation_RR(z);
    }
    return NULL;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    AVL tree;
    while (n--) {
        string cmd, val;
        int k;
        cin >> cmd;
        if (cmd == "insert") {
            cin >> k >> val;
            if (tree.root != NULL)
                tree.insert(k, val);
            else {
                Node* tmp = new Node(k, val);
                tree.root = tmp;
                cout << val << " " << 0 << endl;
            }
        }
        else if (cmd == "find") {
            cin >> k;
            Node* tmp = tree.find(tree.root, k);
            if (tmp->left == NULL && tmp->right == NULL) {
                cout << -1 << endl;
            }
            else {
                cout << tmp->std_num << tree.get_height(tmp) << endl;
            }
        }
    }
    
    return 0;
}
