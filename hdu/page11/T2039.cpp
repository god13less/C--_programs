//
// Created by wang on 2021/1/22.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    double arr[3];
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> arr[j];
            }
            sort(arr,arr+3);
            if ((arr[0] + arr[1] > arr[2]) && (arr[2] - arr[0] < arr[1])) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }

        }
    }

    return 0;
}