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

struct Point {
    int i, j;
};


int main() {
    freopen("infile2.txt", "r", stdin);

    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    vector<Point> vp;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    int sum = 0;
    int i = 0, j = -1;
    int minDiff = 100000000;
    while (j < n) {
        if (sum < target) {
            j++;
            sum += v[j];
        } else {
            int diff = sum - target;

            if (diff < minDiff) {
                vp.clear();
                minDiff = diff;
                Point p = {i, j};
                vp.push_back(p);
            } else if (diff == minDiff) {
                Point p = {i, j};
                vp.push_back(p);
            }

            if (sum > target) {
                sum -= v[i];
                i++;
            } else {
                printf("%d-%d\n", i + 1, j + 1);
                j++;
                sum += v[j];
            }
        }
    }
    if (minDiff != 0) {
        for (int i = 0; i < vp.size(); ++i) {
            printf("%d-%d\n", vp[i].i + 1, vp[i].j + 1);
        }
    }

    return 0;
}

