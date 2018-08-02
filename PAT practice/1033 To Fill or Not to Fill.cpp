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


struct Station {
    double price;
    int dis;
};

bool cmp(const Station &s1, const Station &s2) {
    return s1.dis < s2.dis;
}

int main() {
    freopen("infile1.txt", "r", stdin);
    double Cmax, D, Davg;
    int n;
    cin >> Cmax >> D >> Davg >> n;
    vector<Station> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lf %d", &v[i].price, &v[i].dis);
    }
    Station stmp = {0, D};
    v.push_back(stmp);
    sort(v.begin(), v.end(), cmp);

    int now = 0, tankCount = 0;
    double ans = 0;
    if (v[0].dis != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        while (now < n) {
            double minPrice = 10000, MAX = Cmax * Davg;
            int k = -1;
            for (int i = now + 1; i <= n && v[i].dis - v[now].dis <= MAX; ++i) {
                if (v[i].price < minPrice) {
                    minPrice = v[i].price;
                    k = i;

                    if (v[now].price > minPrice) {
                        break;
                    }
                }
            }
            if (k == -1) {
                printf("The maximum travel distance = %.2lf", v[now].dis + MAX);
                return 0;
            }

            int needGas = (v[k].dis - v[now].dis) / Davg;
            if (minPrice < v[now].price) {
                if (tankCount < needGas) {
                    ans += (needGas - tankCount) * v[now].price;
                    tankCount = 0;
                } else {
                    tankCount -= needGas;
                }
            } else {
                ans += (Cmax - tankCount) * v[now].price;
                tankCount = Cmax - needGas;
            }
            now = k;
        }
        printf("%.2lf", ans);

    }


    return 0;
}