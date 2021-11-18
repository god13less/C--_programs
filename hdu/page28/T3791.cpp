//
// Created by wang on 2021/7/7.
//

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int tree[1005],tem[1005];
int n;

void init(){
    for (int i = 0; i < 1005; i++) {
        tree[i]=-1;
        tem[i]=-1;
    }
}

void add(int t[], int pos,int val){
    if (t[pos] == -1) {
        t[pos]=val;
        return;
    }
    if (val < t[pos]) {
        add(t,pos*2,val);
    } else {
        add(t,pos*2+1,val);
    }
}

int main(){
    init();
    while (cin >> n && n > 0) {
        init();
        string s;
        cin>>s;
        int len=s.length();
        int temlen;
        for (int i = 0; i < len; i++) {
            add(tree,1,s[i]-'0');
        }
        for (int i = 0; i < n; i++) {
            cin>>s;
            temlen=s.length();
            for (int j = 0; j < temlen; j++) {
                add(tem,1,s[j]-'0');
            }
            //判断
            if (len == temlen) {
                int flag=0;
                for (int j = 0; j < 1000; j++) {
                    if (tem[j] != tree[j]) {
                        flag=1;
                        break;
                    }
                }
                if (flag) {
                    cout<<"NO"<<endl;
                } else {
                    cout<<"YES"<<endl;
                }
            } else {
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}