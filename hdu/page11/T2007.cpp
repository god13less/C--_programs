//
// Created by wang on 2021/1/17.
//

#include <iostream>

using namespace std;

int main() {
    int m, n;
    long x, y;
    while (cin >> m >> n) {
        if (m > n) {
            swap(m, n);
        }

        if (m % 2 == 1) {
            x = (m + 1) * (m + 1);
            y = m * m * m;
        } else {
            x = m * m;
            y = (m + 1) * (m + 1) * (m + 1);
        }
        for (int i = m + 2; i <= n; i++) {
            if (i % 2 == 1) {
                y += i * i * i;
            } else {
                x += i * i;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
