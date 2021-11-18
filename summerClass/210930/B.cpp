//
// Created by wang on 2021/9/30.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
inline int read(){
    int x=0;char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
int n,m,k,t;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        bool flag = false;
        if (n == 1 && m == 0 && k == 0) {
            flag = true;
        } else if (m == n - 1 && k - 1 > 1) {
            flag = true;
        } else if (m > n - 1 && m <= (n * (n - 1) / 2)) {
            if (m - n + 2 <= k - 1) {
                flag = true;
            } else {
                flag = false;
            }
        } else {
            flag = false;
        }
        if (flag) {
            cout << "YES"<<endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

