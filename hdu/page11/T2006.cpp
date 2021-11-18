//
// Created by wang on 2021/1/17.
//

#include <iostream>

using namespace std;

int main() {
    int num;
    long ans;
    int n[100000];
    while (cin >> num) {
        for (int i = 0; i < num; i++) {
            cin >> n[i];
        }
        for (int i = 0; i < num; i++) {
            if (n[i] % 2 == 1) {
                ans = n[i];
                n[i]=2;
                break;
            }
        }
        for (int i = 0; i < num; i++) {
            if (n[i] % 2 == 1) {
                ans = ans * n[i];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
