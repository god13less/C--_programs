//
// Created by wang on 2021/7/10.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
queue<ll> que;
stack<ll> sta;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t,n,tem;
    string str;
    cin>>t;
    while (t--) {
        cin>>n>>str;
        if (str == "FIFO") {
            for (int i = 1; i <= n; i++) {
                cin>>str;
                if (str=="IN"){
                    cin>>tem;
                    que.push(tem);
                } else {
                    if (!que.empty()) {
                        cout<<que.front()<<endl;
                        que.pop();
                    } else {
                        cout<<"None"<<endl;
                    }
                }
            }
            while(!que.empty()) {
                que.pop();
            }
        } else {
            for (int i = 1; i <= n; i++) {
                cin>>str;
                if (str=="IN"){
                    cin>>tem;
                    sta.push(tem);
                } else {
                    if (!sta.empty()) {
                        cout<<sta.top()<<endl;
                        sta.pop();
                    } else {
                        cout<<"None"<<endl;
                    }
                }
            }
            while (!sta.empty()) {
                sta.pop();
            }
        }
    }

    return 0;
}