#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

struct stu {
    string name;
    char gender;
    string id;
    int score;
};

int main() {
    freopen("infile1.txt", "r", stdin);

    int n;
    cin >> n;
    vector<stu> vf, vm;

    for (int i = 0; i < n; ++i) {
        stu s;
        cin >> s.name >> s.gender >> s.id >> s.score;
        if (s.gender == 'F')
            vf.push_back(s);
        else
            vm.push_back(s);
    }
    bool isless = false;
    int maxi = 0;
    if (vf.size() != 0) {

        for (int i = 0; i < vf.size(); ++i) {
            if (vf[i].score > vf[maxi].score)
                maxi = i;
        }
        cout << vf[maxi].name << " " << vf[maxi].id << endl;
    } else {
        isless = true;
        cout << "Absent" << endl;
    }
    int mini = 0;
    if (vm.size() != 0) {

        for (int i = 0; i < vm.size(); ++i) {
            if (vm[mini].score > vm[i].score)
                mini = i;
        }
        cout << vm[mini].name << " " << vm[mini].id << endl;
    } else {
        isless = true;
        cout << "Absent" << endl;
    }
    if (!isless) {
        cout << vf[maxi].score - vm[mini].score;
    } else {
        cout << "NA";
    }


    return 0;
}

