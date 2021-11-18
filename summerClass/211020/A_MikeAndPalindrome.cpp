//
// Created by wang on 2021/10/20.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
string str;

int main() {
    cin >> str;
    int cnt=0;
    int len_2 = (str.length() - 1) / 2;
    int len = str.length();
    for (int i = 0; i <= len_2; i++) {
        if (str[i] != str[len - 1 - i]) {
            cnt++;
        }
    }
    if (cnt == 0) {
        if (len % 2 == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (cnt == 1) {
        cout << "YES" << endl;
    } else {
        cout<<"NO"<<endl;
    }

    return 0;
}
