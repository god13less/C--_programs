//
// Created by wang on 2021/1/20.
//

#include <iostream>

using namespace std;

int main(){
    int n,ans;
    char arr[500];
    while (cin >> n) {
        while (n--) {
            ans=0;
            cin>>arr;
            for (int i = 0; arr[i]!='\0'; i++) {
                if (arr[i] - '0' < 10) {
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}