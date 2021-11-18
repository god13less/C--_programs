//
// Created by wang on 2021/5/23.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int line[510][510], boy[510], used[510];
int n,m;
int Find(int x){
    int i,j;
    for (i = 1;  i<=m ; i++) {
        if (line[x][i] = 1&&used[i] == 0) {
            used[i]=1;
            if (boy[i] == 0 || Find(boy[i])) {
                boy[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int i,j,k,x,y,sum;
    while ((cin >> k >> n >> m)&&k!=0) {
        memset(line, 0, sizeof (line));
        memset(boy, 0, sizeof (boy));
        memset(used, 0, sizeof (used));
        for ( i = 0; i < k; i++) {
            cin>>x>>y;
            line[x][y]=1;
        }
        sum=0;
        for ( i = 1; i <=n ; i++) {
            memset(used, 0, sizeof (used));
            if (Find(i)) {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
