//
// Created by wang on 2021/10/17.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
int t, n, ans;
bool is_prime[10005];
ll prime[10005];
ll cnt = 0;

void EUIer(ll n) {
    for (ll i = 0; i < n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[cnt++] = i;
        }
        for (ll j = 0; j < cnt && i * prime[j] <= n; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

struct node {
    int val, index;

    friend bool operator<(const node &a, const node b) {
        return a.val < b.val;
    }
} arr[250];

int main() {
    cin >> t;
    EUIer(300);
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].val;
            arr[i].index = i;
        }
        sort(arr + 1, arr + 1 + n);
        for (int i = 1; i <= n; i++) {
            arr[i].val += arr[i - 1].val;
        }
        if (!is_prime[arr[n].val]) {
            cout << n << endl;
            for (int i = 1; i <= n; i++) {
                cout << arr[i].index << " ";
            }
            cout << endl;
            continue;
        }
        bool bo = false;
        for (int i = 1 ; i <= n; i++) {
            if (!is_prime[arr[n].val - (arr[i].val - arr[i - 1].val)]) {
                cout << n - 1 << endl;
                for (int j = 1; j <= n; j++) {
                    if (j != i) {
                        cout << arr[j].index << " ";
                    }
                }
                cout << endl;
                bo = true;
                break;
            }
        }
        if (bo) {
            continue;
        }
    }

    return 0;
}
