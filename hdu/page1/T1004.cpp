//
// Created by wang on 2021/8/12.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
inline ll rd(){
    ll x=0;char c=getchar();bool f=0;
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return f?-x:x;
}

map<string,int> ma;
map<string,int>::iterator it;
int n;
string str;
int main(){
    while (cin >> n && n != 0) {
        ma.clear();
        for (int i = 1; i <= n; i++) {
            cin >> str;
            if (ma.count(str)) {
                ma[str] += 1;
            } else {
                ma[str] = 1;
            }
        }
        int maxn = 0;
        for (it = ma.begin(); it != ma.end(); it++) {
            if (it->second > maxn) {
                maxn = it->second;
                str = it->first;
            }
        }
        cout << str << endl;
    }

    return 0;
}