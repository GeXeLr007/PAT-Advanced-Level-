#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;


struct Stu {
    char name[15], id[15];
    int grade;
};


bool cmp(const Stu &s1, const Stu &s2) {
    return s1.grade > s2.grade;
}

int main() {
    freopen("infile1.txt", "r", stdin);

    int n;
    cin >> n;
    vector<Stu> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %s %d", v[i].name, v[i].id, &v[i].grade);
    }
    int min, max;
    cin >> min >> max;
    sort(v.begin(), v.end(), cmp);
    bool hasOut = false;
    for (int i = 0; i < n; ++i) {
        if (v[i].grade >= min && v[i].grade <= max) {
            hasOut = true;
            printf("%s %s\n", v[i].name, v[i].id);
        }
    }
    if (!hasOut) {
        printf("NONE");
    }

    return 0;
}


