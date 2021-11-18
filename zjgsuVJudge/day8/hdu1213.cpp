//
// Created by wang on 2021/2/18.
//

#include <iostream>

using namespace std;
typedef long long ll;

int k,n,m,t1,t2;
int pre[1010];

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
    cin>>k;
    for (int i = 0; i < k; i++) {
        cin>>n>>m;
        for (int j = 0; j < 1010; j++) {
            pre[j] = j;
        }
        for (int j = 0; j < m; j++) {
            cin>>t1>>t2;
            Union(t1,t2);
        }
        t1=0;
        for (int j = 1; j <=n ; j++) {
            if (pre[j] == j) {
                t1++;
            }
        }
        cout<<t1<<endl;
    }

    return 0;
}
