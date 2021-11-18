//
// Created by wang on 2021/10/24.
//
#include <iostream>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;

int t, n, a, b;
int cnt = 0;


int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void save() {
    if ((n / gcd(a, b)) % 2) {
        cout << "Case #" << cnt << ": " << "Yuwgna" << endl;
    } else {
        cout << "Case #" << cnt << ": " << "Iaka" << endl;
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        cnt++;
        save();
    }
    return 0;
}
