//
// Created by wang on 2021/11/11.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
int x, y, t;

ll save(){
    ll ans = y - (y % x)/2;
    return ans;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x > y) {
            cout << x + y << endl;
        } else if (x == y) {
            cout << x << endl;
        } else if (x < y) {
            cout << save() << endl;
        }
    }
    return 0;
}
