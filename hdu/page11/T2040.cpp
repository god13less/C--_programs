//
// Created by wang on 2021/1/22.
//

#include <iostream>

using namespace std;

int main() {
    int n, a, b, tem;
    bool bo1, bo2;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            bo1 = false;
            bo2 = false;

            tem = 0;
            for (int i = 1; i <= a/2; i++) {
                if (a % i == 0) {
                    tem += i;
                }
            }
            if (tem == b) {
                bo1 = true;
            }
            tem = 0;
            for (int i = 1; i <= b/2; i++) {
                if (b % i == 0) {
                    tem += i;
                }
            }
            if (tem == a) {
                bo2 = true;
            }

            if (bo1 && bo2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
