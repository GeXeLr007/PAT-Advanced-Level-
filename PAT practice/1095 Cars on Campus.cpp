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

struct Record {
    char id[10];
    long long t;
    char state[5];
};

//将时间转换为long更容易处理
long long timeToLong(int h, int m, int s) {
    return 3600 * h + m * 60 + s;
};


bool cmpByIdAndTime(const Record &r1, const Record &r2) {
    if (strcmp(r1.id, r2.id)) {
        return strcmp(r1.id, r2.id) > 0;
    } else {
        return r1.t < r2.t;
    }
}

bool cmpByTime(const Record &r1, const Record &r2) {
    return r1.t < r2.t;
}

int main() {
    freopen("infile1.txt", "r", stdin);

    int n, k;
    cin >> n >> k;
    vector<Record> vrec(n);
    for (int i = 0; i < n; ++i) {
        int h, m, s;
        scanf("%s %d:%d:%d %s", vrec[i].id, &h, &m, &s, vrec[i].state);
        vrec[i].t = timeToLong(h, m, s);
    }
    vector<Record> validRec;
//按照id、时间排序先对同一id的记录进行处理
    sort(vrec.begin(), vrec.end(), cmpByIdAndTime);
    int maxTime = -1;
    map<string, int> mapp;
    for (int i = 0; i < n; ++i) {
//        巧妙判断出那些记录是有效的
        if (i + 1 != n && !strcmp(vrec[i].id, vrec[i + 1].id) && !strcmp(vrec[i].state, "in") &&
            !strcmp(vrec[i + 1].state, "out")) {
            if (mapp.count(vrec[i].id) == 0) {
                mapp[vrec[i].id] = 0;
            }
            mapp[vrec[i].id] += (vrec[i + 1].t - vrec[i].t);
            maxTime = max(maxTime, mapp[vrec[i].id]);
            validRec.push_back(vrec[i]);
            validRec.push_back(vrec[i + 1]);
        }
    }

//    进行下一步的时候需要按照时间排序
    sort(validRec.begin(), validRec.end(), cmpByTime);
    int index = 0;
    int carNum = 0;
    for (int i = 0; i < k; ++i) {
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        long long time = timeToLong(h, m, s);
        while (index < validRec.size() && time >= validRec[index].t) {
            if (!strcmp(validRec[index].state, "in")) {
                carNum++;
            } else {
                carNum--;
            }
            index++;
        }
        printf("%d\n", carNum);
    }


    for (auto it = mapp.begin(); it != mapp.end(); it++) {
        if (it->second == maxTime) {
            printf("%s", it->first.c_str());
            printf(" ");
        }
    }

    printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 3600 % 60);


}