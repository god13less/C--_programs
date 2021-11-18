//
// Created by wang on 2021/7/12.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
ll arr[1000050];
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t,n;
    cin>>t;
    while (t--) {
        cin>>n;
        memset(arr, 0, sizeof(arr));
        ll maxn=0,sum=0;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
            sum += arr[i];
            if (arr[i] > maxn) {
                maxn=arr[i];
            }
        }
        if (sum - maxn + 1 >= maxn) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}