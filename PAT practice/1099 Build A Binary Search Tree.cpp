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
    int left, right;
};

const int maxn = 110;
Node tree[maxn];
int n;
vector<int> nums;
int myindex = 0;

void inorder(int root) {
    if (root == -1)
        return;
    inorder(tree[root].left);
    tree[root].data = nums[myindex++];
    inorder(tree[root].right);
}

int nnum = 0;

void levelorder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (nnum != 0) {
            printf(" ");
        }
        printf("%d", tree[now].data);
        nnum++;
        if (tree[now].left != -1)
            q.push(tree[now].left);
        if (tree[now].right != -1)
            q.push(tree[now].right);
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        tree[i].left = l;
        tree[i].right = r;
    }

    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end());
    inorder(0);
    levelorder(0);


    return 0;
}
