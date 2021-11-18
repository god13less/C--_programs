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

int main() {
    int t=read();
    while (t--) {
        int a,b;
        a=read();b=read();
        if (a > b) {
            int tem=b;
            b=a;
            a=tem;
        }
        if(a==1||(a==2&&b==2)){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
