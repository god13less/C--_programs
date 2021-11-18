//
// Created by wang on 2021/7/6.
//

#include <iostream>
#include <vector>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
ll list[22];

int main() {
    ll n,t;
    cin >> t;
    while (t--) {
        vector<ll> vect;
        cin>>n;
        list[0]=0;
        for (int i = 1; i <=n ; i++) {
            cin >> list[i];
        }
        for (int i = 1; i <=n ; i++) {
            for (int j = 0; j < list[i] - list[i - 1]; j++) {
                vect.push_back(1);
            }
            vect.push_back(0);
        }
        for (int i = 0; i < vect.size(); i++) {
            ll num = 1;
            if (!vect[i]) {
                for (int j = i-1; j >=0 ; j--) {
                    if (vect[j] == -1) {
                        num++;
                    }
                    if (vect[j]==1) {
                        vect[j]=-1;
                        break;
                    }
                }
                cout<<num;
                if (i != vect.size() - 1) {
                    cout << ' ';
                }
            }
        }
        cout<<endl;
    }

    return 0;
}