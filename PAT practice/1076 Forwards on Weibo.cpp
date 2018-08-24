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
    int index;
    int level;
};

const int maxn = 1010;
vector<Node> G[maxn];
int n, l;
bool vis[maxn] = {false};
int cnt = 0;

void bfs(int index) {
    queue<Node> q;
    Node start;
    start.index = index;
    start.level = 0;
    q.push(start);
    vis[index] = true;
    while (!q.empty()) {
        Node nowVist = q.front();
        q.pop();
        if (nowVist.level != 0 && nowVist.level <= l) {
            cnt++;
        }

        int u = nowVist.index;
        for (int i = 0; i < G[nowVist.index].size(); ++i) {
            Node next = G[u][i];
            next.level = nowVist.level + 1;
            if (vis[next.index] == false) {
                q.push(next);
                vis[next.index] = true;
            }
        }
    }


}


int main() {
    freopen("infile1.txt", "r", stdin);
    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        Node ntmp = {i, 0};
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int t;
            cin >> t;
            G[t].push_back(ntmp);
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int query;
        cin >> query;
        for (int j = 0; j < maxn; ++j) {
            vis[j] = false;
        }
        cnt = 0;
        bfs(query);
        printf("%d\n", cnt);
    }


    return 0;
}
