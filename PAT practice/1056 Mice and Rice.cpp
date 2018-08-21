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
#include <queue>

using namespace std;


struct Mouse {
    int weight, rank;
};

int main() {
    freopen("infile1.txt", "r", stdin);
    int np, ng;
    cin >> np >> ng;
    Mouse mouses[np];
    for (int i = 0; i < np; ++i) {
        scanf("%d", &mouses[i].weight);
    }
    queue<int> q;
    for (int i = 0; i < np; ++i) {
        int t;
        scanf("%d", &t);
        q.push(t);
    }
    int temp = np;
    while (q.size() != 1) {
        int group = temp % ng == 0 ? temp / ng : temp / ng + 1;
        for (int i = 0; i < group; ++i) {
            int max = q.front();
            for (int j = 0; j < ng; ++j) {

                if (i * ng + j >= temp) {
                    break;
                }

                int t = q.front();
                mouses[t].rank = group + 1;
                if (mouses[t].weight > mouses[max].weight) {
                    max = t;
                }
                q.pop();
            }
            q.push(max);
        }
        temp = group;
    }
    mouses[q.front()].rank = 1;

    for (int i = 0; i < np; ++i) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", mouses[i].rank);
    }


    return 0;
}
