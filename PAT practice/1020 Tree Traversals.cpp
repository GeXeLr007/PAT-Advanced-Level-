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
    int data;
    node *left;
    node *right;
};


const int MAXN = 50;
int num = 0, n = 0;
int level[MAXN], in[MAXN], post[MAXN];

node *create(int postL, int postR, int inL, int inR) {
//    为什么会出现这种情况？
    if (postL > postR) {
        return NULL;
    }
    node *root = new node;
    root->data = post[postR];
    int k;
    for (k = inL; k <= inR; ++k) {
        if (in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k - inL;
    root->left = create(postL, postL + numLeft - 1, inL, k - 1);
    root->right = create(postL + numLeft, postR - 1, k + 1, inR);
    return root;
}

void bfs(node *root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *&front = q.front();
        q.pop();
        cout << front->data;
        num++;
        if (num < n) {
            cout << " ";
        }
        if (front->left != NULL) {
            q.push(front->left);
        }
        if (front->right != NULL) {
            q.push(front->right);
        }

    }

}

int main() {
    freopen("infile1.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    node *root = create(0, n - 1, 0, n - 1);
    bfs(root);


    return 0;
}