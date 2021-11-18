//
// Created by wang on 2021/2/16.
//

#include <iostream>

using namespace std;

int n, m, t, tem1, tem2;
int arr[10][10];
bool vis[10][10];
const int mx[] = {1, 0, -1, 0}, my[] = {0, 1, 0, -1};

struct pr {
    int x, y, times;

    pr() {}

    pr(int a, int b, int c) {
        x = a;
        y = b;
        times = c;
    }
} ;

pr st, en, tem;

void dfs(pr st) {
    if (st.x == en.x && st.y == en.y) {
        en.times++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        tem = pr(st.x + mx[i], st.y + my[i], st.times + 1);
        if (vis[tem.x][tem.y] == false && arr[tem.x][tem.y] == 0) {
            vis[st.x][st.y]= true;
            dfs(tem);
            vis[st.x][st.y]= false;

        }
    }
}

int main() {
    cin >> n >> m >> t >> st.x >> st.y >> en.x >> en.y;
    for (int i = 0; i < t; i++) {
        cin >> tem1 >> tem2;
        arr[tem1][tem2] = 1;
    }
    for (int i = 0; i < n + 2; i++) {
        arr[i][0] = arr[i][m + 1] = 1;
    }
    for (int i = 0; i < m + 2; i++) {
        arr[0][i] = arr[n + 1][i] = 1;
    }
    st.times = 0;
    en.times = 0;
    dfs(st);
    cout << en.times << endl;
    return 0;
}
