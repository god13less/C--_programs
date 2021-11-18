//
// Created by wang on 2021/9/29.
//
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
ll k,p,ans,num,asd;
int arr[100];

int main() {
    cin >> k >> p;
    ans=0;
    for (ll i = 1; i <= k; i++) {
        asd=i;
        num=0;
        int tem=i;
        while (tem) {
            num++;
            arr[num] = tem % 10;
            tem /= 10;
        }
        for (int j = 1; j <= num; j++) {
            asd *= 10;
            asd += arr[j];
        }
        ans = (ans + asd % p) % p;
    }
    cout<<ans<<endl;
    return 0;
}
