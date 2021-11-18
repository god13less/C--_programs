//
// Created by wang on 2021/11/11.
//
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    if (a < b) swap(a, b);
    return a % b == 0 ? b : gcd(b, a % b);
}

bool PD(int temp, int i, bool ans) {
    if (ans == 0) return 0;
    for (int j = 2; j <= min(26, i + 1); j++) {
        if (temp % j != 0) return 1;
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int f = 1; f <= T; f++) {
        int n;
        cin >> n;
        bool ans = 1;
        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            ans = PD(temp, i, ans);
        }
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
