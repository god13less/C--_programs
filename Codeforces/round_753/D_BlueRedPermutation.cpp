//
// Created by wang on 2021/11/4.
//

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 300000

using namespace std;
typedef long long ll;

int t, n;
int arr[maxn];
int a1[maxn], a2[maxn];
int cnt1, cnt2;
string str_arr;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> str_arr;
        cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < n; i++) {
            if (str_arr[i] == 'B') {
                a1[++cnt1] = arr[i];
            } else {
                a2[++cnt2] = arr[i];
            }
        }
        sort(a1 + 1, a1 + cnt1 + 1);
        sort(a2 + 1, a2 + cnt2 + 1);
        int flag = 0;
        for (int i = 1; i <= cnt1; i++) {
            if (a1[i] < i) {
                flag = 1;
            }
        }
        for (int i = 1; i <= cnt2; i++) {
            if (a2[i] > i + cnt1) {
                flag = 1;
            }
        }
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}