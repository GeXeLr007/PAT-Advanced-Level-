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
    int id;
    int score[5] = {-2, -2, -2, -2, -2};
    int sum;
    int fullSolveNum;
    int hasScore = -1;
};


bool cmp(const Stu &s1, const Stu &s2) {
    if (s1.sum != s2.sum) {
        return s1.sum >= s2.sum;
    } else if (s1.fullSolveNum != s2.fullSolveNum) {
        return s1.fullSolveNum >= s2.fullSolveNum;
    } else if (s1.hasScore != s2.hasScore) {
        return s1.hasScore > s2.hasScore;
    } else {
        return s1.id < s2.id;
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int N, K, M;
    cin >> N >> K >> M;
    int fullScore[K];
    for (int i = 0; i < K; ++i) {
        cin >> fullScore[i];
    }

    vector<Stu> v(10010);

    for (int j = 0; j < M; ++j) {
        int id, problemNum, problemScore;
        scanf("%d %d %d", &id, &problemNum, &problemScore);
        problemNum -= 1;
        v[id].id = id;
        if (problemScore > v[id].score[problemNum]) {
            v[id].score[problemNum] = problemScore;
            v[id].sum = 0;
            v[id].fullSolveNum = 0;
            for (int k = 0; k < K; ++k) {
                if (v[id].score[k] > 0) {
                    v[id].sum += v[id].score[k];
                }
                if (v[id].score[k] == fullScore[k]) {
                    v[id].fullSolveNum++;
                }
            }

            if (problemScore >= 0) {
                v[id].hasScore = 1;
            }
        }
    }
    sort(v.begin(), v.end(), cmp);

    int index = 1;
    int l = 0;
    printf("%d %05d %d", index, v[0].id, v[0].sum);
    for (int m = 0; m < K; ++m) {
        if (v[l].score[m] != -2) {
            printf(" %d", v[l].score[m] == -1 ? 0 : v[l].score[m]);
        } else {
            printf(" -");
        }
    }
    printf("\n");
    l++;

    for (; l < N; ++l) {
        if (v[l].hasScore == -1) {
            break;
        }
        if (v[l].sum != v[l - 1].sum) {
            index = l + 1;
        }
        printf("%d %05d %d", index, v[l].id, v[l].sum);
        for (int m = 0; m < K; ++m) {
            if (v[l].score[m] != -2) {
                printf(" %d", v[l].score[m] == -1 ? 0 : v[l].score[m]);
            } else {
                printf(" -");
            }
        }
        printf("\n");
    }


    return 0;
}


