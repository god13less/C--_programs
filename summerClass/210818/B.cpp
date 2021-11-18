//
// Created by wang on 2021/8/19.
//

#include <iostream>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
ll myxor(ll a){
    if (a % 4 == 1) {
        return 1;
    } else if (a % 4 == 2) {
        return a + 1;
    } else if (a % 4 == 3) {
        return 0;
    } else {
        return a;
    }
}

int main() {
    ll a,b;
    cin >> a >> b;
    if (a == 0) {
        cout<<b<<endl;
    }else{
        cout<<((myxor(b))^(myxor(a-1)))<<endl;
    }
    return 0;
}