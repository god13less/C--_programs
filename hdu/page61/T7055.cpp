//
// Created by wang on 2021/8/11.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn= 1e5 + 10;

vector<ll> pos[26];
vector<ll> len[26];
char str[maxn];

void sove(){
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    for (ll i = 1; i <= n; i++) {
        if (pos[str[i] - 'a'].empty()) {
            pos[str[i] - 'a'].push_back(0);
        }
        pos[str[i]-'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        if (!pos[i].empty()) {
            pos[i].push_back(n + 1);
            len[i].reserve(pos[i].size() - 1);
            for (int j = 0; j < pos[i].size()-1; j++) {
                len[i][j] = pos[i][j + 1] - pos[i][j];
            }
        }
    }
    ll res=0;
    for (int i = 0; i < 26; i++) {
        if (pos[i].empty()) {
            continue;
        }
        ll ans=0,d1=0,d2=0,sum=0,d3;
        for (int j = 1; j <= pos[i].size()-2; j++) {
            if(j==1) {
                d3 = len[i][j - 1];
            } else {
                d3 = (len[i][j - 1] + len[i][j - 2]) % mod;
            }
            d2 = (d2 + d3) % mod;
            d1 = (d1 + d2) % mod;
            sum = (sum + d1) % mod;
            ans = (ans + len[i][j] * sum % mod) % mod;
        }
        res = (res + ans) % mod;
    }
    for (int i = 0; i < 26; i++) {
        pos[i].clear();
    }
    printf("%lld\n", res);
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        sove();
    }
    return 0;
}