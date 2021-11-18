//
// Created by wang on 2021/10/27.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;

int n;
int main() {
    cin >> n;
    int tem = n % 10;
    n -= tem;
    if (tem > 5) {
        n += 10;
    }
    cout<<n<<endl;
    return 0;
}