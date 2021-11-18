//
// Created by wang on 2021/1/20.
//

#include <iostream>

using namespace std;

int main() {
    int n, m,index,tem,bo;
    int arr[101];
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            return 0;
        }
        index=0;
        bo=0;
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        for (int i = 0; i < n; i++) {
            if (m>arr[i]) {
                index=i+1;
            }
        }
        for (int i = index; i < n+1; i++) {
            tem = arr[i];
            arr[i]=m;
            m=tem;
        }
        for (int i = 0; i < n + 1; i++) {
            if (bo) {
                cout<<" ";
            }
            cout<<arr[i];
            bo=1;
        }
        cout<<endl;
    }

    return 0;
}