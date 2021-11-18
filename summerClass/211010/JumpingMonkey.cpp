//
// Created by wang on 2021/10/10.
//
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 100000

using namespace std;
typedef long long ll;
inline int read(){
    int x=0;char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
int n;
int val[maxn + 5];
vector<int> arr[maxn + 5];
vector<int> tem_bigger,tem_litter;
int cnt;
int maxx;
int bfs(int k,int now){
    //对节点1进行赋值。
    queue<int> q;// 定义一个队列
    q.push(k);//节点入队
    while(!q.empty()){//当队列不为空时，一直搜索
        int tem=q.front();//将节点1的信息赋给节点2
        q.pop();//队首出队
        //找邻节点，得到一些信息，可以执行一些操作，并标记访问，将邻接点入队
        for (int i = 0; i < arr[tem].size(); i++) {
            if (val[arr[tem][i]] > now) {
                return arr[tem][i];
            }else{
                q.push(arr[tem][i]);
            }
        }
    }
}

void save(int k,int now){
    tem_bigger.clear();
    tem_litter.clear();
    for (int i = 0; i < arr[k].size(); i++) {
        if (val[arr[k][i]]>now) {
            tem_bigger.push_back(arr[k][i]);
        } else {
            tem_litter.push_back(arr[k][i]);
        }
    }
    if (tem_bigger.empty()) {
        if(now<maxx) {
            int tem=bfs(k, now);
            cnt++;
            save(tem, val[tem]);
        } else{
            cout<<cnt<<endl;
            return;
        }

    } else {
        int tee = tem_bigger[0];
        int te = val[tem_bigger[0]];
        for (int i = 1; i < tem_bigger.size(); i++) {
            if (val[tem_bigger[i]] < te) {
                tee = tem_bigger[i];
                te = val[tem_bigger[i]];
            }
        }
        cnt++;
        save(tee, te);
    }
}

int main() {
    int t=read();
    while (t--) {
        memset(arr, 0, sizeof arr);
        tem_bigger.clear();
        tem_litter.clear();
        n = read();
        for (int i = 1; i < n; i++) {
            int x,y;
            x = read(), y = read();
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            val[i] = read();
        }
        maxx=max(val + 1, val + 1 + n)-(val+1);
        for (int i = 1; i <= n; i++) {
            cnt=1;
            save(i, val[i]);
        }
    }
    return 0;
}
