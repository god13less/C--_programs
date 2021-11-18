//
// Created by wang on 2021/8/17.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;

int n, m;             //n为顶点数
int indegree[550];   //记录每个顶点的入度
vector<int> arr[550];//邻接表
//维护一个入度为零的顶点集合,需要字典序的话就用优先列队
queue<int> que;

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
        int u = que.front();
        que.pop();
        count++;
        //将所有u指向的顶点的入度减一，并将入度减为零的点入队
        for (int & i : arr[u]) {
            indegree[i]--;
            if (!indegree[i]) {
                que.push(i);
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
        if(topological_sort()){
            cout<<n*888+n-1<<endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}