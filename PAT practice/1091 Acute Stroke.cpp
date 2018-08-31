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

struct Node {
    int x, y, z;
};
int m, n, l, t;
int info[1290][140][70];
bool visit[1290][140][70];

int directionX[] = {1, 0, -1, 0, 0, 0};
int directionY[] = {0, 1, 0, -1, 0, 0};
int directionZ[] = {0, 0, 0, 0, -1, 1};

int cnt = 0;

bool judge(int x, int y, int z) {
    if (x >= m || x < 0 || y >= n || y < 0 || z < 0 || z >= l) {
        return false;
    }
    if (visit[x][y][z] == true || info[x][y][z] == 0) {
        return false;
    }
}

void BFS(Node now) {
    queue<Node> q;
    q.push(now);
    cnt++;
    visit[now.x][now.y][now.z] = true;
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int newX = cur.x + directionX[i];
            int newY = cur.y + directionY[i];
            int newZ = cur.z + directionZ[i];
            if (judge(newX, newY, newZ)) {
                Node newnode;
                newnode.x = newX;
                newnode.y = newY;
                newnode.z = newZ;
                visit[newX][newY][newZ] = true;
                q.push(newnode);
                cnt++;
            }
        }
    }
}

int main() {
    freopen("infile1.txt", "r", stdin);
    cin >> m >> n >> l >> t;
    for (int z = 0; z < l; ++z) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int t;
                scanf("%d", &info[i][j][z]);
            }
        }
    }

    int outnum = 0;
    for (int z = 0; z < l; ++z) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visit[i][j][z] == false && info[i][j][z] == 1) {
                    Node now;
                    now.x = i;
                    now.y = j;
                    now.z = z;
                    cnt = 0;
                    BFS(now);
                    if (cnt >= t) {
                        outnum += cnt;
                    }
                }
            }
        }
    }
    cout << outnum;


    return 0;
}
