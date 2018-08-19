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


struct node {
    node *left;
    node *right;
    int val;

    node(int _val) {
        val = _val;
    }
};

const int MAXN = 50;
int pre[MAXN];
int in[MAXN];

node *create(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return NULL;
    }
    node *root = new node(pre[preL]);
    int k = inL;
    while (in[k] != pre[preL]) {
        k++;
    }
    int numLeft = k - inL;
    root->left = create(preL + 1, preL + numLeft, inL, k - 1);
    root->right = create(preL + numLeft + 1, preR, k + 1, inR);

    return root;
}

bool isFirst = true;

void post(node *root) {
    if (root == NULL) {
        return;
    }
    post(root->left);
    post(root->right);
    if (!isFirst) {
        cout << " ";
    }
    cout << root->val;
    isFirst = false;
}


int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    stack<int> myStack;
    int indexpre = 0;
    int indexin = 0;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> s;
        if (s == "Push") {
            int t;
            cin >> t;
            myStack.push(t);
            pre[indexpre++] = t;
        } else {
            in[indexin++] = myStack.top();
            myStack.pop();
        }
    }
    node *root = create(0, n - 1, 0, n - 1);
    post(root);

    return 0;
}

