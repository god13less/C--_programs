//
// Created by wang on 2021/9/28.
//cf#744(Div3)
//wrong

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 100

using namespace std;
typedef long long ll;
struct node {
    int l, r, n;
} t[100000];

int arr[maxn];
int n, m, cnt;
int flag = 0;

int main() {
    cin >> n;
    while (n--) {
        cnt = 0;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> arr[i];
        }
        int k = m;
        while (k) {
            flag=0;
            int l = 0;
            for (int i = 1; i < k; i++) {
                if (arr[i] > arr[k]) {
                    l = i;
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                cnt++;
                int tem;
                int i;
                for (i = l; i <= k; i++) {
                    int qwe=max(arr + l , arr + k ) - arr;
                    if (arr[i] == qwe) {
                        t[cnt].n = i - l + 1;
                        break;
                    }
                }
                t[cnt].r = k;
                t[cnt].l = l;
                for (int as = 1; as <= cnt; as++) {
                    tem = arr[l];
                    for (int j = l; j < k; j++) {
                        arr[j] = arr[j + 1];
                    }
                    arr[k] = tem;
                }
            }
            k--;
        }
        cout << cnt << endl;
        for (int i = 1; i <= cnt; i++) {
            cout << t[i].l << ' ' << t[i].r << ' ' << t[i].n << endl;
        }
    }
    return 0;
}

