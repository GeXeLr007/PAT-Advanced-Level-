#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;


int C;

struct Stu {
    char column[3][10];
};

bool cmp(const Stu &s1, const Stu &s2) {
    if (C != 1) {
        if (strcmp(s1.column[C - 1], s2.column[C - 1]) != 0) {
            return strcmp(s1.column[C - 1], s2.column[C - 1]) <= 0;
        } else {
            return strcmp(s1.column[0], s2.column[0]) < 0;
        }
    } else {
        return strcmp(s1.column[0], s2.column[0]) < 0;
    }
}


int main() {
    freopen("infile1.txt", "r", stdin);
    int N;
    cin >> N >> C;
    vector<Stu> v(N);
    for (int i = 0; i < N; ++i) {
        Stu stu;
        scanf("%s %s %s", stu.column[0], stu.column[1], stu.column[2]);
        v[i] = stu;
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; ++i) {
        printf("%s %s %s\n", v[i].column[0], v[i].column[1], v[i].column[2]);
    }


    return 0;
}


