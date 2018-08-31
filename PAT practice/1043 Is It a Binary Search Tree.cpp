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

struct Node {
    int data;
    Node *left, *right;
};

void insert(Node *&root, int data) {
    if (root == NULL) {
        root = new Node;
        root->data = data;
        root->right = NULL;
        root->left = NULL;
        return;
    } else {
        if (data < root->data) {
            insert(root->left, data);
        } else {
            insert(root->right, data);
        }
    }
}

void preorder(Node *root, vector<int> &v) {
    if (root == NULL) {
        return;
    }
    v.push_back(root->data);
    preorder(root->left, v);
    preorder(root->right, v);
}

void preorderMirror(Node *root, vector<int> &v) {
    if (root == NULL) {
        return;
    }
    v.push_back(root->data);
    preorderMirror(root->right, v);
    preorderMirror(root->left, v);
}

void postorder(Node *root, vector<int> &v) {
    if (root == NULL) {
        return;
    }
    postorder(root->left, v);
    postorder(root->right, v);
    v.push_back(root->data);
}

void postorderMirror(Node *root, vector<int> &v) {
    if (root == NULL) {
        return;
    }
    postorderMirror(root->right, v);
    postorderMirror(root->left, v);
    v.push_back(root->data);
}


int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> origin(n), pre, preM, post, postM;
    Node *root = NULL;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &origin[i]);
        insert(root, origin[i]);
    }

    preorder(root, pre);
    preorderMirror(root, preM);
    postorder(root, post);
    postorderMirror(root, postM);

    if (origin == pre) {
        printf("YES\n");
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", post[i]);
        }
    } else if (origin == preM) {
        printf("YES\n");
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                printf(" ");
            }
            printf("%d", postM[i]);
        }
    } else {
        printf("NO");
    }


    return 0;
}
