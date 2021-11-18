//
// Created by wang on 2021/7/6.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 1 << 30;

struct people {
    ll num;
    ll b;
    friend bool operator < (const people &a,const people b)
    {
        return a.b<b.b||(a.b==b.b&&a.num>b.num);
    }
} peo;


priority_queue<people> doc[4];

int main(){
    ll n,a,b;
    string str;
    while (cin>>n) {
        ll num=1;
        while (n--) {
            cin >> str;
            if (str == "IN") {
                cin >> a >> b;
                peo.num = num++;
                peo.b = b;
                doc[a].push(peo);
            } else {
                cin >> a;
                if (doc[a].empty()) {
                    cout << "EMPTY" << endl;
                } else {
                    cout << doc[a].top().num << endl;
                    doc[a].pop();
                }
            }
        }
        for (int i = 1; i <= 3; i++) {
            while (!doc[i].empty()) {
                doc[i].pop();
            }
        }
    }

    return 0;
}
