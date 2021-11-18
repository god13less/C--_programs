//
// Created by wang on 2021/1/30.
//

#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    int n;
    ll a,b;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin>>a>>b;
            cout<<(a%100+b%100)%100<<endl;
        }
    }
    return 0;
}
