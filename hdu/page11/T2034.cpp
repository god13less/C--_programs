//
// Created by wang on 2021/1/22.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, bo, k;
    int A[100], B[100];
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            return 0;
        }
        int C[100];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> B[i];
        }
        k = 0;
        for (int i = 0; i < n; i++) {
            bo = 1;
            for (int j = 0; j < m; j++) {
                if (A[i] == B[j]) {
                    bo = 0;
                }
            }
            if (bo) {
                C[k] = A[i];
                k++;
            }
        }
        if (k == 0) {
            cout << "NULL" << endl;
        } else {
            sort(C,C+k);
            for (int i = 0; i < k; i++) {
                cout<<C[i]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
