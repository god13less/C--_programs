//
// Created by wang on 2021/1/22.
//

#include <iostream>

using namespace std;

int main() {
    int n,k,bo;
    int arr[30][30];
    for (int i = 0; i < 30; i++) {
        arr[i][0] = 1;
    }
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j < 30; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 1; i < 30; i++) {
        for (int j = 1; j < i+1; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    while (cin >> n) {
        k=1;
        for (int i = 0; i < n; i++) {
            bo=0;
            for (int j = 0; j < k; j++) {
                if (bo) {
                    cout<<" ";
                }
                cout<<arr[i][j];
                bo=1;
            }
            cout<<endl;
            k++;
        }
        cout<<endl;
    }

    return 0;
}
