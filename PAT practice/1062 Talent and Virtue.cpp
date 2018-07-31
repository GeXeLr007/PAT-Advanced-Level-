#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
//#include <cstring>
using namespace std;


struct Stu {
    int name;
    int vg, tg;
    int rank, sum;

    Stu(int _name, int _vg, int _tg, int _rank) : name(_name), vg(_vg), tg(_tg), rank(_rank) {
        sum = vg + tg;
    }

    Stu() {

    }
};

bool cmp(const Stu &s1, const Stu &s2) {
    if (s1.rank != s2.rank) {
        return s1.rank > s2.rank;
    } else if (s1.sum != s2.sum) {
        return s1.sum > s2.sum;
    } else if (s1.vg != s2.vg) {
        return s1.vg > s2.vg;
    } else {
        return s1.name < s2.name;
    }
}


int main() {
    freopen("infile1.txt", "r", stdin);
//    超时很有可能是因为用了cin
    int n, L, H;
    cin >> n >> L >> H;
    vector<Stu> v(n);
    int index = 0;
    for (int i = 0; i < n; ++i) {
        int name;
        int vg, tg, rank = 0;
        scanf("%d %d %d", &name, &vg, &tg);
        if (vg >= H && tg >= H) {
            rank = 4;
        } else if (tg >= L && tg < H && vg >= H) {
            rank = 3;
        } else if (vg >= L && vg < H && tg < H && tg >= L && vg >= tg) {
            rank = 2;
        } else if (vg >= L && tg >= L) {
            rank = 1;
        }
        if (rank != 0) {
            Stu s(name, vg, tg, rank);
            v[index++] = s;
        }
    }
    sort(v.begin(), v.end(), cmp);

    cout << index << endl;
    for (int i = 0; i < index; ++i) {
        printf("%d %d %d\n", v[i].name, v[i].vg, v[i].tg);
    }

    return 0;
}


