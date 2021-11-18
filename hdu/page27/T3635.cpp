//
// Created by wang on 2021/7/7.
// don't understand

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
int mov[10500];     //i龙珠所运输的次数
int F[10500];     // i号龙珠子的父节点
int num[10500];   // i个城市中龙珠的数量
int n;
int find(int a)
{
    if (F[a] == a)
        return a;
    int t = F[a];
    F[a] = find(F[a]);
    mov[a] += mov[t];
    return F[a];
}
void insert(int a, int b)
{
    int t1 = find(a);
    int t2 = find(b);
    if (t1 == t2)
        return;
    F[t1] = t2;
    num[t2] += num[t1];
    num[t1] = 0;
    mov[t1]++;

}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        F[i] = i;
        mov[i] = 0;
        num[i] = 1;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
    {
        int  m;
        cin >> n >> m;
        init();
        cout << "Case " << q << ":" << endl;
        for (int i = 1; i <= m; i++)
        {
            string a;
            cin >> a;
            if (a == "T")
            {
                int x, y;
                cin >> x >> y;
                insert(x, y);
            }
            else if(a=="Q")
            {
                int x;
                cin >> x;
                int y = find(x);
                cout << y << " " << num[y] << " " << mov[x]<<endl;
            }
        }
    }
    return 0;
}