//
// Created by wang on 2021/1/30.
//

#include <iostream>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ll n,a,b,c;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin>>a>>b;
            for (int j = b; j <=a ; j++) {
                if (b==gcd(a,j)&&b!=j) {
                    c=j;
                    break;
                }
            }

            cout << c << endl;
        }
    }
    return 0;
}
