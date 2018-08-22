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
    char data;
    int next;
};

Node memo[100010];

int main() {
    freopen("infile1.txt", "r", stdin);
    int head1, head2, n;
    cin >> head1 >> head2 >> n;
    for (int i = 0; i < n; ++i) {
        int addr, next;
        char c;
        scanf("%d %c %d", &addr, &c, &next);
        memo[addr].data = c;
        memo[addr].next = next;
    }
    int cur1 = head1;
    int cur2 = head2;
    int num1 = 0, num2 = 0;
    while (cur1 != -1) {
        num1++;
        cur1 = memo[cur1].next;
    }
    while (cur2 != -1) {
        num2++;
        cur2 = memo[cur2].next;
    }

    cur1 = head1;
    cur2 = head2;
    if (num1 > num2) {
        int cha = num1 - num2;
        for (int i = 0; i < cha; ++i) {
            cur1 = memo[cur1].next;
        }
    } else {
        int cha = num2 - num1;
        for (int i = 0; i < cha; ++i) {
            cur2 = memo[cur2].next;
        }
    }
    while (cur1 != cur2 && cur1 != -1 && cur2 != -1) {
        cur1 = memo[cur1].next;
        cur2 = memo[cur2].next;
    }
    if (cur1 == cur2) {
        if(cur1==-1){
            printf("-1");
        } else{
            printf("%05d", cur1);
        }
    } else {
        printf("-1");
    }


    return 0;
}

