//
// Created by wang on 2021/1/22.
//

#include <iostream>

using namespace std;

int main(){
    int n,m;
    int arr[41]={0,0,1,2};
    for (int i = 4; i < 41; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin>>m;
            cout<<arr[m]<<endl;
        }
    }

    return 0;
}
