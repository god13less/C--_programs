//
// Created by wang on 2021/11/12.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
int t;
string str;
map<char, int> mp;

int main() {
    cin >> t;
    while (t--) {
        mp.clear();
        cin >> str;
        for (int i = 1; i <= str.length(); i++) {
            mp[str[i - 1]] = i;
        }
        cin >> str;
        str = str + str[str.length() - 1];
        int ans = 0;
        for (int i = 0; i < str.length()-1; i++) {
            ans += abs(mp[str[i]] - mp[str[i + 1]]);
        }
        cout << ans << endl;
    }
    return 0;
}
