//
// Created by wang on 2021/7/8.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;

ll n;
ll treearray[5007];
ll arr[5007];

ll lowbit(ll x) {
    return x & (-x);
}

void update(ll index, ll value) {
    while (index <= n) {
        treearray[index] += value;
        index += lowbit(index);
    }
}

ll getsum(ll index) {
    ll ans = 0;
    while (index > 0) {
        ans += treearray[index];
        index -= lowbit(index);
    }
    return ans;
}

int main() {
    while(cin >> n) {
        ll sum = 0;
        memset(treearray, 0, sizeof(treearray));
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i]++;
            update(arr[i], 1);
            sum += i - getsum(arr[i]);
        }
        ll minimum = sum;
        for (int i = 1; i < n; i++) {
            sum += (n - arr[i]) - (arr[i] - 1);
            if (minimum > sum) {
                minimum = sum;
            }
        }
        cout << minimum << endl;
    }

    return 0;
}
