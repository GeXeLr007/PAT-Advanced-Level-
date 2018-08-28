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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int sum1 = 0, sum2 = 0;
    int mid = n / 2;
    for (int i = 0; i < mid; ++i) {
        sum1 += v[i];
    }
    for (int i = mid; i < n; ++i) {
        sum2 += v[i];
    }
    int cha = sum2 - sum1;
    if (n % 2 == 0) {
        printf("0 ");
    } else {
        printf("1 ");
    }
    printf("%d", cha);


    return 0;
}
