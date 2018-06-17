#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main() {
//    freopen("infile1.txt", "r", stdin);

    int n;
    cin >> n;
    vector<int> next(55);
    for (int i = 1; i <= 54; ++i) {
        cin >> next[i];
    }
    vector<string> v_out;
    for (int i = 0; i < 54; ++i) {
        if (i <= 12) {
            string s = "S" + to_string(i + 1);
            v_out.push_back(s);
        }
        if (i >= 13 && i <= 25) {
            string s = "H" + to_string(i - 13 + 1);
            v_out.push_back(s);
        }
        if (i >= 26 && i <= 38) {
            string s = "C" + to_string(i - 26 + 1);
            v_out.push_back(s);
        }
        if (i >= 39 && i <= 51) {
            string s = "D" + to_string(i - 39 + 1);
            v_out.push_back(s);
        }
        if (i >= 52) {
            string s = "J" + to_string(i - 52 + 1);
            v_out.push_back(s);
        }
    }

    vector<int> start(55), end(55);
    for (int i = 1; i <= 54; ++i) {
        start[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= 54; ++j) {
            end[next[j]] = start[j];
        }
//        每进行完一次操作，都覆盖原始数组
        for (int j = 1; j <= 54; ++j) {
            start[j] = end[j];
        }
    }

    for (int i = 1; i <= 54; ++i) {
        if (i != 1) {
            cout << " ";
        }
        cout << v_out[start[i] - 1];
    }


    return 0;
}