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


struct Node {
    int data = 100010;
    int next;
    int addr;
    int isIn = -1;
};

vector<Node> memo(100010);

bool cmp(const Node &n1, const Node &n2) {
    if (n1.isIn != n2.isIn) {
        return n1.isIn > n2.isIn;
    } else {
        return n1.data < n2.data;
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    int head;
    cin >> n >> head;
    for (int i = 0; i < n; ++i) {
        int addr;
        scanf("%d", &addr);
        scanf("%d %d", &memo[addr].data, &memo[addr].next);
        memo[addr].addr = addr;
    }

    int cur = head;
    int num;
    while (cur != -1) {
        memo[cur].isIn = 1;
        num++;
        cur = memo[cur].next;
    }

    if (num == 0) {
        printf("0 -1");
    } else {
        sort(memo.begin(), memo.end(), cmp);
        printf("%d %05d\n", num, memo[0].addr);
        for (int i = 0; i < num; ++i) {
            if (i == num - 1) {
                memo[i].next = -1;
                printf("%05d %d -1", memo[i].addr, memo[i].data);
            } else {
                memo[i].next = memo[i + 1].addr;
                printf("%05d %d %05d\n", memo[i].addr, memo[i].data, memo[i].next);
            }
        }
    }

    return 0;
}
