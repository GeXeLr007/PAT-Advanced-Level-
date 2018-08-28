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


const int maxn = 1010;  //可能因为数组空间太小出错
vector<int> G[maxn];
int n, m, k;
bool vis[maxn] = {false};
int nowDel;
int block;

void dfs(int index) {
    vis[index] = true;
    for (int i = 0; i < G[index].size(); ++i) {
        if (vis[G[index][i]] == false && G[index][i] != nowDel) {
            dfs(G[index][i]);
        }
    }
}


int main() {
    freopen("infile1.txt", "r", stdin);

    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        G[t1].push_back(t2);
        G[t2].push_back(t1);
    }

    for (int i = 0; i < k; ++i) {
        int query;
        scanf("%d", &query);
        nowDel = query;
        for (int j = 0; j < maxn; ++j) {
            vis[j] = false;
        }
        block = 0;
        for (int l = 1; l <= n; ++l) {
            if (vis[l] == false && l != nowDel) {
                dfs(l);
                block++;
            }
        }
        printf("%d\n", block - 1);
    }


    return 0;
}
