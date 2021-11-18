//
// Created by wang on 2021/5/21.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll balls,sore1,sore2;
        cin>>balls>>sore1>>sore2;
        if (balls > 6) {
            sore1+=(balls-6)*8+27;
        } else{
            int j=7;
            while (balls--) {
                sore1 += j;
                j--;
            }
        }

        if (sore1 >= sore2) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
