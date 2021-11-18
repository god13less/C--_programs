//
// Created by wang on 2021/7/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 1 << 30;

int main(){
    ll n;
    cin >> n;
    while (n--) {
        ll x;
        cin>>x;
        list<ll> mylist;
        list<ll>::iterator it;
        for (int i = 1; i <= x; i++) {
            mylist.push_back(i);
        }
        ll k=2;
        while (mylist.size() > 3) {
            ll num=1;
            for (it = mylist.begin(); it != mylist.end();) {
                if (num++ % k == 0) {
                    it = mylist.erase(it);
                } else {
                    it++;
                }
            }
            k==2?k=3:k=2;
        }
        for (it = mylist.begin(); it != mylist.end();it++) {
            if (it != mylist.begin()) {
                cout << ' ';
            }
            cout<<*it;
        }
        cout<<endl;
    }

    return 0;
}
