#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

const int MAXN = 20;
struct node {
    int left, right;
};

int n;
node tree[MAXN];
bool notRoot[MAXN];

int char2num(char c) {
    if (c == '-') {
        return -1;
    }
    notRoot[c - '0'] = true;
    return c - '0';
}

int findroot() {
    for (int i = 0; i < n; ++i) {
        if (notRoot[i] == false) {
            return i;
        }
    }
}

void postorder(int root) {
    if (root == -1) {
        return;
    }
    postorder(tree[root].left);
    postorder(tree[root].right);

    int t = tree[root].left;
    tree[root].left = tree[root].right;
    tree[root].right = t;
}


int num = 0;
void print(int node) {
    cout << node;
    num++;
    if (num < n) {
        cout << " ";
    } else {
        cout << endl;
    }
}

void levelorder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        print(node);
        if (tree[node].left != -1) {
            q.push(tree[node].left);
        }
        if (tree[node].right != -1) {
            q.push(tree[node].right);
        }
    }
}

void inorder(int root) {
    if (root == -1) {
        return;
    }
    inorder(tree[root].left);
    print(root);
    inorder(tree[root].right);
}


int main() {
    freopen("infile1.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        char left, right;
        cin >> left >> right;
        tree[i].left = char2num(left);
        tree[i].right = char2num(right);
    }
    int root = findroot();
    postorder(root);

    levelorder(root);
    num = 0;
    inorder(root);


    return 0;
}

