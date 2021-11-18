//
// Created by wang on 2021/7/13.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;

int arr[25][25],vis[25][25];
int ans;
int n,m;
int fx[4]={0,0,1,-1},fy[4]={1,-1,0,0};

void dfs(int x,int y){
    ans++;
    vis[x][y]=1;
    for (int i = 0; i <4 ; i++) {
        int nx = x + fx[i];
        int ny = y + fy[i];
        if (!vis[nx][ny] && arr[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main(){
    char c;
    while (cin >> m >> n ) {
        if (n == 0 && m == 0) {
            break;
        }
        memset(arr, 0, sizeof(arr));
        memset(vis, 0, sizeof(vis));
        int x,y;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c;
                if (c == '.') {
                    arr[i][j] = 1;
                } else if (c == '@') {
                    arr[i][j] = 1;
                    x = i;
                    y = j;
                }
            }
        }
        ans = 0;
        dfs(x, y);
        cout << ans << endl;
    }
    return 0;
}