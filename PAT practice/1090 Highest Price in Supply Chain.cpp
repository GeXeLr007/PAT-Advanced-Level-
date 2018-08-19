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

const int MAXN = 100010;
struct node {
    vector<int> child;
};

node Node[MAXN];

int maxDepth;
int cnt = 0;

void dfs(int index, int depth) {
    if (Node[index].child.size() == 0) {
        if (depth == maxDepth) {
            cnt++;
        } else if (depth > maxDepth) {
            cnt = 1;
            maxDepth = depth;
        }
    } else {
        for (int i = 0; i < Node[index].child.size(); ++i) {
            dfs(Node[index].child[i], depth + 1);
        }
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    double price, r;
    cin >> n >> price >> r;
    r /= 100;
    int root;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        if (t == -1) {
            root = i;
        } else {
            Node[t].child.push_back(i);
        }
    }
    dfs(root, 0);
    printf("%.2lf %d", pow(1 + r, maxDepth) * price, cnt);

    return 0;
}
