#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

struct time {
    int h, m, s;


    time(string &str) {
        h = stoi(str.substr(0, 2));
        m = stoi(str.substr(3, 5));
        s = stoi(str.substr(6, 8));
    };
};

bool myless(time t1, time t2) {
    if (t1.h != t2.h) return t1.h < t2.h;
    if (t1.m != t2.m) return t1.m < t2.m;
    return t1.s < t2.s;
}


int main() {
    freopen("infile1.txt", "r", stdin);

//    有时候用结构体在本地环境可以通过，但是提交上去就编译出错了，则要换一种解法
    int n;
    cin >> n;
    string strs[n];
    time tstart[n], tend[n];
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> strs[i] >> s1 >> s2;
        tstart[i] = time(s1);
        tend[i] = time(s2);
    }
    int mini = 0, maxi = 0;
    for (int i = 0; i < n; ++i) {
        if (myless(tstart[i], tstart[mini])) {
            mini = i;
        }
        if (myless(tend[maxi], tend[i])) {
            maxi = i;
        }
    }
    cout << strs[mini] << " " << strs[maxi];


    return 0;
}

