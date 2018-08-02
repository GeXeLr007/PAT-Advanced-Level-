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
    int ge, gi, sum, rank, id;
    vector<int> choices;
};

struct Sch {
    int quoto;
    vector<int> ids;
    int lastRank = -1;
};


bool cmp(const Stu &s1, const Stu &s2) {
    if (s1.sum != s2.sum) {
        return s1.sum > s2.sum;
    } else {
        return s1.ge > s2.ge;    //不懂为什么这里变成了>=会有段错误！！！
    }
}

bool cmpsch(int i1, int i2) {
    return i1 < i2;
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;
    vector<Sch> vsch(m);
//    获取每个学校的名额
    for (int i = 0; i < m; ++i) {
        cin >> vsch[i].quoto;
    }

    vector<Stu> vstu(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &(vstu[i].ge), &(vstu[i].gi));
        vstu[i].sum = vstu[i].ge + vstu[i].gi;
        for (int j = 0; j < k; ++j) {
            int t;
            scanf("%d", &t);
            vstu[i].choices.push_back(t);
        }
        vstu[i].id = i;
    }
    sort(vstu.begin(), vstu.end(), cmp);


    for (int i = 0; i < n; ++i) {
        if (i > 0 && vstu[i].sum == vstu[i - 1].sum && vstu[i].ge == vstu[i - 1].ge) {
            vstu[i].rank = vstu[i - 1].rank;
        } else {
            vstu[i].rank = i;
        }
    }

    for (int j = 0; j < n; ++j) {
        for (int l = 0; l < k; ++l) {
            if (vsch[vstu[j].choices[l]].quoto > 0 || vsch[vstu[j].choices[l]].lastRank == vstu[j].rank) {
                vsch[vstu[j].choices[l]].quoto--;
                vsch[vstu[j].choices[l]].ids.push_back(vstu[j].id);
                vsch[vstu[j].choices[l]].lastRank = vstu[j].rank;
                break;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        if (vsch[j].ids.size() > 0) {
            sort(vsch[j].ids.begin(), vsch[j].ids.end(), cmpsch);
            for (int l = 0; l < vsch[j].ids.size(); ++l) {
                if (l != 0) {
                    printf(" ");
                }
                printf("%d", vsch[j].ids[l]);
            }
        }
        printf("\n");
    }


    return 0;
}



