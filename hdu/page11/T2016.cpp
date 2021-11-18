//
// Created by wang on 2021/1/19.
//

#include <iostream>

using namespace std;

int main() {
    int n, index, tem,bo;
    int arr[100];
    while (cin >> n ) {
        if (n == 0) {
            return 0;
        }
        index=0;
        bo=0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        tem = arr[0];
        for (int i = 0; i < n; i++) {
            if (tem > arr[i]) {
                tem = arr[i];
                index = i;
            }
        }
        swap(arr[0], arr[index]);
        for (int i = 0; i < n; i++) {
            if (bo) {
                cout<<" ";
            }
            cout << arr[i];
            bo=1;
        }
        cout << endl;
    }

    return 0;
}
