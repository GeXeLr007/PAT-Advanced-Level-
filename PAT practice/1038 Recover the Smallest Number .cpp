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

using namespace std;


bool cmp(const string &s1, const string &s2) {
    return s1 + s2 < s2 + s1;
}

int main() {
    freopen("infile1.txt", "r", stdin);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    string s;
    for (int i = 0; i < n; ++i) {
        s += v[i];
    }
    int i = 0;
    while (s[i] == '0' && i < s.size()) {
        i++;
    }
    if (s.size() == i) {
        cout << 0;
    } else {
        cout << s.substr(i);
    }

    return 0;
}
