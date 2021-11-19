#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
const int N = 500;
inline ll rd()
{
    ll x = 0;
    char c = getchar();
    bool f = 0;
    while (!isdigit(c))
    {
        if (c == '-')
            f = 1;
        c = getchar();
    }
    while (isdigit(c))
    {
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return f ? -x : x;
}

int n, m, x, y;
int visit[N][N], ans[N][N];
int w[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

struct node
{
    int x, y;
};

void bfs(int x, int y)
{
    visit[x][y] = 1;
    ans[x][y] = 0;
    queue<node> que;
    node tem1;
    tem1.x = x;
    tem1.y = y;
    que.push(tem1);
    while (!que.empty())
    {
        node tem2 = que.front();
        que.pop();
        for (int i = 0; i < 8; i++)
        {
            int dx = tem2.x + w[i][0];
            int dy = tem2.y + w[i][1];
            if (dx <= 0 || dy <= 0 || dx > n || dy > m)
                continue;
            if (!visit[dx][dy])
            {
                visit[dx][dy] = 1;
                tem1.x = dx;
                tem1.y = dy;
                que.push(tem1);
                ans[dx][dy] = ans[tem2.x][tem2.y] + 1;
            }
        }
    }
}

void save()
{
    memset(visit, 0, sizeof(visit));
    memset(ans, -1, sizeof(ans));
    int step = 0;
    bfs(x, y);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << setiosflags(ios::left) << setw(5) << setfill(' ') << ans[i][j];
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m >> x >> y;
    save();
    return 0;
}