//
// Created by wang on 2021/1/22.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    int x[100], y[100];
    double S;
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        S = 0;
        x[n] = x[0];
        y[n] = y[0];
        for (int i = 0; i < n; i++) {
            S += (x[i] * y[i + 1] - x[i + 1] * y[i]) / 2.0;
        }

        cout << fixed << setprecision(1) << S << endl;
    }

    return 0;
}
