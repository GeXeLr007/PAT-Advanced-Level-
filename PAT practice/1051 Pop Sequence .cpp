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
    int m, n, k;
    cin >> m >> n >> k;
    stack<int> mystack;
    for (int i = 0; i < k; ++i) {
        while (!mystack.empty()) {
            mystack.pop();
        }
        bool flag = true;
        int w = 0;
        for (int j = 0; j < n; ++j) {
            int t;
            scanf("%d", &t);
            if (flag) {
                while (mystack.empty() || mystack.top() < t) {
                    mystack.push(++w);
                }
                if (mystack.size() > m) {
                    flag = false;
                }
                if (mystack.top() == t) {
                    mystack.pop();
                }
            }
        }
        if (mystack.empty()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }


    return 0;
}
