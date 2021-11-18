//
// Created by wang on 2021/8/9.
//

#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

ll d[6];
ll m[6];
ll arr[5];
queue<ll> que;

int main() {
    ll n;
    cin>>n;
    for (int i = 1; i <= 4; i++) {
        cin>>d[i];
    }
    d[5]=40000;
    for (int i = 1; i <=5 ; i++) {
        cin>>m[i];
    }
    ll tem;
    for (int i = 1; i <= n; i++) {
        cin>>tem;
        que.push(tem);
    }
    for (int i = 1; i <= 4; i++) {
        arr[i]=que.front();
        que.pop();
    }

    return 0;
}

