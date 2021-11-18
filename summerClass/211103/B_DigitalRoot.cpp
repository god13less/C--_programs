//
// Created by wang on 2021/11/3.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000060

using namespace std;
typedef long long ll;
inline ll read(){
    int x=0;char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
ll t,n,k;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout<<(n-1)*9+k<<endl;
    }

    return 0;
}