//
// Created by wang on 2021/1/24.
//

#include <iostream>

using namespace std;

int main(){
    unsigned long long arr[41]={0,3,8};
    int n;
    for (int i = 3; i < 41; i++) {
        arr[i]=2*arr[i-1]+2*arr[i-2];
    }
    while (cin >> n) {
        cout<<arr[n]<<endl;
    }
    return 0;
}
