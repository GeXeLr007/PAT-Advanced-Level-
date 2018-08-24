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


const int MAXN = 2010;
int G[MAXN][MAXN] = {0};
int weight[MAXN] = {0};
map<string, int> stringToint;
map<int, string> intTostring;
int numPerson = 0;
bool vis[MAXN] = {false};
map<string, int> Gang;
int n, k;

int change(string &s) {
    if (stringToint.find(s) != stringToint.end()) {
        return stringToint[s];
    } else {
        stringToint[s] = numPerson;
        intTostring[numPerson] = s;
        return numPerson++;
    }
}

void dfs(int nowVisit, int &head, int &numMember, int &totalValue) {
    vis[nowVisit] = true;
    numMember++;
    if (weight[nowVisit] > weight[head]) {
        head = nowVisit;
    }
    for (int i = 0; i < numPerson; ++i) {
        if (G[nowVisit][i] > 0) {
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = 0;
            G[i][nowVisit] = 0;
            if (vis[i] == false) {
                dfs(i, head, numMember, totalValue);
            }
        }
    }

}

void dfstrace() {
    for (int i = 0; i < numPerson; ++i) {
        if (vis[i] == false) {
            int head = i, numMember = 0, totalValue = 0;
            dfs(i, head, numMember, totalValue);
            if (numMember > 2 && totalValue > k) {
                Gang[intTostring[head]] = numMember;
            }
        }
    }
}


int main() {
    freopen("infile1.txt", "r", stdin);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        int w;
        cin >> s1 >> s2 >> w;
        int id1 = change(s1), id2 = change(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }

    dfstrace();
    cout << Gang.size() << endl;
    for (auto it = Gang.begin(); it != Gang.end(); it++) {
        printf("%s %d\n", it->first.c_str(), it->second);
    }

    return 0;
}
