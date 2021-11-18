//
// Created by wang on 2021/4/28.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll n;
ll ans[12];


void trans() {
    int len = 0;
    while (n != 0) {
        if (n % 2 == 0) {
            ans[len++] = 0;
        } else {
            ans[len++] = 1;
        }
        n /= 2;
    }
    while (len--) {
        cout<<ans[len];
    }
    cout<<endl;
}

int main() {
    while (cin >> n) {
        trans();
    }

    return 0;
}
