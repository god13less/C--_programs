//
// Created by wang on 2021/4/28.
//

#include <iostream>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < m+2; i++) {
            if (i == 0 || i == m+1) {
                cout << "+";
                for (int j = 0; j < n; j++) {
                    cout << "-";
                }
                cout << "+" << endl;
            } else {
                cout << "|";
                for (int j = 0; j < n; j++) {
                    cout << " ";
                }
                cout << "|" << endl;
            }
        }
        cout<<endl;
    }

    return 0;
}
