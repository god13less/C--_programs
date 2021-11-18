//
// Created by wang on 2021/1/30.
//

#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main() {
    map<ll, ll> m;
    ll n, times;
    ll tem1, tem2, x;
    while (cin >> n >> times) {
        tem1 = -1;
        tem2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> tem2;
            if (tem2 > tem1) {
                m[tem2] = i + 1;
            }
            tem1 = tem2;
        }
        for (int i = 0; i < times; i++) {
            cin >> x;
            if (i != times - 1) {
                if (m[x]) {
                    cout << m[x] << ' ';
                } else {
                    cout << -1 << ' ';
                }
            } else {
                if (m[x]) {
                    cout << m[x] << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}
