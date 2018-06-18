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
    vector<double> v1(1100), v2(1100), vout(1100);
    int n;
    cin >> n;
    while (n--) {
        int index;
        double num;
        cin >> index >> num;
        v1[index] = num;
    }
    cin >> n;
    while (n--) {
        int index;
        double num;
        cin >> index >> num;
        v2[index] = num;
    }

    for (int i = 0; i < v1.size(); ++i) {
        vout[i] = v1[i] + v2[i];
    }
    int cnt = 0;
    for (int i = 0; i < vout.size(); ++i) {
        if (vout[i] != 0)
            cnt++;
    }
    cout << cnt;
    for (int i = vout.size() - 1; i >= 0; --i) {
        if (vout[i] != 0) {
            printf(" %d %.1lf", i, vout[i]);
        }
    }


    return 0;
}

