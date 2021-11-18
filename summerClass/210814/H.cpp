#include <bits\stdc++.h>
#define endl "\n"
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const  ll mod = 998244353;
const   double  PI = acos(-1.0);
const double EI = exp(1.0);
const int maxn = 1e5 + 10;
char a[maxn];
void to3(ll x)
{
    ll i = 1;
    while (x)
    {
        if (x % 3 == 0) a[i] = '2';
        else if (x % 3 == 1) a[i] = '3';
        else if (x % 3 == 2) a[i] = '6';
        x /= 3;
        i++;
    }
}
void solve()
{
    ll n;
    cin >> n;
    ll q = n;
    ll s = 1,l=0;
    while (q>=s)
    {
        l++;
        q -= s;
        s *= 3;
    }
    memset(a, '2', sizeof(a));
    to3(q);
    for (ll i = l; i >= 1; i--)
        cout << a[i];
    cout << endl;

}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //int t;cin >> t;while (t--)
    solve();
    return 0;
}