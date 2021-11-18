//
// Created by wang on 2021/7/12.
// 30 - 40 行不理解唉 unfinished

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
ll primes[10000];
ll que[maxn];

ll solve(int a, int b) {
    int i, j, cnt = 0;
    for (i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            primes[cnt++] = i;
            while (a % i == 0) {
                a /= i;
            }
        }
    }
    if (a > 1) {
        primes[cnt++] = a;
    }
    ll front = 0, sum = 0, uu;
    que[front++] = -1;
    for (i = 0; i < cnt; i++) {
        uu = front;
        for (j = 0; j < uu; j++) {
            que[front++] = que[j] * primes[i] * (-1);
        }
    }
    for (i = 1; i < front; i++) {
        sum += b / que[i];
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    ll a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a > b) {
            ll tem = a;
            a = b;
            b = tem;
        }
        ll sum = b;
        for (int i = 2; i <= a; i++) {
            sum += b - solve(i, b);
        }
        cout << sum << endl;
    }

    return 0;
}
