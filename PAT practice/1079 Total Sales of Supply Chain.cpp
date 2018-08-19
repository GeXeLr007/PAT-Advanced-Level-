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
    int data;
};

node Node[MAXN];
double sum = 0, r, price;

void dfs(int index, int depth) {
    if (Node[index].child.size() == 0) {
        sum += pow(1 + r, depth) * price * Node[index].data;
    }
    for (int i = 0; i < Node[index].child.size(); ++i) {
        dfs(Node[index].child[i], depth + 1);
    }

}

int main() {
    freopen("infile1.txt", "r", stdin);
    int n;

    cin >> n >> price >> r;
    r /= 100;

    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        if (num == 0) {
            scanf("%d", &Node[i].data);
        } else {
            for (int j = 0; j < num; ++j) {
                int t;
                scanf("%d", &t);
                Node[i].child.push_back(t);
            }
        }
    }
    dfs(0, 0);
    printf("%.1lf", sum);

    return 0;
}
