//
// Created by wang on 2021/1/19.
//

#include <iostream>

using namespace std;

int main() {
    int n, m, times, x,bo;
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = 2 * (i + 1);
    }
    while (cin >> n >> m) {
        times = n / m;
        int all[100];
        bo=0;
        for (int i = 0; i < times + 1; i++) {
            all[i] = 0;
        }

        for (int i = 0; i < times; i++) {
            for (int j = 0; j < m; j++) {
                all[i] += arr[j + m * i];
                x = j + m * i + 1;
            }
        }
        for (int i = 0; i < times; i++) {
            if (bo) {
                cout<<" ";
            }
            cout << all[i] / m;
            bo=1;
        }

        if (n % m) {
            for (int i = x; i < n; i++) {
                all[times] += arr[i];
            }
            cout <<" "<< all[times] / (n % m) << endl;
        } else {
            cout << endl;
        }
    }

    return 0;
}
