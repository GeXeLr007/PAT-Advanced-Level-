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

const int maxn = 1010;
int n;
vector<int> CBT(maxn);
vector<int> num(maxn);

int myindex = 0;

void inoreder(int root) {
    if (root > n) {
        return;
    }
    inoreder(root * 2);
    CBT[root] = num[myindex++];
    inoreder(root * 2 + 1);
}

int main() {
    freopen("infile1.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    sort(num.begin(), num.begin() + n);
    inoreder(1);
    for (int i = 1; i <= n; ++i) {
        if (i != 1) {
            printf(" ");
        }
        printf("%d", CBT[i]);
    }


    return 0;
}
