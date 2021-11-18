//
// Created by wang on 2021/11/10.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 100000000

using namespace std;
typedef long long ll;


int p, y;
int f(int x){
    for (int i = 2; i <= p && i * i <= y; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    cin >> p >> y;
    bool bo = false;
    if (y % 2 == 0) {
        y--;
    }
    for (int i = y; i > p; i -= 2) {
        if (f(i)) {
            cout << i << endl;
            bo = true;
            break;
        }
    }
    if (!bo) {
        cout << -1 << endl;
    }

    return 0;
}
