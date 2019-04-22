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

const int maxn = 2147483647;

int main() {
    freopen("infile1.txt", "r", stdin);

    int n;
    cin >> n;
    set<int> s;

    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        if (t > 0) {
            s.insert(t);
        }
    }
    for (int i = 1; i <= maxn; ++i) {
        if (s.find(i) == s.end()) {
            cout << i;
            return 0;
        }
    }


    return 0;
}

