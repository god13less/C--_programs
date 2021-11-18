//
// Created by wang on 2021/7/6.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;

set<string> setall, setloss;

int main() {
    ll n;
    string str1, str2;
    while (cin >> n && n > 0) {
        for (int i = 0; i < n; i++) {
            cin >> str1 >> str2;
            setall.insert(str1);
            setall.insert(str2);
            setloss.insert(str2);
        }
        if (setall.size() - setloss.size() == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        setall.clear();
        setloss.clear();
    }

    return 0;
}
