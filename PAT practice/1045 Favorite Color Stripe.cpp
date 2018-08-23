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


int main() {
    freopen("infile1.txt", "r", stdin);

    int n, m, l;
    cin >> n;
    cin >> m;
    vector<int> order(n + 1, -1);
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        order[t] = i;
    }
    cin >> l;
    vector<int> v;
    for (int i = 0; i < l; ++i) {
        int t;
        scanf("%d", &t);
        if (order[t] >= 0) {
            v.push_back(order[t]);
        }
    }
    vector<int> dp(v.size(), 1);
    int ans = -1;
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (v[i] >= v[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(dp[i], ans);
    }

    cout << ans;

    return 0;
}
