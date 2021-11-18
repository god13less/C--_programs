#include <bits\stdc++.h>
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
int w[8][2] = {{}};

void dfs(int x, int y)
{
}

void save()
{
    memset(visit, 0, sizeof(visit));
    memset(ans, 0, sizeof(ans));
}

int main()
{
    cin >> n >> m >> x >> y;
    save();
    return 0;
}