//
// Created by wang on 2021/1/19.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x,y,n,bo;
    while (cin >> x >> y ) {
        bo=0;
        if (x == 0 && y == 0) {
            return 0;
        }
        for (int i = x; i <= y; i++) {
            n=i*i+i+41;
            for (int j = 2; j < sqrt(n); j++) {
                if (n % j == 0) {
                    bo=1;
                }
            }
        }
        if (bo) {
            cout<<"Sorry"<<endl;
        } else {
            cout<<"OK"<<endl;
        }
    }
    return 0;
}