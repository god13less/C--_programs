//
// Created by wang on 2021/1/19.
//

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
    int n,m;
    double arr[1000];
    while (cin >> n >> m) {
        arr[0]=n;
        arr[999]=0;
        for (int i = 1; i < m; i++) {
            arr[i] = pow(arr[i - 1], 0.5);
        }

        for (int i = 0; i < m; i++) {
            arr[999]+=arr[i];
        }
        cout<<fixed<<setprecision(2)<<arr[999]<<endl;
    }

    return 0;
}