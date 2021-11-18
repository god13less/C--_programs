//
// Created by wang on 2021/1/19.
//

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n, m, bo;
    int arr[1000];
    while (cin >> m >> n) {
        bo = 0;
        for (int i = 0; i < n - m + 1; i++) {
            arr[i] = m + i;
        }

        for (int i = 0; i < n - m + 1; i++) {
            if (arr[i] == pow(arr[i] / 100, 3) + pow(arr[i] % 100 / 10, 3) + pow(arr[i] % 10, 3)) {
                if (bo == 1) {
                    cout<<" ";
                }
                cout << arr[i];
                bo = 1;
            }
        }

        if (bo == 0) {
            cout << "no";
        }
        cout << endl;
    }

    return 0;
}