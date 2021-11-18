//
// Created by wang on 2021/9/29.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
string str;
int n, m,l,r;
char c1, c2;

int main() {
    cin >> n >> m;
    cin>>str;
    for (int i = 1; i <= m; i++) {
        cin>>l>>r>>c1>>c2;
        for (int j = l-1; j <= r-1; j++) {
            if (str[j] == c1) {
                str[j] = c2;
            }
        }
    }
    cout<<str<<endl;
    return 0;
}