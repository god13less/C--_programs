//
// Created by wang on 2021/9/28.
//cf#744(Div3)
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
map<char, int> ma;
string str;

int main() {
    int n;
    cin >> n;
    while (n--) {
        ma.clear();
        cin >>str;
        for (int i = 0; i < str.length(); i++) {
            if (!ma.count(str[i])) {
                ma[str[i]] = 1;
            } else {
                ma[str[i]]++;
            }
        }
        if (ma['A'] + ma['C'] == ma['B']) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
