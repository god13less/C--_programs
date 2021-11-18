//
// Created by wang on 2021/7/5.
// Codeforces 681 div2

#include <iostream>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
ll n, x;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ll con=0;
        for (int j = 2*x; j <4*x; j+=2) {
            cout << j << ' ';
            con++;
            if (con == x) {
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}