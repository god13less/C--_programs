//数据有问题

#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

char s[550][2005];
int vis[550];

int solve(char *fa,char *son)
{
    int n = strlen(fa);
    int m = strlen(son);
    int i = 0; // 主串的索引
    int j = 0; // 字串的索引

    while (i < n && j < m) {
        if (son[j] == fa[i]) {
            i++;
            j++;
        } else {
            i = i - j + 1; // 这句是关键
            j = 0;
        }
    }
    if (j == m) {
        return i - j;
    }
    else {
        return -1;
    }
    return -1;
}

int main()
{
    int t;scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(vis,0,sizeof(vis));
        int n;scanf("%d",&n);
        int flag = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]);
            for(int j=i-1;j>=1;j--)
            {
                if(vis[j])continue;
                if(solve(s[i],s[j])==-1){flag=i;break;}
                else vis[j]=1;
            }
        }
        if(!flag)
            printf("Case #%d: -1\n",cas);
        else
            printf("Case #%d: %d\n",cas,flag);
    }
}