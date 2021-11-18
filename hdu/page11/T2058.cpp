//
// Created by wang on 2021/5/13.
//
//等差数列问题
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N,M,a;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        for (int len = sqrt(2*M); len >=1; len--) {
            a = (2*M/len + 1 - len) / 2;
            if (len * len + 2 * a * len - len == 2 * M) {
                cout<<'['<<a<<','<<a+len-1<<']'<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}