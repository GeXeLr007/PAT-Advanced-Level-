#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;


struct Stu {
    string name;
    string password;
};

bool change(string &s) {
    int size = s.size();
    bool ret = false;
    for (int i = 0; i < size; ++i) {
        if (s[i] == '1') {
            s[i] = '@';
            ret = true;
        } else if (s[i] == '0') {
            s[i] = '%';
            ret = true;
        } else if (s[i] == 'l') {
            s[i] = 'L';
            ret = true;
        } else if (s[i] == 'O') {
            s[i] = 'o';
            ret = true;
        }
    }
    return ret;
}

int main() {
    freopen("infile1.txt", "r", stdin);
    int n;
    cin >> n;
    vector<Stu> v;
    for (int i = 0; i < n; ++i) {
        string name, password;
        cin >> name >> password;
        bool ischange = change(password);
        if (ischange) {
            Stu s = {name, password};
            v.push_back(s);
        }
    }
    int size = v.size();
    if (size == 0) {
        if (n == 1) {
            printf("There is 1 account and no account is modified");
        } else {
            printf("There are %d accounts and no account is modified", n);
        }
    } else {
        printf("%d\n", size);
        for (int i = 0; i < size; ++i) {
            cout << v[i].name << " " << v[i].password << endl;
        }
    }


    return 0;
}

