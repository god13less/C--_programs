//
// Created by wang on 2021/1/22.
//

#include <iostream>

using namespace std;

int main() {
    int n, ans;
    int arr[100][2];
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> arr[i][j];
            }
        }
        //key point
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <n-i-1 ; j++) {
                if (arr[j][1] > arr[j + 1][1]) {
                    swap(arr[j][0],arr[j+1][0]);
                    swap(arr[j][1],arr[j+1][1]);
                }
            }
        }
        int x ,y;
        for ( x = 1, y=0,ans=1; x < n; x++) {
            if (arr[x][0] >= arr[y][1]) {
                ans++;
                y=x;
            }
        }


        cout << ans << endl;
    }
    return 0;
}
