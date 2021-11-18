//
// Created by wang on 2021/5/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
LL quick_mod(LL a, LL b, LL p)//快速幂:a^b%p
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

int main(){
    int T;
    while (cin >> T) {
        if (T==0) {
            return 0;
        }
        for (int i = 1; i <=T ; i++) {
            LL N;
            cin>>N;
            int ans = (quick_mod(4,N-1,100)+quick_mod(2,N-1,100))%100;
            cout<<"Case "<<i<<": "<<ans<<endl;
        }
        cout<<endl;
    }
    return 0;
}