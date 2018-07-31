#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
//#include <cstring>
using namespace std;

int main() {
    freopen("infile1.txt", "r", stdin);
    string s;
    cin >> s;

//    这个题没想出来
    string danwei[] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
    string shu[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    int left = 0, right = s.size() - 1;
    if (s[left] == '-') {
        cout << "Fu";
        left++;
    }
    while (left + 4 <= right) {
        right -= 4;
    }
    while (left < s.size()) {
        bool flag = false, isPrint = false;
        while (left <= right) {
//            这里处理了输入是0的特殊情况
            if (left > 0 && s[left] == '0') {
                flag = true;
            } else {
                if (flag) {
                    printf(" ling");
                    flag = false;
                }
                if (left > 0) {
                    printf(" ");
                }
                printf("%s", shu[s[left] - '0'].c_str());
                isPrint = true;
                if (left != right) {
                    printf(" %s", danwei[right - left - 1].c_str());
                }
            }
            left++;
        }
        if (isPrint && right != s.size() - 1) {
            printf(" %s", danwei[(s.size() - 1 - right) / 4 + 2].c_str());
        }
        right += 4;
    }


    return 0;
}


