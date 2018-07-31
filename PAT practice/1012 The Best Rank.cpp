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
    int num;
    int grades[4];

    Stu(int _num, int _c, int _m, int _e) {
        num = _num;
        grades[1] = _c;
        grades[2] = _m;
        grades[3] = _e;
        grades[0] = _c + _m + _e;
    }

    Stu() {}
};

int Rank[1000010][4] = {0};
int now;

bool cmp(const Stu &s1, const Stu &s2) {
    return s1.grades[now] > s2.grades[now];
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    vector<Stu> v(N);
    for (int i = 0; i < N; ++i) {
        int num, c, m, e;
        cin >> num >> c >> m >> e;
        Stu s(num, c, m, e);
        v[i] = s;
    }
    vector<int> check(M);
    for (int i = 0; i < M; ++i) {
        cin >> check[i];
    }

    for (int j = 0; j < 4; ++j) {
        int index = 1;
        now = j;
        sort(v.begin(), v.end(), cmp);
//        这种排序包含并列排名
        for (int i = 0; i < v.size(); ++i) {
            if (i != 0 && v[i - 1].grades[now] != v[i].grades[now]) {
                index = i + 1;
            }
            Rank[v[i].num][j] = index;
        }
    }

    char out[] = {'A', 'C', 'M', 'E'};
    for (int i = 0; i < M; ++i) {
        int num = check[i];
        int minindex = 0, min = 10000;
//        用这种存储结构可以简化优先级的逻辑
        for (int j = 0; j < 4; ++j) {
            if (Rank[num][j] < min) {
                min = Rank[num][j];
                minindex = j;
            }
        }
        if (min==0){
            printf("N/A\n");
        } else{
            printf("%d %c\n", min, out[minindex]);

        }
    }


    return 0;
}


