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

const int maxn = 110;
struct Node {
    int id, weight;
    vector<int> childIds;
};
Node tree[maxn];

bool cmp(int id1, int id2) {
    return tree[id1].weight > tree[id2].weight;
}

vector<vector<int>> out;
vector<int> temp;
int n, m, sum;
int nowSum = 0;

void dfs(int index) {

    if (tree[index].childIds.size() == 0 && nowSum == sum) {
        out.push_back(temp);
        return;
    } else {
        for (int i = 0; i < tree[index].childIds.size(); ++i) {
            int childIndex = tree[index].childIds[i];
            temp.push_back(tree[childIndex].weight);
            nowSum += tree[childIndex].weight;
            dfs(childIndex);
            nowSum -= tree[childIndex].weight;
            temp.pop_back();
        }
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);

    cin >> n >> m >> sum;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tree[i].weight);
    }
    for (int i = 0; i < m; ++i) {
        int id, num;
        scanf("%d %d", &id, &num);
        for (int j = 0; j < num; ++j) {
            int t;
            scanf("%d", &t);
            tree[id].childIds.push_back(t);
            sort(tree[id].childIds.begin(), tree[id].childIds.end(), cmp);
        }
    }

    temp.push_back(tree[0].weight);
    nowSum += tree[0].weight;
    dfs(0);

    for (int i = 0; i < out.size(); ++i) {
        for (int j = 0; j < out[i].size(); ++j) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", out[i][j]);
        }
        printf("\n");
    }


    return 0;
}
