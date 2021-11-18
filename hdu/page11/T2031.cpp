//
// Created by wang on 2021/1/21.
//

#include <iostream>

using namespace std;

int main() {
    int n, r, tem;
    int arr[100000];
    while (cin >> n >> r) {
        tem = 0;
        if (n < 0) {
            n = -n;
            cout << "-";
        }
        for (int i = 0; n != 0; i++) {
            arr[i] = n % r;
            n=n/r;
            tem++;
        }
        for (int i = tem-1; i >=0; i--) {
            if (arr[i] <= 9) {
                cout << arr[i];
            } else if (arr[i]==10) {cout<<"A";}
            else if (arr[i]==11) {cout<<"B";}
            else if (arr[i]==12) {cout<<"C";}
            else if (arr[i]==13) {cout<<"D";}
            else if (arr[i]==14) {cout<<"E";}
            else if (arr[i]==15) {cout<<"F";}
        }
        cout<<endl;
    }

    return 0;
}
