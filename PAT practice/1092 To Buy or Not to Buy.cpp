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

    string s="gtiruhvj";
    s.erase(2,3);

    string s1,s2;
    cin>>s1>>s2;
    bool isFull=true;
    int cnt=0;
    for (int i = 0; i < s2.size(); ++i) {
        int res=s1.find(s2[i]);
        if(res==-1){
            isFull=false;
            cnt++;
        } else{
            s1.erase(res,1);
        }
    }
    if(isFull){
        printf("Yes %d",s1.size());
    }else{
        printf("No %d",cnt);
    }

}