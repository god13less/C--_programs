//
// Created by wang on 2021/7/10.
//


#include<iostream>
#include<random>
#define endl "\n"
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int INF=1e9+7,MAXN=1e5+10;
int sz,rt;
int size[MAXN],key[MAXN],cnt[MAXN],rd[MAXN],son[MAXN][2];
inline void push_up(int x){
    size[x]=size[son[x][0]]+size[son[x][1]]+cnt[x];
}

inline void rotate(int &x,int y){
    int ii =son[x][y^1];
    son[x][y^1]=son[ii][y];
    son[ii][y]=x;
    push_up(x);
    push_up(ii);
    x=ii;
}

void ins(int &p, int x){
    if (!p) {
        p=++sz;
        size[p]=cnt[p]=1;
        key[p]=x;
        rd[p]=rand();
        return;
    }
    if (key[p] == x) {
        cnt[p]++;
        size[p]++;
        return;
    }
    int d=(x>key[p]);
    ins(son[p][d], x);
    if (rd[p < rd[son[p][d]]]) {
        rotate(p,d^1);
    }
    push_up(p);
}

void del(int &p,int x){
    if(!p)
        return;
    if(x!=key[p])
        del(son[p][x>key[p]],x);
    else{
        if(!son[p][0]&&!son[p][1]){
            cnt[p]--;
            size[p]--;
            if(cnt[p]==0)
                p=0;
        }else if(son[p][0]&&!son[p][1]){
            rotate(p,1);
            del(son[p][1],x);
        }else if(!son[p][0]&&son[p][1]){
            rotate(p,0);
            del(son[p][0],x);
        }else{
            int d=rd[son[p][0]]>rd[son[p][1]];
            rotate(p,d);
            del(son[p][d],x);
        }
    }
    push_up(p);
}
int get_rank(int p,int x){
    if(!p)
        return 0;
    if(key[p]==x)
        return size[son[p][0]]+1;
    if(key[p]<x)
        return size[son[p][0]]+cnt[p]+get_rank(son[p][1],x);
    /*if(key[p]>x)*/
    return get_rank(son[p][0],x);
}
int find(int p,int x){
    if(!p)
        return 0;
    if(size[son[p][0]]>=x)
        return find(son[p][0],x);
    else if(size[son[p][0]]+cnt[p]<x)
        return find(son[p][1],x-cnt[p]-size[son[p][0]]);
    else
        return key[p];
}
int pre(int p,int x){
    if(!p)
        return -INF;
    if(key[p]>=x)
        return pre(son[p][0],x);
    else
        return max(key[p],pre(son[p][1],x));
}
int suf(int p,int x){
    if(!p)
        return INF;
    if(key[p]<=x)
        return suf(son[p][1],x);
    else
        return min(key[p],suf(son[p][0],x));
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    int q,x;
    cin>>t;
    while (t--) {
        cin>>q>>x;
        switch(q) {
            case 1:{
                ins(rt, x);
                break;
            }
            case 2:{
                del(rt, x);
                break;
            }
            case 3:{
                cout << get_rank(rt, x)<<endl;
                break;
            }
            case 4:{
                cout<<find(rt,x)<<endl;
                break;
            }
            case 5:{
                cout<<pre(rt,x)<<endl;
                break;
            }case 6:{
                cout<<suf(rt,x)<<endl;
                break;
            }
        }
    }
    return 0;
}