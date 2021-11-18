//
// Created by wang on 2021/3/25.
//

#include<cstring>
#include<cstdio>

using namespace std;

const int maxn=500000;
char wen[20];

struct node{
    int tot;
    int child[26];
    node(){
        tot=0;
        memset(child,0,sizeof(child));
    }
}tree[maxn];

int sz=0;

void insert(char *s){
    int u=0;
    int h=strlen(s);
    for(int i=0;i<h;i++){
        int pos=s[i]-'a';
        if(tree[u].child[pos]==0){
            tree[u].child[pos]=++sz;
        }
        u=tree[u].child[pos];
        tree[u].tot++;
    }
}

int find(char *t){
    int u=0;
    int h=strlen(t);
    for(int i=0;i<h;i++){
        int pos=t[i]-'a';
        if(tree[u].child[pos]==0){
            return 0;
        }
        u=tree[u].child[pos];
    }
    return tree[u].tot;
}

int main(){
    while(gets(wen)){
        if(strlen(wen)==0)  break;
        insert(wen);
    }
    while(gets(wen)){
        printf("%d\n",find(wen));
    }
    return 0;
}