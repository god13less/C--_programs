//
// Created by wang on 2021/7/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 1 << 30;

stack<char> stk;

int main() {
    char c;
    ll n;
    cin >> n;
    getchar();
    while (n--) {
        while (true) {
            c=getchar();
            if (c == ' ' || c == '\n' || c == EOF) {
                while (!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
                if (c == '\n' || c == EOF) {
                    break;
                }
                cout<<c;
            } else {
                stk.push(c);
            }
        }
        cout<<endl;
    }

    return 0;
}
