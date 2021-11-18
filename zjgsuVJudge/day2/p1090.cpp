//
// Created by wang on 2021/1/30.
//

#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    ll n,tem,ans;
    priority_queue<ll,vector<ll>,greater<ll> > que;
    while (cin >> n) {
        ans=0;
        for (int i = 0; i < n; i++) {
            cin>>tem;
            que.push(tem);
        }
        while (que.size() > 1) {
            tem=que.top();
            que.pop();
            tem+=que.top();
            que.pop();
            que.push(tem);
            ans+=tem;
        }
        cout<<ans<<endl;
        que.pop();
    }

    return 0;
}
