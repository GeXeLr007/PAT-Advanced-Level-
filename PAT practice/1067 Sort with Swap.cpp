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

    int n;
    scanf("%d", &n);
    int pos[n];
    int left = n - 1, cnt = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        pos[t] = i;
        if (t != 0 && t == i) {
            left--;
        }
    }

    int k = 1;

    while (left != 0) {
        if (pos[0] == 0) {
            while (k < n) {
                if (pos[k] != k) {
                    swap(pos[0], pos[k]);
                    cnt++;
                    break;
                }
                k++;
            }
        }
        while (pos[0] != 0) {
            swap(pos[0], pos[pos[0]]);
            left--;
            cnt++;
        }
    }
    printf("%d", cnt);


    return 0;
}
