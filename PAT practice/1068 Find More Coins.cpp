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

const int maxn = 10000 + 4;
const int maxv = 105;
int coins[maxn];
int dp[maxv]; //dp[v]表示：总和加起来=v的序列中最后一个值最小为多少。
int chosen[maxn][maxv];
int ans[maxn];
int cnt = 0;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("infile1.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    sort(coins, coins + n, cmp);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = m; j >= coins[i]; j--) {
            if (dp[j] <= dp[j - coins[i]] + coins[i]) {
                dp[j] = dp[j - coins[i]] + coins[i];
                chosen[i][j] = 1;
            }
        }
    }
    if (dp[m] != m) {
        printf("No Solution");
    } else {
        int v = m, idx = n - 1;
        while (v) {
            if (chosen[idx][v]) {
                ans[cnt++] = coins[idx];
                v -= coins[idx];
            }
            idx--;
        }
        printf("%d", ans[0]);
        for (int i = 1; i < cnt; i++)
            printf(" %d", ans[i]);
    }
    return 0;
}
