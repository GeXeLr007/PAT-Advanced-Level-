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
#include <queue>

using namespace std;


vector<int> fac, temp, ans;
int n, k, p;
int maxSumFac = -1;

void dfs(int index, int nowK, int sum, int sumfac) {
    if (index >= 1) {
        if (sum == n && nowK == k) {
            if (sumfac > maxSumFac) {
                maxSumFac = sumfac;
                ans = temp;
            }
            return;
        }
        if (sum > n || nowK > k) {
            return;
        }
        temp.push_back(index);
        dfs(index, nowK + 1, sum + fac[index], sumfac + index);
        temp.pop_back();
        dfs(index - 1, nowK, sum, sumfac);
    }
}


int main() {
    freopen("infile1.txt", "r", stdin);

    cin >> n >> k >> p;
    int temp = 0, i = 0;
    while (temp <= n) {
        fac.push_back(temp);
        temp = pow(++i, p);
    }
    dfs(fac.size() - 1, 0, 0, 0);
    if(maxSumFac!=-1){
        printf("%d = %d^%d",n,ans[0],p);
        for (int i = 1; i < ans.size(); ++i) {
            printf(" + %d^%d", ans[i], p);
        }
    }else{
        printf("Impossible");
    }

    return 0;
}
