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
vector<int> Node[MAXN];

int minDepth = 100010;
int cnt = 0;

void dfs(int index, int depth) {
    if (Node[index].size() == 0) {
        if (depth < minDepth) {
            cnt = 1;
            minDepth = depth;
        } else if (depth == minDepth) {
            cnt++;
        }
    }

    for (int i = 0; i < Node[index].size(); ++i) {
        dfs(Node[index][i], depth + 1);
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    double price, r;
    cin >> n >> price >> r;
    r /= 100;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int t;
            cin >> t;
            Node[i].push_back(t);
        }
    }
    dfs(0, 0);
    printf("%.4lf %d", pow(1 + r, minDepth) * price, cnt);

    return 0;
}
