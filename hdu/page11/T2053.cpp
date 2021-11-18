//
// Created by wang on 2021/4/29.
//

#include <iostream>

using namespace std;
typedef long long ll;


int main() {
    ll n, k;
    while (cin >> n) {
        k=0;
        for (int i = 1; i <= n; i++) {
            if (n%i==0) {
                k++;
            }
        }
        if (k%2==0) {
            cout<<'0'<<endl;
        } else {
            cout<<'1'<<endl;
        }
    }
    return 0;
}
