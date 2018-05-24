#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main() {

//    freopen("infile1.txt", "r", stdin);

//    这个题好坑。。。跑不出样例正确结果的代码才是正确的代码，直接保留两位小数即可，不需要+0.005
    double product = 1;
    for (int i = 0; i < 3; ++i) {
        double a, b, c;
        cin >> a >> b >> c;
        double maxnum = max(max(a, b), c);
        if (maxnum == a) {
            printf("W ");
        } else if (maxnum == b) {
            printf("T ");
        } else {
            printf("L ");
        }
        product *= maxnum;
    }
    double out = (product * 0.65 - 1) * 2;

    printf("%.2lf", out);


    return 0;
}