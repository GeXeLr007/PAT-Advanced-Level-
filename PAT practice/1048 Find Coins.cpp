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

    int n, m;
    cin >> n >> m;
    map<int, int> mapp;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        mapp[t]++;
    }
    for (auto it = mapp.begin(); it != mapp.end(); it++) {
        if(mapp[it->first]!=0 && mapp[m-it->first]!=0){
            if(it->first == m-it->first && mapp[it->first]<2){
                continue;
            }
            printf("%d %d",it->first,m-it->first);
            return 0;
        }
    }
    printf("No Solution");

    return 0;
}