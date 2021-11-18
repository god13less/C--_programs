//
// Created by wang on 2021/11/17.
//

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 200003

using namespace std;
typedef long long ll;

struct node
{
    int u, v;

    friend bool operator<(const node &a, node &b)
    {
        return a.u == b.u ? a.v < b.v : a.u < b.u;
    }
} edge[maxn];

int n, m;
int dp[maxn], degree[maxn];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
        if (u > v)
        {
            swap(u, v);
        }
        edge[i].u = u;
        edge[i].v = v;
    }
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        dp[edge[i].v] = max(dp[edge[i].v], dp[edge[i].u] + 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, (ll)(dp[i] + 1) * degree[i]);
    }
    cout << ans << endl;
    return 0;
}