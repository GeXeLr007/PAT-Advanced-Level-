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

    int n;
    cin>>n;
    vector<int> v(n);
    unordered_map<int,int> map;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&v[i]);
        map[v[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if(map[v[i]]==1){
            printf("%d",v[i]);
            return 0;
        }
    }
    printf("None");

}