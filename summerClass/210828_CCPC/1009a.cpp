#include <bits/stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
bool vis[maxn][maxn];

void solve() {
    string a;
    int n;
    cin >> n;
    cin >> a;
    memset(vis, 0, sizeof(vis));
    vis[0][0] = true;
    int len = a.size();
    int x = 0, y = 0;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] == 'U')
            y++;
        else if (a[i] == 'D')
            y--;
        else if (a[i] == 'R')
            x++;
        else if (a[i] == 'L')
            x--;
        if (vis[x][y])
            ans++;
        else
            vis[x][y] = true;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
