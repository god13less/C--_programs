//
// Created by wang on 2021/7/7.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
typedef struct binTreeNode{
    ll v;
    struct binTreeNode *lchild,*rchild;
} *BT;

void add(BT &T,ll val){//构造一个二叉搜索树
    if (T == NULL) {
        T = new binTreeNode();
        T->v=val;
        T->lchild=T->rchild=NULL;
    } else if (T->v > val) {
        add(T->lchild, val);
    } else if (T->v < val) {
        add(T->rchild, val);
    }
}

void preOrder(BT T, bool flag){//先序输出
    if (T == NULL) {
        return;
    } else {
        if(!flag) {
            cout << ' ';
        }
        cout<<T->v;
        preOrder(T->lchild,0);
        preOrder(T->rchild,0);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    BT T;
    ll n,v;
    cin>>n;
    T=NULL;
    for (int i = 1; i <= n; i++) {
        cin>>v;
        add(T,v);
    }
    preOrder(T,1);
    cout<<endl;
    return 0;
}
