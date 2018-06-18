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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long a, b, c;
        bool istrue = true;
        cin >> a >> b >> c;
        long long res = a + b;
        if (a < 0 && b < 0 && res >= 0) {
            istrue = false;
        } else if (a > 0 && b > 0 && res <= 0) {
            istrue = true;
        } else {
            istrue = res > c;
        }
        if (istrue) {
            printf("Case #%d: true\n", i + 1);

        } else {
            printf("Case #%d: false\n", i + 1);

        }
    }
    return 0;
}

