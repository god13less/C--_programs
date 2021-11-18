//
// Created by wang on 2021/4/28.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll linecut(ll m){
    ll a=0;
    for (int i = 1; i <= m-2; i++) {
        a+=i;
    }
    return a+2*m;
}

int main(){
    int n;
    ll m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin>>m;
        cout<<linecut(2*m)-2*m<<endl;
    }
    return 0;
}