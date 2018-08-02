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

    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    unordered_map<int,int> map;
    for (int i = 0; i < s1.size(); ++i) {
        map[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); ++i) {
        map[s2[i]]=0;
    }
    for (int i = 0; i < s1.size(); ++i) {
        if(map[s1[i]]!=0){
            printf("%c",s1[i]);
        }
    }


    return 0;
}