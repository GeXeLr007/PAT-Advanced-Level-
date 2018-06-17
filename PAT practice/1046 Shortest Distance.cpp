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
    int N;
    cin >> N;
    vector<int> dis(N + 2);
    for (int i = 0; i < N; ++i) {
        int t;
        scanf("%d", &t);
        dis[i + 2] += (t + dis[i + 1]);
    }
    int sumdis = dis[N + 1];

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int i1, i2;
        cin >> i1 >> i2;
        if (i2 < i1) {
            int t = i1;
            i1 = i2;
            i2 = t;
        }
        int distmp = dis[i2] - dis[i1];
        int out = min(distmp, sumdis - distmp);
        printf("%d\n", out);

    }


    return 0;
}