//
// Created by wang on 2021/8/12.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 2009;

int n,c;
int tot=0;
struct node{
    int x,y;
}p[maxn];
int pre[maxn];

struct edge{
    int a,b,dis;
    friend bool operator < (const edge &a,const edge b){
        return a.dis < b.dis;
    }
}ed[19260817];

int dis(node a, node b){
    return pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
}

inline void init(){
    for (int i = 0; i <=maxn; i++) {
        pre[i]=i;
    }
}

inline int Find(int x){
    if(x!=pre[x]){
        pre[x] = Find(pre[x]);
    }
    return pre[x];
}

void kruskal(){
    init();
    int u,v;
    int cnt=0,ans=0;
    for (int i = 1; i <= tot; i++) {
        u=ed[i].a;
        v=ed[i].b;
        u = Find(u);
        v = Find(v);
        if (u != v) {
            pre[u] = v;
            ans+=ed[i].dis;
            cnt++;
        }
        if (cnt == n - 1) {
            break;
        }
    }
    if (cnt == n - 1) {
        cout<<ans<<endl;
    } else {
        cout<<-1<<endl;
    }
    return;
};


int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>c;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        for (int j = 1; j < i; j++) {
            if (dis(p[i], p[j]) >= c) {
                ed[++tot].a=i;
                ed[tot].b=j;
                ed[tot].dis = dis(p[i], p[j]);
            }
        }
    }
    sort(ed+1,ed+1+tot);
    kruskal();
    return 0;
}
