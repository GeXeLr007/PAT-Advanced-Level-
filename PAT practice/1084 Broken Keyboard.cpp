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


int main() {
    freopen("infile1.txt", "r", stdin);

    string s1, s2;
    cin >> s1 >> s2;
    int book[300] = {0};
    for (int i = 0; i < s1.size(); ++i) {
        int res = s2.find(s1[i]);
        if (res == -1 && book[toupper(s1[i])] == 0) {
            book[toupper(s1[i])] = 1;
            printf("%c",toupper(s1[i]));
        }
    }

}