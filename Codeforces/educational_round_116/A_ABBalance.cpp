//
// Created by wang on 2021/11/12.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
int t, AB, BA;
string str;

void save() {
    AB = 0;
    BA = 0;
    if (str.length() == 1) {
        cout << str << endl;
        return;
    }
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == 'a' && str[i + 1] == 'b') {
            AB++;
        }
        if (str[i] == 'b' && str[i + 1] == 'a') {
            BA++;
        }
    }
    if (AB == BA) cout << str << endl;
    else {
        if (str[0] == 'a') {
            str[0] = 'b';
        } else {
            str[0] = 'a';
        }
        cout << str << endl;
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> str;
        save();
    }
    return 0;
}
