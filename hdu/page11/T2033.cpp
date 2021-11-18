//
// Created by wang on 2021/1/22.
//

#include <iostream>

using namespace std;

int main() {
    int n, bo;
    int a[3], b[3], c[3];
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[j];
            }
            for (int j = 0; j < 3; j++) {
                cin >> b[j];
            }
            for (int j = 0; j < 3; j++) {
                c[j] = a[j] + b[j];
            }
            for (int j = 2; j >= 1; j--) {
                if (c[j] >= 60) {
                    c[j - 1]++;
                    c[j] = c[j] % 60;
                }
            }
            bo=0;
            for (int j = 0; j < 3; j++) {
                if (bo) {
                    cout<<" ";
                }
                cout << c[j];
                bo=1;
            }
            cout<<endl;
        }
    }

    return 0;
}
