//
// Created by wang on 2021/1/30.
//

#include <iostream>

using namespace std;
typedef long long ll;

const ll n = 10000000;

bool is_prime[100000010];
ll prime[100000010];
ll cnt = 0;

void EUIer(ll n) {
    for (ll i = 0; i < n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime[cnt++] = i;
        }
        for (ll j = 0; j < cnt && i * prime[j] <= n; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

bool is_palidromicNumber(ll n){
    ll arr[10];
    int i=0;
    while (n > 0) {
        arr[i++]=n%10;
        n=n/10;
    }
    for (int j = 0; j < i; j++) {
        if (arr[j] != arr[i - 1 - j]) {
            return false;
        }
    }
    return true;
}

int main() {
    ll num=0;
    EUIer(n);
    for (ll i = 0; i <cnt ; i++) {
        if (is_palidromicNumber(prime[i])) {
            cout<<prime[i]<<",";
            num++;
        }
    }
    cout<<endl<<num;

    return 0;
}
