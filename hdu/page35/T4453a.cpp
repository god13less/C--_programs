//
// Created by wang on 2021/8/11.
//

#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define maxn 1100000
#define mem(a,b) memset(a,b,sizeof(a))
#define root10 ch[ch[root][1]][0]
#define root11 ch[ch[root][1]][0]
#define root1 ch[root][1]
#define rson ch[x][1]
#define lson ch[x][0]

int ch[maxn][2];
int pre[maxn];
int root,tot;
int val[maxn];
int rev[maxn];
int sum[maxn];
int size[maxn];

int num[maxn],n;

void init(){
    root=tot=0;
}
void newnode(int &x,int k,int father){
    x=++tot;
    pre[x]=father;
    size[x]=1;
    ch[x][0]=ch[x][1]=0;
    val[x]=k;
    rev[x]=0;
    sum[x]=0;
}
void push_down(int x){
    if (sum[x]) {
        val[lson]+=sum[x];
        val[rson]+=sum[x];
        sum[lson]+=sum[x];
        sum[rson]+=sum[x];
        sum[x]=0;
    }
    if (rev[x]) {
        rev[x]=0;
        rev[ch[x][0]]^=1;
        rev[ch[x][1]]^=1;
        swap(ch[x][0], ch[x][1]);
    }
}
void push_up(int x){
    size[x]=size[lson]+size[rson]+1;
}
void rot(int x,int kind){

}