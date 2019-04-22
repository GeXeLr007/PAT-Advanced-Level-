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
#include <set>

using namespace std;


int main() {
    //freopen("infile1.txt", "r", stdin);
    int w, h;
    cin >> w >> h;
    int memo[1010][1010] = {0};
    int cnt = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (memo[i][j] == 0) {
                cnt++;
                if (i + 2 < h && j + 2 < w) {
                    memo[i + 2][j] = -1;
                    memo[i][j + 2] = -1;
                }
            }
        }
    }
    cout << cnt;


    return 0;
}
