//
// Created by wang on 2021/8/11.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

int main(){
    int t,n;
    double x1,x2,x3,y1,y2,y3,ans;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);
//        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
        x2=x2-x1;
        y2=y2-y1;
        ans= x2*y2*(4*n-10+3.0/pow(2,n-2));
//        cout<<fixed<< setprecision(3)<<ans<<endl;
        printf("%.3f\n",ans);
    }

    return 0;
}
