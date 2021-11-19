#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
const int N = 1050;
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

int t, m;
string str;

void solve()
{
    int n;
    cin >> n;
    char c[n + 1];
    cin >> c;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (count(c, c + i, '1') == 0)
            continue;
        if (count(c, c + i, '1') == count(c + i, c + n, '0'))
        {
            cout << 1 << '\n'
                 << 2 * count(c, c + i, '1') << " ";
            for (int j = 0; j < i; j++)
                if (c[j] == '1')
                    cout << j + 1 << " ";
            for (int j = i; j < n; j++)
                if (c[j] == '0')
                    cout << j + 1 << " ";
            cout << '\n';
            return;
        }
    }
    cout << 0 << '\n';
}

int main()
{
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}