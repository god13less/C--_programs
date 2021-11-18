//
// Created by wang on 2021/9/15.
//
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
inline int read(){
    int x=0;char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}

ll arr[1000000];

void init(){
    arr[0]=0;
    arr[1]=2;
    for (int i = 2; i <= 1000000; i++) {
        arr[i]=arr[i-1]+arr[i-1]-arr[i-2]+3;
    }
}


int main() {
    init();
    int t ;
    cin>>t;
    ll n;
    while (t--) {
        cin>>n;
        int ans=0;
        int index;
        while (n!=1&&n!=0) {
            index=upper_bound(arr,arr+1000000,n)-arr-1;
            n -= arr[index];
            ans++;
            if (n == 2) {
                ans++;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
