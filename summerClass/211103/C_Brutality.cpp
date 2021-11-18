#include<bits/stdc++.h>

using namespace std;
int a[200010];
string s;
vector<int> vec[200010];
int tot;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    cin >> s;
    s = '#' + s;//注意一定要和第一个字母类型不同
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            ++tot;
            vec[tot].push_back(a[i]);
        } else {
            vec[tot].push_back(a[i]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= tot; i++) {
        sort(vec[i].begin(), vec[i].end());
        int tmpk = k;
        for (int j = vec[i].size() - 1; j >= 0 && tmpk > 0; j--, tmpk--) {
            ans += vec[i][j];
        }
    }
    printf("%lld\n", ans);
}