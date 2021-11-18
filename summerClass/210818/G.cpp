#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
int l;
int dfn[maxn], low[maxn];
bool instack[maxn];
int ans;//记录环的大小
int idex = 1;
int len;//1所在链路的大小
stack<int> s;
vector<int> G[maxn];
bool flag = 1;

void tarjan(int u){
    s.push(u);
    instack[u] = 1;
    len++;
    int v;
    dfn[u] = low[u] = idex++;
    for (int i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        if(flag){
            l = u;
        }
        while (1) {
            if (flag) {
                ans++;
            }
            v=s.top();
            s.pop();
            instack[v] = 0;
            if (u == v) {
                flag = 0;
                break;
            }
        }
    }
}

int main() {
    ll n,k;
    cin >> n >> k;
    int u;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        G[i].push_back(u);
    }
    tarjan(1);
    int answer;
    int num=len-ans;
    if (k <= num - 1) {
        answer = 1;
        while (k--) {
            answer = G[answer][0];
        }
        cout<<answer<<endl;
    } else{
        answer=l;
        k = k - num;
        k %= ans;
        while (k--) {
            answer = G[answer][0];
        }
        cout<<answer<<endl;
    }
    return 0;
}