//
// Created by wang on 2021/1/19.
//

#include <iostream>

using namespace std;

int main(){
    int n,num;
    while (cin >> n) {
        num=1;
        for (int i = 1; i < n; i++) {
            num=(num+1)*2;
        }
        cout<<num<<endl;
    }
    return 0;
}