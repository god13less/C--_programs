//
// Created by wang on 2021/2/18.
//

#include<stdio.h>

struct Node {
    int s, e;
} room[100001];
int pre[100001];

int find(int x) {
    int r = x;
    while (r != pre[r])r = pre[r];
    int i = x, j;
    while (i != r)j = pre[i], pre[i] = r, i = j;//并差集修正
    return r;
}

int main() {
    int f1, f2, A, B, t = 0, flag = 0, v = 0, k;
    for (int i = 1; i <= 100000; ++i)pre[i] = i;
    while (scanf("%d%d", &A, &B), A != -1 && B != -1) {
        if (A == 0 && B == 0)v = 1;
        else {
            room[t].s = A;
            room[t].e = B;
            t++;
            f1 = find(A);
            f2 = find(B);
            if (f1 == f2)flag = 1;
            else pre[f1] = f2;
        }
        k = 0;
        if (v) {
            for (int i = 0; i < t; ++i) {
                if (room[i].s == pre[room[i].s])k++;
                if (room[i].e == pre[room[i].e])k++;
            }
        }
        if (k > 1)flag = 1;
        if (v) {
            if (flag)printf("No\n");
            else printf("Yes\n");
            t = flag = v = 0;
            for (int i = 1; i <= 100000; ++i) {
                pre[i] = i;
            }
        }
    }
    return 0;
}