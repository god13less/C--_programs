#include <iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
char ss[33][33];
double dis[33][33];

int main() {
    int n, m, o = 1;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < 33; i++)
            for (int j = 0; j < 33; j++)
                dis[i][j] = i == j ? 1 : 0;

        for (int i = 0; i < n; i++)
            scanf("%s", ss[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            double hh = 0;
            char s0[33], s1[33];
            scanf("%s%lf%s", s0, &hh, s1);
            int k1, k2;
            for (int j = 0; j < n; j++) {
                if (strcmp(s0, ss[j]) == 0)
                    k1 = j;
                if (strcmp(s1, ss[j]) == 0)
                    k2 = j;
            }
            dis[k1][k2] = hh;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dis[i][j] = max(dis[i][j], dis[i][k] * dis[k][j]);
        int flag = 0;
        for (int i = 0; i < n; i++)
            if (dis[i][i] > 1.0) {
                printf("Case %d: Yes\n", o++);
                flag = 1;
                break;
            }
        if (flag == 0)printf("Case %d: No\n", o++);
    }
    return 0;
}