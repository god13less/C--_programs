//
// Created by wang on 2021/7/8.
//

//基础的线段树模板题
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=100005;
int t,n,q;
ll sum[maxn*4],add[maxn*4];
void pushup(int rt){
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void pushdown(int rt,int len){
    if(add[rt]){
        add[rt<<1]=add[rt];
        add[rt<<1|1]=add[rt];
        sum[rt<<1]=add[rt]*(len-(len>>1));
        sum[rt<<1|1]=add[rt]*(len>>1);
        add[rt]=0;
    }
}
void build(int l,int r,int rt){
    add[rt]=0;
    if(l==r){
        //scanf("%I64d",&sum[rt]);
        sum[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L<=l&&R>=r){
        add[rt]=c;
        sum[rt]=(ll)c*(r-l+1);
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,l,m,rt<<1);
    if(R>m) update(L,R,c,m+1,r,rt<<1|1);
    pushup(rt);
}
ll querry(int L,int R,int l,int r,int rt){
    if(L<=l&&R>=r) return sum[rt];
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    ll ans=0;
    if(L<=m) ans+=querry(L,R,l,m,rt<<1);
    if(R>m) ans+=querry(L,R,m+1,r,rt<<1|1);
    return ans;
}
int main(){
    int x,y,z;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>n>>q;
        build(1,n,1);
        while(q--){
            cin>>x>>y>>z;
            update(x,y,z,1,n,1);
        }
        printf("Case %d: The total value of the hook is %I64d.\n",cas,querry(1,n,1,n,1));
    }
}