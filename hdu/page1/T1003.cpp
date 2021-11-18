//
// Created by wang on 2021/8/12.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;

ll t, n;
ll arr[100050], sum[100050];

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ':' << endl;
        cin >> n;
        memset(arr, 0, sizeof arr);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        int start=0,fst=0,lst=0,maxSum;
        maxSum=arr[0];
        for (int j = 1; j < n; j++) {
            if (arr[j - 1] >= 0) {
                arr[j] = arr[j - 1] + arr[j];
            } else {
                start = j;
            }

            if (arr[j] > maxSum) {
                maxSum = arr[j];
                fst=start;
                lst = j;
            }

        }
        cout << maxSum << " " << fst+1 << " " << lst+1 << endl;
        if (i != t) {
            cout << endl;
        }
    }
    return 0;
}