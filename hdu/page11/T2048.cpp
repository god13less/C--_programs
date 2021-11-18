//
// Created by wang on 2021/1/24.
//

#include <iostream>
#include <iomanip>

using namespace std;
typedef long long ll;


ll f(ll x) {
    if (x == 1) {
        return 0;
    } else if (x == 2) {
        return 1;
    } else if (x == 3) {
        return 2;
    }
    return (x - 1) * (f(x - 1) + f(x - 2));
}

int main() {
    ll n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double g = 1.0;
        cin >> x;
        for (int j = 1; j <= x; j++) {
            g *= j;
        }
        cout.setf(ios::fixed);
        cout << fixed << setprecision(2) << (f(x) / g) * 100 << '%' << endl;
    }
    return 0;
}
