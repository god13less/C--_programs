//
// Created by wang on 2021/8/16.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
inline int read(){
    int x=0;char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
int n,k;
int c[1000040],vis[1000040];
string str;
vector<int> vec[1000040];
vector<int> tem;
map<int,int> ma;

void save(){
    if (ma.size() < c[1]) {
        cout<<"NO"<<endl;
        return;
    }
}

int main() {
    n=read();
    cin>>str;
    for (int i = 1; i <= n; i++) {
        vis[i]=read();
        if (ma.count(vis[i])) {
            ma[vis[i]]++;
        } else {
            ma[vis[i]]=1;
        }
    }
    k=1;
    memset(c, 0, sizeof c);
    for (int i = 1; i <= 2*n; i++) {
        if (str[i-1] == '(') {
            tem.push_back(k);
            vec[k]=tem;
            c[vec[k].size()]++;
            k++;
        } else {
            tem.pop_back();
        }
    }
//    save();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <vec[i].size() ; j++) {
            cout << vec[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<"______________"<<endl;
    for (int i = 1; i <= n; i++) {
        cout<<c[i]<<endl;
    }


    return 0;
}