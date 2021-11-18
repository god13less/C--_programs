//
// Created by wang on 2021/2/3.
//

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

int pi[1000010];
char W[1000010], T[1000010];

void prefix_function(char T[]) {
    memset(pi, 0, sizeof pi);
    for (int i = 1; i < strlen(T); i++) {
        int p = pi[i - 1];
        while (p > 0 && T[i] != T[p]) {
            p = pi[p - 1];
        }
        if (T[i] == T[p]) {
            p++;
        }
        pi[i] = p;
    }
}

int kmp(char W[], char T[]) {
    int k = 0, p = 0;
    ll Tlen = strlen(T);
    ll Wlen = strlen(W);
    for (int i = 0; i < Wlen; i++) {
        while (p > 0 && W[i] != T[p]) {
            p = pi[p - 1];
        }
        if (W[i] == T[p]) {
            p++;
        }
        if (p == Tlen) {
            k++;
        }
    }
    return k;
}

int main() {
    ll n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> T >> W;
            prefix_function(T);
            cout << kmp(W, T) << endl;
        }
    }
    return 0;
}
