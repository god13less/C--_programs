//
// Created by wang on 2021/1/23.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    long long arr[51]={0,3,6,6};
    for (int i = 4; i < 51; i++) {
        arr[i]=arr[i-1]+arr[i-2]*2;
    }

    while (cin >> n) {
        cout<<arr[n]<<endl;
    }
    return 0;
}
