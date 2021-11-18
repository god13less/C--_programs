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
map<int,int> ma;
int main() {
    int n = read();
    for (int i = 1; i <= n; i++) {
        int tem = read();
        if (ma.count(tem)) {
            ma[tem]++;
        } else {
            ma[tem] = 1;
        }
    }
    map<int, int>::iterator it;
    int maxx=0;
    for (it = ma.begin(); it != ma.end(); it++) {
        if (maxx < it->second) {
            maxx = it->second;
        }
    }
    cout<<maxx<<endl;
    return 0;
}