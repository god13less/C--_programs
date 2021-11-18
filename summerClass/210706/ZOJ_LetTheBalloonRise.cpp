//
// Created by wang on 2021/7/6.
//

#include <iostream>
#include <map>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
map<string,ll> ma;

int main() {
    ll n;
    string str;
    while (cin >> n && n > 0) {
        for (int i = 0; i < n; i++) {
            cin>>str;
            if (ma.count(str)) {
                ma[str]++;
            } else {
                ma[str]=1;
            }
        }
        map<string, ll>::iterator it;
        ll maxn=0;
        for (it = ma.begin(); it != ma.end(); it++) {
            if (it->second > maxn) {
                maxn=it->second;
            }
        }
        for (it = ma.begin(); it != ma.end(); it++) {
            if (it->second == maxn) {
                cout<<it->first<<endl;
                break;
            }
        }
        ma.clear();
    }

    return 0;
}
