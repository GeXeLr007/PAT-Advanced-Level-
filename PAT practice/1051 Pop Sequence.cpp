#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int main() {

//    freopen("infile1.txt", "r", stdin);

    stack<int> stack1;
    int arr[1010] = {0};
    int m, n, k;
    cin >> m >> n >> k;
    while (k--) {
        bool isyes = true;
//        先把上一次循环遗留的栈清空
        while (!stack1.empty()) {
            stack1.pop();
        }

//        把出栈序列读入到数组中
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int cur = 0;
        for (int j = 1; j <= n; ++j) {
            stack1.push(j);
//            先在push之后检查元素个数是否大于栈的最大容量
            if (stack1.size() > m) {
                isyes = false;
                break;
            }
//            如果栈顶元素和数组cur元素相等，则一直pop并数组下标cur加一。pop之前要判断栈非空，才能进行pop
            while (!stack1.empty() && arr[cur] == stack1.top()) {
                stack1.pop();
                cur++;
            }
        }
//        如果循环操作之后栈中还残留有元素，则是因为出栈序列错误
        if (stack1.empty() && isyes) {
            printf("YES\n");
        } else {
            printf("NO\n");

        }
    }


    return 0;
}