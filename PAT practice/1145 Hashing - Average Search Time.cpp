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
#include <set>

using namespace std;

bool isprime(int size) {
    for (int i = 2; i <= sqrt(size); ++i) {
        if (size % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    freopen("infile1.txt", "r", stdin);

    int size, n, m;
    cin >> size >> n >> m;
    while (!isprime(size)) {
        size++;
    }
    int hash[size] = {0};
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        bool hasInsert = false;
        for (int j = 0; j <= size; ++j) {
            int index = (t + j * j) % size;
            if (hash[index] == 0) {
                hash[index] = t;
                hasInsert = true;
                break;
            }
        }
        if (hasInsert == false) {
            printf("%d cannot be inserted.\n", t);
        }
    }

    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        for (int j = 0; j <= size; ++j) {
            sum++;
            int index = (t + j * j) % size;
            if (t == hash[index] || hash[index] == 0) {
                break;
            }
        }
    }
    printf("%.1f", sum * 1.0 / m);


    return 0;
}
