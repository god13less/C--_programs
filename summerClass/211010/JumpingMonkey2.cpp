//
// Created by wang on 2021/10/10.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 100000

using namespace std;
typedef long long ll;

inline int read() {
    int x = 0;
    char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar());
    for (; isdigit(ch); ch = getchar())x = (x << 1) + (x << 3) + (ch ^ 48);
    return x;
}

int n, t;
int val[maxn + 5], lsh[maxn + 5];
vector<int> arr[maxn + 5];
int maxx;

void lsh_arr() {
    map<int, int> ma;
    sort(lsh + 1, lsh + n + 1);
    int cnt = unique(lsh + 1, lsh + n + 1) - lsh - 1;
    for (int i = 1; i <= cnt; i++) {
        ma[i] = lsh[i];
    }
    for (int i = 1; i <= n; i++) {
        val[i] = lower_bound(lsh + 1, lsh + cnt + 1, val[i]) - lsh;
    }
}

bool flag[maxn + 5];
int que[maxn + 5];
int cnt = 0;

int bfs(int k) {
    memset(flag, 0, sizeof flag);
    //对节点1进行赋值。
    queue<int> q;// 定义一个队列
    q.push(k);//节点入队
    flag[k] = true;
    while (!q.empty()) {//当队列不为空时，一直搜索
        int tem = q.front();//将节点1的信息赋给节点2
        q.pop();//队首出队
        //找邻节点，得到一些信息，可以执行一些操作，并标记访问，将邻接点入队
        for (int i = 0; i < arr[tem].size(); i++) {
            if (!flag[arr[tem][i]]) {
                if (val[arr[tem][i]] < val[tem] && (arr[arr[tem][i]].size() == 1)) {
                    cnt++;
                    que[cnt] = arr[tem][i];
                }
                q.push(arr[tem][i]);
                flag[arr[tem][i]] = true;
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        memset(que, 0, sizeof que);
        memset(flag, 0, sizeof flag);
        cnt = 0;
        n = read();
        for (int i = 1; i < n; i++) {
            int x, y;
            x = read(), y = read();
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            val[i] = read();
            lsh[i] = val[i];
        }
        lsh_arr();
        maxx=1;
        for (int i = 1; i <= n; i++) {
            if (val[maxx] < val[i]) {
                maxx = i;
            }
        }
        bfs(maxx);
        for (int i = 1; i <= n; i++) {
            int tem_cnt = 0;
            for (int j = 1; j <= cnt; j++) {
                if (val[i] < val[que[j]]) {
                    tem_cnt++;
                }
            }
            cout << val[maxx] + 1 - tem_cnt - val[i] << endl;
        }
    }
    return 0;
}