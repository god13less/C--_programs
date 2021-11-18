//
// Created by wang on 2021/7/6.
//

#include <iostream>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
double h[105],d[105],x[105],y[105];

int main() {
    ll n;
    double vx,vy,vxvy;
    while (cin >> n) {
        for (int i = 1; i <=n ; i++) {
            cin >> h[i] >> d[i];
        }
        h[n+1]=0;
        for (int i = 1; i <=n ; i++) {
            x[i]=x[i-1]+d[i];
            y[i]=max(h[i],h[i+1]);
        }
        vxvy = 9.8 * 0.5 * y[n];
        for
    }

    return 0;
}