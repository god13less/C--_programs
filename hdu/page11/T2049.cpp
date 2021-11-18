//
// Created by wang on 2021/4/25.
//

#include <iostream>

using namespace std;

const int MAX = 21;
long long int factorial[MAX];
long long int wrongArrang[MAX];

void f() {
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i < MAX; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

void f2() {
    wrongArrang[2] = 1;
    wrongArrang[3] = 2;
    for (int i = 4; i < MAX; i++) {
        wrongArrang[i] = (wrongArrang[i - 1] + wrongArrang[i - 2]) * (i - 1);
    }
}

int main() {
    f();
    f2();
    int C;
    cin >> C;
    for (int i = 0; i < C; i++) {
        int n, m;
        cin >> n >> m;
        long long int ans = factorial[n] / factorial[m] / factorial[n - m];
        ans *= wrongArrang[m];
        cout << ans << endl;
    }
    return 0;
}
