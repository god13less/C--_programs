//
// Created by wang on 2021/1/21.
//

#include <iostream>

using namespace std;

int main() {
    int n, ans, bo, j, num;
    int arr[100];
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        bo = 1;
        j = 1;
        while (bo) {
            ans = j * arr[0];
            num = 0;
            for (int i = 0; i < n; i++) {
                if (ans % arr[i] == 0) {
                    num++;
                }
            }
            if (num == n) {
                bo = 0;
            } else {
                j++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
