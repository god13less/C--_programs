//
// Created by wang on 2021/10/13.
//
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
inline int read(){
    int x=0;char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
int h1,a1,c1,h2,a2,cnt;
queue<string> que;

int main() {
    cnt=0;
    cin>>h1>>a1>>c1>>h2>>a2;
    int top=h1;//top为生命上限
    int k=top/a2;
    if(top%a2!=0) {
        k++;
    }
    while (h2>k*a1) {
        cnt++;
        h1-=a2;
        if(h1>=a2) {
            que.push("STRIKE");
            h2-=a1;
        } else {
            que.push("HEAL");
            h1+=c1;

        }
        k=h1/a2;
        if(h1%a2!=0) {
            k++;
        }
    }
    k=h2/a1;
    if(h2%a1!=0) {
        k++;
    }
    while (k--) {
        cnt++;
        que.push("STRIKE");
    }
    cout<<cnt<<endl;
    while (!que.empty()) {
        cout<<que.front()<<endl;
        que.pop();
    }

    return 0;
}
