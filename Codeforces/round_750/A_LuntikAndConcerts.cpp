//
// Created by wang on 2021/10/24.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;



int t, a, b, c;

void save() {
    int tot=0;
    if (c % 2) {
        tot += 3;
    }
    if (b != 0) {
        if (tot == 0) {
            if (b % 2) {
                tot = 2;
            }
        } else {
            tot = 1;
        }

    }
    if (a % 2) {
        tot --;
    }
    cout<<tot<<endl;
}

int main() {
    cin>>t;
    while (t--) {
        cin >> a >> b >> c;
        save();
    }

    return 0;
}
