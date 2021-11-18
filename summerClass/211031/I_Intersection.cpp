//
// Created by wang on 2021/10/31.
//

#include <cstdio>
#include <cmath>

using namespace std;
typedef long long ll;

struct node {
    double x, y, r;
};

double calarea(node a, node b) {
    double dis = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    if (a.r + b.r <= dis) {
        return 0;
    }
    if (a.r - b.r >= dis) {
        return acos(-1.0) * b.r * b.r;
    }
    if (b.r - a.r >= dis) {
        return acos(-1.0) * a.r * a.r;
    }
    double angle1 = acos((a.r * a.r + dis * dis - b.r * b.r) / (2 * dis * a.r));
    double angle2 = acos((b.r * a.r + dis * dis - a.r * a.r) / (2 * dis * b.r));
    return a.r * a.r * angle1 + b.r * b.r * angle2 - sin(angle1) * a.r * dis;
}

int t;
double r, R;
node a, b;

int main() {
    scanf("%lf", &t);
    int k = 0;
    while (t--) {
        k++;
        scanf("%lf %lf", &r, &R);
        scanf("%lf %lf", &a.x, &a.y);
        scanf("%lf %lf", &b.x, &b.y);
        double ans = 0;
        a.r = b.r = R;
        ans += calarea(a, b);
        a.r = R, b.r = r;
        ans -= 2 * calarea(a, b);
        a.r = b.r = r;
        ans += calarea(a, b);
        printf("Case #%d: %.6f\n", k, ans);
    }
    return 0;
}