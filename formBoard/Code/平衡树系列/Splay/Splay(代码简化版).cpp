const int maxn = 1e5+5;
struct Node
{
    int fa,ch[2],val,cnt,size;  //ch[0]是左儿子，ch[1]是右儿子
}spl[maxn];
int cnt,root;
inline void update(int x)
{
    spl[x].size=spl[spl[x].ch[0]].size+spl[spl[x].ch[1]].size+spl[x].cnt;
}
inline bool ident(int x,int f) { return spl[f].ch[1]==x; }  //查询父子关系
inline void connect(int x,int f,int s)          //建立父子关系
{
    spl[f].ch[s]=x;
    spl[x].fa=f;
}
void rotate(int x)      //合二为一的旋转
{
    int f=spl[x].fa,ff=spl[f].fa,k=ident(x,f);
    connect(spl[x].ch[k^1],f,k);        //三次建立父子关系
    connect(x,ff,ident(f,ff));
    connect(f,x,k^1);
    update(f),update(x);                //别忘了更新大小信息
}
void splaying(int x,int top)//代表把x转到top的儿子，top为0则转到根结点
{
    if(!top) root=x;
    while(spl[x].fa!=top)
    {
        int f=spl[x].fa,ff=spl[f].fa;
        if(ff!=top) ident(f,ff)^ident(x,f)?rotate(x):rotate(f);
        rotate(x);      //最后一次都是旋转x
    }
}
void newnode(int &now,int fa,int val)   //新建节点，要注意fa指针的初始化
{
    spl[now=++cnt].val=val;
    spl[cnt].fa=fa;
    spl[cnt].size=spl[now].cnt=1;
}
void delnode(int x)                 //删除结点，要注意fa指针的维护
{
    splaying(x,0);
    if(spl[x].cnt>1) spl[x].cnt--;
    else if(spl[x].ch[1])
    {
        int p = spl[x].ch[1];
        while(spl[p].ch[0]) p=spl[p].ch[0];
        splaying(p,x);
        connect(spl[x].ch[0],p,0);
        root=p;
        spl[p].fa=0;
        update(root);
    }
    else root=spl[x].ch[0],spl[root].fa=0;
}
void ins(int val,int &now=root,int fa=0)    //递归式，要传fa指针
{
    if(!now) newnode(now,fa,val),splaying(now,0);
    else if(val<spl[now].val) ins(val,spl[now].ch[0],now);
    else if(val>spl[now].val) ins(val,spl[now].ch[1],now);
    else spl[now].cnt++,splaying(now,0);
}
void del(int val,int now=root)              //同上
{
    if(val==spl[now].val) delnode(now);
    else if(val<spl[now].val) del(val,spl[now].ch[0]);
    else del(val,spl[now].ch[1]);
}

void find(int x) {
    int u = root;
    if (!u) return;
    while (spl[u].ch[x > spl[u].val] && x != spl[u].val) {
        u = spl[u].ch[x > spl[u].val];
    }
    splaying(u, 0);
}

int next(int x, int pn) {//pn=0为前驱，1为后驱
    find(x);
    int u = root;//根节点，此时x的父节点（存在的话）就是根节点
    if (spl[u].val > x && pn)return u;//如果当前节点的值大于x并且要查找的是后继
    if (spl[u].val < x && !pn)return u;//如果当前节点的值小于x并且要查找的是前驱
    u = spl[u].ch[pn];//查找后继的话在右儿子上找，前驱在左儿子上找
    while (spl[u].ch[pn ^ 1]) u = spl[u].ch[pn ^ 1];//要反着跳转，否则会越来越大（越来越小）
    return u;//返回位置
}

int kth(int k){
    int u=root;
    if(spl[u].size<k) return 0;
    while (1) {
        int l = spl[u].ch[0];
        if (k > spl[l].size + spl[u].cnt) {
            k-=spl[l].size + spl[u].cnt;
            u=spl[u].ch[1];
        } else {
            if (k <= spl[l].size) {
                u = l;
            } else {
                return spl[u].val;
            }
        }
    }
}

