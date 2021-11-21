#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
const int N = 1000090;
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

int t, n;
string str;
string arr[] = {"aa", "aba", "aca", "abca", "acba", "abbacca", "accabba"};

void solve()
{
    cin >> t;
    while (t--)
    {
        int ans = -1;
        cin >> n >> str;
        for (int i = 0; i < 7; i++)
        {
            if (str.find(arr[i]) != -1)
            {
                ans = arr[i].size();
                break;
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    solve();
    return 0;
}