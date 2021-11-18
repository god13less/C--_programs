//
// Created by wang on 2021/7/8.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;

map<int,int> ma;
map<int,int>::iterator it;
int pre[1005],vis[1005];

int find(int x){
    while(x!=pre[x]){
        x=pre[x];
    }
    return x;
}
void Union(ll x,ll y){
    ll fx = find(x);
    ll fy = find(y);
    if (fx != fy) {
        pre[fy]=fx;
    }
}
void init(){
    for (int i = 0; i <=1005 ; i++) {
        pre[i]=i;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x,y,k=0;
    init();
    while (cin >> x >> y && (x>=0 &&y>=0)) {
        if (x != 0 && y != 0) {
            if (!ma.count(x)) {
                ma[x]=0;
            }
            if (ma.count(y)) {
                if (ma[y] == 0) {
                    ma[y]=1;
                }else {
                    ma[y] = 2;
                }
            } else {
                ma[y]=1;
            }
            Union(x, y);
        } else {
            k++;
            int sum1=0,sum2=0;
            for (it=ma.begin();it!=ma.end();it++) {
                if (it->second == 0) {
                    sum1++;
                }else if(it->second == 2){
                    sum2++;
                }
            }
            if (sum1 != 1 || sum2>=1) {
                cout<<"Case "<<k<<" is not a tree."<<endl;
            } else {
                cout<<"Case "<<k<<" is a tree."<<endl;
            }
            ma.clear();
            init();
        }
    }
    return 0;
}