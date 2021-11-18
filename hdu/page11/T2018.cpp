//
// Created by wang on 2021/1/20.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    int arr[55], all[55];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    all[0] = 2;
    for (int i = 3; i < 55; i++) {
        arr[i] = arr[i - 1] + arr[i - 3];
    }
    for (int i = 1; i < 55; i++) {
        all[i] = all[i - 1] + arr[i];
    }

    while (cin >> n && n != 0) {
        if (n == 1) {
            cout << arr[0] << endl;
        } else {
            cout << all[n - 2] << endl;
        }
    }

    return 0;
}
