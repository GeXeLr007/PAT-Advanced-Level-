#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <cstring>


using namespace std;

bool check(vector<string> &v, int index) {
    for (int i = 0; i < v.size()-1; i++)
    {
        if (!(v[i][index] == v[i + 1][index])) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    cin >> n;
    getchar();
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        getline(cin, v[i]);
        reverse(v[i].begin(), v[i].end());
    }
    int index = 0;
    while (check(v,index)) {
        index++;
    }
    if (index==0)
    {
        cout << "nai";
    }
    else {
        string out = v[0].substr(0, index);
        reverse(out.begin(), out.end());
        cout << out;
    }


    return 0;
}


