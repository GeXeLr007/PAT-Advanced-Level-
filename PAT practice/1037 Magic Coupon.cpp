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

using namespace std;


int main() {
    freopen("infile1.txt", "r", stdin);

    int m, n, ans = 0, p = 0, q = 0;
    scanf("%d", &m);
    vector<int> v1(m);
    for(int i = 0; i < m; i++)
        scanf("%d", &v1[i]);
    scanf("%d", &n);
    vector<int> v2(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v2[i]);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while(p < m && q < n && v1[p] < 0 && v2[q] < 0) {
        ans += v1[p] * v2[q];
        p++; q++;
    }
    p = m - 1, q = n - 1;
    while(p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0) {
        ans += v1[p] * v2[q];
        p--; q--;
    }
    printf("%d", ans);


    return 0;
}
