//
// Created by wang on 2021/1/23.
//

#include <iostream>

using namespace std;

int main(){
    int n,a,b;
    long long arr[50]={1,2};
    for (int i = 2; i < 50; i++) {
        arr[i]=arr[i-1]+arr[i-2];
    }
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin>>a>>b;
            cout<<arr[b-a-1]<<endl;
        }
    }

    return 0;
}
