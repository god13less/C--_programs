//
// Created by wang on 2021/8/17.
// hdu1285

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;

int n, m;             //n为顶点数
int indegree[550];   //记录每个顶点的入度
vector<int> arr[550];//邻接表
//维护一个入度为零的顶点集合,需要字典序的话就用优先列队
priority_queue<int,vector<int>,greater<int>> que;

void init() {
    memset(indegree, 0, sizeof indegree);
    memset(arr, 0, sizeof arr);
    while (!que.empty()) {
        que.pop();
    }
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        arr[u].push_back(v);
        indegree[v]++;
    }
}

bool topological_sort() {
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            que.push(i);        //将所有的入度为0的顶点入队
        }
    }
    int count = 0;                //计数，记录当前已经输出的顶点数
    while (!que.empty()) {
        int u = que.top();
        que.pop();
        if (count == 0) {
            cout << u;
        } else {
            cout << " " << u;   //输出顶点
        }
        count++;
        //将所有u指向的顶点的入度减一，并将入度减为零的点入队
        for (int i=0; i < arr[u].size(); i++) {
            indegree[arr[u][i]]--;
            if (!indegree[arr[u][i]]) {
                que.push(arr[u][i]);
            }
        }
    }
    if (count < n) {
        return false;
    } else {
        return true;
    }
}

int main() {
    while (cin >> n >> m) {
        init();
        topological_sort();
        cout<<endl;
    }
    return 0;
}