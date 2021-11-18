//
// Created by wang on 2021/7/9.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;

ll quick_pow(ll a,ll b,ll c){
    ll ans=1,base=a;
    while(b!=0){
        if(b&1){
            ans=ans*base%c;
        }
        base=base*base%c;
        b>>=1;
    }
    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, a;
    cin>>n;
    while (n--) {
        cin>>a;
        cout<<quick_pow(a,a,10)<<endl;
    }

    return 0;
}