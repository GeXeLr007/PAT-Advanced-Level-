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


typedef long long LL;

LL num210(string basic_string, int radix, LL inf);

void init();

LL findLowNum(string basic_string);

int binerySerach(string basic_string, LL left, LL right, LL num);

int cmp(string basic_string, LL mid, LL num);

int book[300] = {0};

int main() {
    freopen("infile1.txt", "r", stdin);

    init();
    string N1, N2;
    LL inf = (1L << 63) - 1;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    if (tag == 2) {
        string t = N1;
        N1 = N2;
        N2 = t;
    }
    LL n1num = num210(N1, radix, inf);
    LL low = findLowNum(N2);
    LL high = max(low, n1num) + 1;

    int out = binerySerach(N2, low, high, n1num);
    if (out == -1) {
        cout << "Impossible";
    } else {
        cout << out;
    }


    return 0;
}

int binerySerach(string str, LL left, LL right, LL num) {
    while (left <= right) {
        LL mid = (left + right) / 2;
        int flag = cmp(str, mid, num);
        if (flag > 0) {
            right = mid - 1;
        } else if (flag < 0) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int cmp(string str, LL mid, LL n1num) {
    int n2num = num210(str, mid, n1num);
    if (n2num == n1num) {
        return 0;
    } else if (n2num < 0 || n2num > n1num) {
        return 1;
    } else {
        return -1;
    }

    return 0;
}

LL findLowNum(string str) {
    int max = -1;
    for (int i = 0; i < str.size(); ++i) {
        if (book[str[i]] > max) {
            max = book[str[i]];
        }
    }
    return max;
}

void init() {
    for (int i = '0'; i <= '9'; ++i) {
        book[i] = i - '0';
    }
    for (int i = 'a'; i <= 'z'; ++i) {
        book[i] = i - 'a' + 10;
    }
}

LL num210(string str, int radix, LL inf) {
    LL ret = 0;
    for (int i = 0; i < str.size(); ++i) {
        ret = ret * radix + book[str[i]];
        if (ret < 0 || ret > inf) {
            return -1;
        }
    }
    return ret;
}
