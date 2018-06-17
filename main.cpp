#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;


struct bign {
    int data[1000];
    int len=0;
    int isfu = false;

    bign(string &s) {
        if (s[0] == '-') {
            isfu = true;
            s.erase(0, 1);
        }

        for (int i = 0; i < s.size(); ++i) {
            data[len++] = s[s.size() - 1 - i]-'0';
        }
    }
};

bign add(bign b1, bign b2);

int main() {
//    freopen("infile1.txt", "r", stdin);

    string s = "-4255432";
    bign b=bign(s);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        bign b1=bign(s1),b2=bign(s2),b3=bign(s3);
        bign tmp=add(b1,b2);
    }


    return 0;
}

bign add(bign b1, bign b2) {



    return b1(__cxx11::basic_string());
}