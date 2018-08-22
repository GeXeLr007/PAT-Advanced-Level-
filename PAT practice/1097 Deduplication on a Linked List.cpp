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
    int data;
    int next = -1;
};
Node memo[1000010];

int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    int head;
    cin >> head >> n;
    for (int i = 0; i < n; ++i) {
        int addr;
        scanf("%d", &addr);
        scanf("%d %d", &memo[addr].data, &memo[addr].next);
    }
    int hashmap[10010] = {0};
    int cur = head, pre = 100009;
    memo[pre].next = head;
    int newHead = 100005, newCur = newHead;
    while (cur != -1) {
        if (hashmap[abs(memo[cur].data)] != 0) {
            memo[pre].next = memo[cur].next;
            memo[cur].next = -1;

            memo[newCur].next = cur;
            newCur = cur;

            cur = memo[pre].next;
        } else {
            hashmap[abs(memo[cur].data)]++;
            cur = memo[cur].next;
            pre = memo[pre].next;
        }
    }

    cur = head;
    newCur = memo[newHead].next;
    while (cur != -1) {
        if (memo[cur].next != -1) {
            printf("%05d %d %05d\n", cur, memo[cur].data, memo[cur].next);
        } else {
            printf("%05d %d -1\n", cur, memo[cur].data);
        }
        cur = memo[cur].next;
    }

    while (newCur != -1) {
        if (memo[newCur].next != -1) {
            printf("%05d %d %05d\n", newCur, memo[newCur].data, memo[newCur].next);
        } else {
            printf("%05d %d -1", newCur, memo[newCur].data);
        }
        newCur = memo[newCur].next;
    }


    return 0;
}
