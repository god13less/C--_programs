#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct Node
{
    long long t,x;
} Node[10005];
bool cmp(struct Node n,struct Node m)
{
    return n.t<m.t;
}
int main()
{
    int t,c;
    scanf("%d",&t);
    for(c=1; c<=t; c++)
    {
        int n,q=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld%lld",&Node[i].t,&Node[i].x);
        }
        sort(Node,Node+n,cmp);
        double a[10005];
        memset(a,0,sizeof(a));
        for(int i=1; i<n; i++)
        {
            a[q++]=1.0*abs(Node[i].x-Node[i-1].x)/(Node[i].t-Node[i-1].t);
        }
        sort(a,a+q);
        printf("Case #%d: %.2lf\n",c,a[q-1]);
    }
    return 0;
}