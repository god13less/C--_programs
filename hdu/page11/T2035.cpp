//
// Created by wang on 2021/1/22.
//

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int a, b, ans;
    long long tem;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            return 0;
        }

        if (a >= 1000) {
            a = a % 1000;
        }
        ans = a;
        for (int i = 0; i < b-1; i++) {
            ans = ans * a;
            if (ans >= 1000) {
                ans=ans%1000;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
