//
// Created by wang on 2021/1/21.
//

#include <iostream>

using namespace std;

int main() {
    int n, ans;
    int arr[100], num[100];
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }

        //initialize
        for (int i = 0; i < n; i++) {
            num[i] = 0;
        }
        ans = 0;

        //input
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        //main
        for (int i = 0; i < n; i++) {
            num[i] = arr[i] / 100 + (arr[i] % 100) / 50 + (arr[i] % 50) / 10 + (arr[i] % 10) / 5 + (arr[i] % 5) / 2 +
                     (arr[i] % 5) % 2;
        }
        for (int i = 0; i < n; i++) {
            ans += num[i];
        }

        //output
        cout << ans << endl;
    }

    return 0;
}