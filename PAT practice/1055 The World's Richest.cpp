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
    char name[10];
    int age, worth;
};


bool cmp(const Stu &s1, const Stu &s2) {
    if (s1.worth != s2.worth) {
        return s1.worth >= s2.worth;
    } else if (s1.age != s2.age) {
        return s1.age <= s2.age;
    } else {
        return strcmp(s1.name, s2.name) < 0;
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);

//    现在还是超时，网上找的剪枝解法也是超时
    int N, K;
    cin >> N >> K;
    vector<Stu> v(N);
    for (int i = 0; i < N; ++i) {
        scanf("%s %d %d", v[i].name, &v[i].age, &v[i].worth);
    }
    sort(v.begin(), v.end(), cmp);
    vector<Stu> valid(N);
    int age[210] = {0};
    int index1 = 0;
    for (int j = 0; j < N; ++j) {
        if (age[v[j].age] < 100) {
            valid[index1++] = v[j];
            age[v[j].age]++;
        }
    }

    for (int i = 0; i < K; ++i) {
        int num, min, max;
        scanf("%d %d %d", &num, &min, &max);
        int index = 0;
        printf("Case #%d:\n", i + 1);
        for (int j = 0; j < index1 && index < num; ++j) {
            if (valid[j].age >= min && valid[j].age <= max) {
                printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
                index++;
            }
        }
        if (index == 0) {
            printf("None\n");
        }
    }


    return 0;
}


