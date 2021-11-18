//
// Created by wang on 2021/7/5.
// Codeforces 681 div2

#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
ll t, a, b;
string str;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> str;
        ll f0 = 0, cnt0 = 0, res = 0;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '1') {
                f0 = 1;
            }
            if (str[j] == '0' && f0) {
                cnt0++;
            } else if (cnt0 > 0) {
                res += cnt0 * b < a ? cnt0 * b : a;
                cnt0=0;
            }
        }
        cout<<res+(f0?a:0)<<endl;
    }
    return 0;
}