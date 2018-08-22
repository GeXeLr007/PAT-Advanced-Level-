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
    int data, next;
};

int reverseOneGroup(int pre, int next);

Node memo[100010];

int main() {
    freopen("infile1.txt", "r", stdin);
    int head, n, k;
    cin >> head >> n >> k;  //k=1??,head=-1

    for (int i = 0; i < n; ++i) {
        int addr;
        scanf("%d", &addr);
        scanf("%d %d", &memo[addr].data, &memo[addr].next);
    }
    int num = 0;
    int cur = head;
    while (cur != -1) {
        cur = memo[cur].next;
        num++;
    }

    int dummy = 100000;
    memo[dummy].next = head;
    int pre = dummy;
    cur = head;
    int i = 0;
    while (cur != -1) {
        i++;
        if (i % k == 0) {
            pre = reverseOneGroup(pre, memo[cur].next);
            cur = memo[pre].next;
        } else {
            cur = memo[cur].next;
        }
    }

    cur = memo[dummy].next;
    while (cur != -1) {
        if (memo[cur].next == -1) {
            printf("%05d %d -1\n", cur, memo[cur].data);
        } else {
            printf("%05d %d %05d\n", cur, memo[cur].data, memo[cur].next);
        }
        cur = memo[cur].next;
    }


    return 0;
}

int reverseOneGroup(int pre, int next) {
    int last = memo[pre].next;
    int cur = memo[last].next;
    while (cur != next) {
        memo[last].next = memo[cur].next;
        memo[cur].next = memo[pre].next;
        memo[pre].next = cur;
        cur = memo[last].next;
    }
    return last;
}
