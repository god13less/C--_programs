//
// Created by wang on 2021/11/4.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
int t, n;
int arr[maxn];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        sort(arr + 1, arr + 1 + n);
        if (n == 1) {
            cout << arr[1] << endl;
            continue;
        }
        int mn;
        if (arr[1] < 0) {
            for (int i = 2; i <= n; i++) {
                arr[i] += -arr[1];
            }
            mn = arr[2];
            for (int i=3; i <= n; i++) {
                if ((arr[i] - arr[i - 1]) > mn) {
                    mn = arr[i] - arr[i - 1];
                }
            }
        } else {
            mn = arr[1];
            for (int i=2; i <= n; i++) {
                if ((arr[i] - arr[i - 1]) > mn) {
                    mn = arr[i] - arr[i - 1];
                }
            }
        }

        cout << mn << endl;
    }
    return 0;
}
