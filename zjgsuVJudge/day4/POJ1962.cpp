//
// Created by wang on 2021/2/5.
//

#include <iostream>

#define maxn 20020

using namespace std;
typedef long long ll;

ll pre[maxn], val[maxn];

void init() {
    for (int i = 0; i <= maxn; i++) {
        pre[i] = i;
        val[i] = 0;
    }
}

ll Find(ll x) {
    if (x == pre[x]) {
        return x;
    }
    ll f = Find(pre[x]);
    val[x] += val[pre[x]];
    pre[x]=f;
    return f;
}


int main() {
    ll T, n, I, J;
    char ch;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        init();
        while (cin >> ch) {
            if (ch == 'O') {
                break;
            } else if (ch == 'E') {
                cin >> I;
                Find(I);
                cout << val[I] << endl;
            } else {
                cin >> I >> J;
                pre[I] = J;
                val[I] = abs(I - J) % 1000;
            }
        }
    }

    return 0;
}
