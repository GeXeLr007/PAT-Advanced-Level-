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

    string s;
    getline(cin, s);
    int ans = 1;
    bool dp[s.size()][s.size()];
    for (int i = 0; i < s.size(); ++i) {
        dp[i][i] = true;
        if (i < s.size() - 1 && s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            ans = 2;
        }
    }
    for (int L = 3; L <= s.size(); ++L) {
        for (int i = 0; i + L - 1 < s.size(); ++i) {
            int j = i + L - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == true) {
                dp[i][j] = true;
                ans = L;
            }
        }
    }
    cout << ans;


    return 0;
}
