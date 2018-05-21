#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

//    freopen("infile1.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
    }
    int ret = n * 5;
    for (int j = 1; j <= n; ++j) {
        int cha = v[j] - v[j - 1];
        ret = ret + (cha > 0 ? cha * 6 : -cha * 4);
    }
    cout<<ret;


    return 0;
}