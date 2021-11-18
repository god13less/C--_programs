//
// Created by wang on 2021/1/17.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    double array[100];
    int num[3];
    while (cin >> n && n != 0) {
        for (int i = 0; i < 3; i++) {
            num[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }

        for (int i = 0; i < n; i++) {
            if (array[i] > 0) {
                num[2]++;
            } else if (array[i] == 0) {
                num[1]++;
            } else {
                num[0]++;
            }
        }

        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;
    }

    return 0;
}