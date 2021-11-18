//
// Created by wang on 2021/7/8.
//
// TME

#include <iostream>
using namespace std;
typedef long long ll;

struct node{
    int left,right,sum,addmark;
    node *lchild,*rchild;
} *root;

void build(node *cur, int l, int r){
    cur->left=l;
    cur->right=r;
    cur->sum=0;
    cur->addmark=0;
    if (l < r) {
        cur->lchild = new node;
        cur->rchild = new node;
        build(cur->lchild,l,(l+r)/2);
        build(cur->rchild,(l+r)/2+1,r);
    } else {
        cur->lchild=cur->rchild=nullptr;
    }
}

void pushUp(node *cur){
    cur->sum=cur->lchild->sum+cur->rchild->sum;
}

void pushDown(node *cur){
    if (cur->addmark != 0) {
        cur->lchild->addmark=cur->addmark;
        cur->rchild->addmark=cur->addmark;

        cur->lchild->sum = cur->addmark * (cur->lchild->right - cur->lchild->left + 1);
        cur->rchild->sum = cur->addmark * (cur->rchild->right - cur->rchild->left + 1);
        cur->addmark=0;
    }
}

void update(node *cur,int l,int r,int w){
    if (l > cur->right || r < cur->left) {
        return;
    }
    if (l <= cur->left && r >= cur->right) {
        cur->addmark=w;
        cur->sum = w * (cur->right - cur->left + 1);
        return;
    }
    pushDown(cur);
    int mid = (cur->left + cur->right) / 2;
    if (l <= mid) {
        update(cur->lchild, l, r, w);
    }
    if (r > mid) {
        update(cur->rchild, l, r, w);
    }
    pushUp(cur);
}

int query(node *cur,int l,int r) {
    if (l <= cur->left && cur->right <= r) {
        return cur->sum;
    } else {
        int ans=0;
        if (l < (cur->left + cur->right) / 2) {
            ans += query(cur->lchild, l, r);
        }
        if (l > (cur->left + cur->right) / 2) {
            ans += query(cur->rchild, l, r);
        }
        return ans;
    }
}

void del(node *cur){
    if (cur->lchild != nullptr) {
        del(cur->lchild);
    }
    if (cur->rchild != nullptr) {
        del(cur->rchild);
    }
    if (cur->rchild == nullptr and cur->lchild == nullptr) {
        delete cur;
    }
}


int main(){
    int t, n, q;
    cin>>t;
    root=new node;
    for (int j = 1; j <= t; j++) {
        cin >> n >> q;
        build(root,1,n);
        update(root, 1, n, 1);
        for (int i = 1; i <= q; i++) {
            int l,r,v;
            cin>>l>>r>>v;
            update(root,l,r,v);
        }
        cout<<"Case "<<j<<": The total value of the hook is "<<root->sum<<'.'<<endl;
        del(root);
    }
    return 0;
}
