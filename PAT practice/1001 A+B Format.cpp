#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;


int main() {

//    freopen("infile1.txt", "r", stdin);

    int a, b;
    scanf("%d %d", &a, &b);
    int c = a + b;
    bool isFu=false;
    if(c<0){
        isFu=true;
        c=-c;
    }

    string s1 = to_string(c);
    string s2 = "";
    int j = 1;
    for (int i = s1.size() - 1; i >= 0; --i) {
        s2.push_back(s1[i]);
        if (j % 3 == 0 && i != 0) {
            s2.push_back(',');
        }
        j++;
    }
    if (isFu){
        s2.push_back('-');
    }
    reverse(s2.begin(), s2.end());
    cout<<s2;

    return 0;
}