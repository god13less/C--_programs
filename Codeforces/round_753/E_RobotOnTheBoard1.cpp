//
// Created by wang on 2021/11/7.
//

#include<bits/stdc++.h>

using namespace std;
int t, n, m;
int L, R, U, D, x, y, a, b;
string s;

int main(void) {
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        a = b = L = D = x = y = 1;
        R = m;
        U = n;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') y++;
            if (s[i] == 'R') y--;
            if (s[i] == 'D') --x;
            if (s[i] == 'U') ++x;
            L = max(L, y);
            D = max(D, x);
            R = min(R, y + m - 1);
            U = min(U, x + n - 1);
            if (L <= R && D <= U) a = D, b = L;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
