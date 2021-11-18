//
// Created by wang on 2021/1/19.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    int m;
    int n[100];
    double ans[100];
    while (cin >> m) {
        for (int i = 0; i < m; i++) {
            cin >> n[i];
        }
        for (int i = 0; i < 100; i++) {
            ans[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n[i]; j++) {
                ans[i] += pow(-1, j + 1) * (1.0 / j);
            }
            cout<<fixed<<setprecision(2)<<ans[i]<<endl;
        }

    }

    return 0;
}