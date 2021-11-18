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
struct node{
    ll deadline,score;

    friend bool operator<(const node &a, const node &b){
        if (a.score == b.score) {
            return a.deadline<b.deadline;
        }
        return a.score>b.score;
    }
} arr[2000];

int vis[2000];

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t,n;
    cin>>t;
    while (t--) {
        ll sum=0,sumall=0;
        memset(vis, 0, sizeof vis);
        cin>>n;
        for (int i = 1; i <= n; i++) {
            cin>>arr[i].deadline;
        }
        for (int i = 1; i <= n; i++) {
            cin>>arr[i].score;
            sumall+=arr[i].score;
        }
        sort(arr + 1, arr + n + 1);
        for (int i = 1; i <= n; i++) {
            if (!vis[arr[i].deadline]) {
                sum+=arr[i].score;
                vis[arr[i].deadline]=1;
            } else {
                for (int j = arr[i].deadline-1; j >= 1; j--) {
                    if (!vis[j]) {
                        sum+=arr[i].score;
                        vis[j]=1;
                        break;
                    }
                }
            }
        }
        cout<<sumall-sum<<endl;
    }
    return 0;
}