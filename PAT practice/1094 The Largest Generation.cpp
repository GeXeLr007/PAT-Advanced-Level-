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

const int MAXN = 110;
vector<int> Node[MAXN];
int hashmap[MAXN] = {0};

void dfs(int index, int level) {
    hashmap[level]++;
    for (int i = 0; i < Node[index].size(); ++i) {
        dfs(Node[index][i], level + 1);
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int parent, num;
        cin >> parent >> num;
        for (int j = 0; j < num; ++j) {
            int t;
            cin >> t;
            Node[parent].push_back(t);
        }
    }
    dfs(1, 1);
    int max = -1, maxLevel = -1;
    for (int i = 0; i < MAXN; ++i) {
        if (hashmap[i] > max) {
            max = hashmap[i];
            maxLevel = i;
        }
    }
    cout << max << " " << maxLevel;

    return 0;
}
