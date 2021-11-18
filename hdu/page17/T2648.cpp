//
// Created by wang on 2021/7/6.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;

int main() {
    map<string, ll> rank;
    ll n, m, tem;
    string str;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> str;
            rank[str] = 0;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> tem >> str;
                rank[str] += tem;
            }
            ll ans = 1;
            map<string, ll>::iterator it;
            for (it = rank.begin(); it != rank.end(); it++) {
                if (it->second > rank["memory"]) {
                    ans++;
                }
            }
            cout << ans << endl;
        }
        rank.clear();
    }
    return 0;
}
