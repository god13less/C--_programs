//
// Created by wang on 2021/7/16.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
const ll maxn=100000+10;
ll pre[maxn];
int flag=0;

void init(){
    for (int i = 0; i <=maxn; i++) {
        pre[i]=i;
    }
}

ll Find(ll x){
    if(x!=pre[x]){
        pre[x] = Find(pre[x]);
    }
    return pre[x];
}

void Union(ll x,ll y){
    ll fx = Find(x);
    ll fy = Find(y);
    if (fx != fy) {
        pre[fy]=fx;
    } else if (fx == fy){
        flag=1;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll a,b;
    init();
    flag=0;
    set<ll> se;
    set<ll>::iterator it;
    while (cin >> a >> b && a != -1 && b != -1) {
        if (a == 0 && b == 0) {
            ll sum=0;
            for (it = se.begin(); it != se.end(); it++) {
                if (*it == pre[*it]) {
                    sum++;
                }
            }
            if (flag || sum > 1) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
            init();
            flag=0;
            se.clear();
        } else {
            Union(a, b);
            se.insert(a);
            se.insert(b);
        }
    }

    return 0;
}