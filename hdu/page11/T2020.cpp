//
// Created by wang on 2021/1/20.
//

#include <iostream>

using namespace std;

int main() {
    int n, tem, bo;
    int arr[100];
    while (cin >> n) {
        //input
        if (n == 0) {
            return 0;
        }
        bo = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        //sort
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (abs(arr[j + 1]) > abs(arr[j])) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        //output
        for (int i = 0; i < n; i++) {
            if (bo) {
                cout << " ";
            }
            cout << arr[i];
            bo = 1;
        }
        cout << endl;
    }

    return 0;
}
