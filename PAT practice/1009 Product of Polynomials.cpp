#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;


int main() {
//    freopen("infile1.txt", "r", stdin);
//    注意出现错误时，要考虑是不是数组太小，要重新考虑指数的范围
    vector<double> v1(2100), v2(2100), vout(2100);
    int n;
    cin >> n;
    while (n--) {
        int index;
        double value;
        cin >> index >> value;
        v1[index] = value;
    }
    cin >> n;
    while (n--) {
        int index;
        double value;
        cin >> index >> value;
        v2[index] = value;
    }
    for (int i = 0; i < v1.size(); ++i) {
        for (int j = 0; j < v2.size(); ++j) {
            if (v1[i] != 0 && v2[j] != 0) {
                vout[i + j] += v1[i] * v2[j];
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < vout.size(); ++i) {
        if (vout[i] != 0)
            cnt++;
    }
    cout << cnt;
    for (int i = vout.size() - 1; i >= 0; --i) {
        if (vout[i] != 0)
            printf(" %d %.1f", i, vout[i]);
    }


    return 0;
}

