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
    int start, data;
};

int main() {
    freopen("infile1.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> v(n);
    bool allFu = true;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
        if (v[i] >= 0) {
            allFu = false;
        }
    }
    vector<Node> dp(n);
    dp[0].data = v[0];
    dp[0].start = 0;
    for (int i = 1; i < n; ++i) {
        if (dp[i - 1].data > 0) {
            dp[i].data = dp[i - 1].data + v[i];
            dp[i].start = dp[i - 1].start;
        } else {
            dp[i].data = v[i];
            dp[i].start = i;
        }
    }
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i].data > dp[k].data) {
            k = i;
        }
    }
    if (allFu) {
        printf("0 %d %d", v[0], v[n-1]);
    } else {
        printf("%d %d %d", dp[k].data, v[dp[k].start], v[k]);
    }


    return 0;
}
