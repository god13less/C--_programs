//
// Created by wang on 2021/1/22.
//

#include <iostream>

using namespace std;

int main(){
    int n, num;
    int sheep[31]={3};
    for (int i = 1; i < 31; i++) {
        sheep[i]=(sheep[i-1]-1)*2;
    }
    while (cin >> n) {
        for (int i = 0; i <n; i++) {
            cin>>num;
            cout<<sheep[num]<<endl;
        }
    }

    return 0;
}
