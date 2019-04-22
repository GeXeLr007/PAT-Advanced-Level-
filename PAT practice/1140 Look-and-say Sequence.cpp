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

const int maxn = 1000000;

int main() {
    freopen("infile1.txt", "r", stdin);
    int d, n;
    cin >> d >> n;
    char str[2][maxn];
    int index = 0;
    str[index % 2][0] = d + '0';

    for (int k = 0; k < n - 1; ++k) {
        int num = 0;
        char cur = str[index % 2][0];
        int cnt = 1;
        for (int i = 1; str[index % 2][i] != '\0'; ++i) {
            if (cur == str[index % 2][i]) {
                cnt++;
            } else {
                str[(index + 1) % 2][num++] = cur;
                str[(index + 1) % 2][num++] = cnt + '0';

                cnt = 1;
                cur = str[index % 2][i];
            }
        }
        str[(index + 1) % 2][num++] = cur;
        str[(index + 1) % 2][num++] = cnt + '0';
        index++;
    }
    printf("%s", str[(index) % 2]);


    return 0;
}
