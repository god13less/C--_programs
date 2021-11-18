//
// Created by wang on 2021/8/14.
//

#include<bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
int n,m,p,a,b;
struct node{
    ll p,a,b;
}c[100005];
bool cmp(node x,node y){
    return x.p < y.p;
}

int main() {
    cin >> n >> m;
    int time=0,temTime=0;
    for (int i = 1; i <= m; i++) {
        cin >> c[i].p >> c[i].a >> c[i].b;
    }
    sort(c + 1, c + 1 + m, cmp);
    c[++m].p=n;
    c[m].a = 0;
    c[m].b = 1;
    for (int i = 1; i <= m; i++) {
        time += c[i].p - c[i - 1].p;
        temTime = time % (c[i].a + c[i].b);
        if (temTime < c[i].a) {
            time += c[i].a - temTime;
        }
    }
    cout << time << endl;

    return 0;
}