//
// Created by wang on 2021/8/18.
//p2337
//有向图

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;

//前向星
struct Edge {
    int to, next;
    int index;
    bool flag;
} edge[maxn];

int head[maxn], tot;

void addedge(int u, int v, int w) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].index = w;
    edge[tot].flag = false;
    head[u] = tot++;
}

void init() {
    tot = 0;
    memset(head, -1, sizeof (head));
}

string num[maxn];
int in[maxn], out[maxn], ans[maxn];
int cnt;

void dfs(int start) {
    for (int i = head[start]; i != -1; i = edge[i].next) {
        if (!edge[i].flag) {
            edge[i].flag = true;
            dfs(edge[i].to);
            ans[cnt++] = edge[i].index;
        }
    }
}

int main() {
    int T, n;
    cin>>T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; ++i) {
            cin >> num[i];
        }
        sort(num + 1, num + 1 + n);
        memset(in, 0, sizeof (in));
        memset(out, 0, sizeof (out));
        int start = inf;
        for (int i = n; i >= 1; --i) {
            int u = num[i][0] - 'a';
            int v = num[i][num[i].length() - 1] - 'a';
            addedge(u, v, i);
            in[v]++, out[u]++;  //入度与出度计算
            if (u < start) {
                start = u;
            }
        }
        int c1 = 0, c2 = 0;
        for (int i = 0; i < 26; ++i) {
            if (out[i] - in[i] == 1) {
                ++c1;
                start = i;
            } else if (out[i] - in[i] == -1) {
                ++c2;
            } else if (out[i] - in[i] != 0) {
                c2 = 3;
            }
        }
        if ((c1 == 1 && c2 == 1) || (c1 == 0 && c2 == 0)) {
            cnt = 0;
            dfs(start);
            if (cnt != n) {
                printf("***\n");
            } else {
                for (int i = cnt - 1; i >= 0; --i) {
                    if (i == 0) {
                        cout << num[ans[i]];
                    } else {
                        cout << num[ans[i]] << ".";
                    }
                }
                printf("\n");
            }
        } else {
            printf("***\n");
        }
    }
    return 0;
}


