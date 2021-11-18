//
// Created by wang on 2021/10/17.
//
#include <iostream>
#define inf 0x3f3f3f3f
#define maxn 100000000

using namespace std;
typedef long long ll;

int t;
double n;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        double ans = maxn / n;
        if (abs(ans-int(ans))<1e-6){
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
        }
    }

    return 0;
}
