//
// Created by wang on 2021/2/6.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int arr[55][55];
bool visit[55][55][5];
char direction;
const int Mn[] = {-1, 0, 1, 0}, Mm[] = {0, 1, 0, -1};

int mod(int a) {
    return (a + 4) % 4;
}

struct pr {
    int x;
    int y;
    int dir;//0 北，1 东，2 南，3 西
    int step;

    pr() {}

    pr(int u, int v, int di, int ste) {
        x = u;
        y = v;
        dir = di;
        step = ste;
    }
};

pr b;
pr e;

void input() {
    cin >> n >> m;
    memset(arr, 0, sizeof arr);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                arr[i - 1][j - 1] = arr[i][j - 1] = arr[i - 1][j] = 1;
            }
        }
    }
    for (int i = 0; i <= m; i++) {
        arr[n][i] = 1;
        arr[0][i] = 1;
    }
    for (int i = 0; i <= n; i++) {
        arr[i][m] = 1;
        arr[i][0] = 1;
    }
    cin >> b.x >> b.y >> e.x >> e.y >> direction;
    switch (direction) {
        case 'N':
            b.dir = 0;
            break;
        case 'E':
            b.dir = 1;
            break;
        case 'S':
            b.dir = 2;
            break;
        case 'W':
            b.dir = 3;
            break;
    }
}

void bfs() {
    queue<pr> q;
    bool flag = false;
    b.step = 0;
    q.push(b);
    visit[b.x][b.y][b.dir] = true;
    while (!q.empty()) {
        pr t = q.front();
        q.pop();
        if (t.x == e.x && t.y == e.y) {
            cout << t.step << endl;
            flag = true;
            break;
        }
        for (int i = 1; i <= 3; i++) {
            int u, v;
            u = t.x + i * Mn[mod(t.dir)];
            v = t.y + i * Mm[mod(t.dir)];
            if (u <= 0 || u >= n || v <= 0 || v >= m || arr[u][v] == 1) {
                break;
            }
            if (visit[u][v][t.dir]) {
                continue;
            }
            visit[u][v][t.dir] = true;
            q.push(pr(u, v, t.dir, t.step + 1));
        }
        if (!visit[t.x][t.y][mod(t.dir + 1)]) {
            visit[t.x][t.y][mod(t.dir + 1)] = true;
            q.push(pr(t.x, t.y, mod(t.dir + 1), t.step + 1));
        }
        if (!visit[t.x][t.y][mod(t.dir - 1)]) {
            visit[t.x][t.y][mod(t.dir - 1)] = true;
            q.push(pr(t.x, t.y, mod(t.dir - 1), t.step + 1));
        }

    }
    if (!flag) {
        cout << -1 << endl;
    }
}

int main() {
    input();
    bfs();
    return 0;
}
