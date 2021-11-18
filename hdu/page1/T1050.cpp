//
// Created by wang on 2021/7/14.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
struct node {
    ll start, end, len;

    friend bool operator<(const node &a, const node &b) {
        if (a.len == b.len) {
            return a.start < b.start;
        }
        return a.len < b.len;
    }
}arr[250];
int vis[250];

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t,n,tem1,tem2;
    cin>>t;
    while (t--) {
        memset(arr,0,sizeof arr);
        cin>>n;
        for (int i = 1; i <= n; i++) {
            cin >> tem1>>tem2;
            if (tem1 > tem2) {
                ll te=tem2;
                tem2=tem1;
                tem1=te;
            }
            arr[i].start=tem1;
            arr[i].end=tem2;
            arr[i].len = tem2-tem1;
        }
        sort(arr + 1, arr + n + 1);

    }
    return 0;
}