//
// Created by wang on 2021/2/18.
//

#include <iostream>

using namespace std;
typedef long long ll;

int n,m,num,tem,t1;
int pre[30030];

int Find(int x){
    while (pre[x] != x) {
        x = Find(pre[x]);
    }
    return x;
}
void Union(int x,int y){
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy) {
        pre[fy]=fx;
    }
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            return 0;
        }
        for (int i = 0; i < 30030; i++) {
            pre[i]=i;
        }
        for (int i = 0; i < m; i++) {
            cin>>num>>t1;
            for (int j = 1; j < num; j++) {
                cin>>tem;
                Union(t1, tem);
                t1=tem;
            }
        }
        tem=0;
        for (int i = 0; i < n; i++) {
            if (Find(pre[i]) == Find(pre[0])) {
                tem++;
            }
        }
        cout<<tem<<endl;
    }

    return 0;
}
