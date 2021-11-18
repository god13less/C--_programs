//
// Created by wang on 2021/7/6.
//

#include <iostream>
#include <map>
#include <stack>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
struct node{
    ll x,y;
} no,tem;

stack<node> sta;
map<char,node> mp;

int main() {
    ll n,a,b;
    char c;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>c>>a>>b;
        no.x=a;
        no.y=b;
        mp[c]=no;
    }
    string str;
    while (cin >> str) {
        ll ans=0;
        if (str.length() == 1) {
            cout<<0<<endl;
        } else {
            bool bo= true;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == '(') {
                    continue;
                }else if (str[i] == ')') {
                    no=sta.top();
                    sta.pop();
                    tem=sta.top();
                    sta.pop();
                    if (tem.y != no.x) {
                        cout<<"error"<<endl;
                        bo= false;
                        break;
                    } else {
                        ans+=tem.x*tem.y*no.y;
                        tem.y=no.y;
                        sta.push(tem);
                    }
                } else {
                    sta.push(mp[str[i]]);
                }
            }
            if (bo) {
                cout<<ans<<endl;
            }
            while (!sta.empty()) {
                sta.pop();
            }
        }
    }

    return 0;
}