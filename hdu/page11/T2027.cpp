//
// Created by wang on 2021/1/21.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, bo;
    string str;
    int num[5];
    while (cin >> n) {
        cin.ignore();
        bo = 0;
        for (int i = 0; i < n; i++) {
            for (int i = 0; i < 5; i++) {
                num[i] = 0;
            }
            getline(cin, str);
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == 'a') { num[0]++; }
                else if (str[i] == 'e') { num[1]++; }
                else if (str[i] == 'i') { num[2]++; }
                else if (str[i] == 'o') { num[3]++; }
                else if (str[i] == 'u') { num[4]++; }
            }
            if (bo) {
                cout << endl;
            }
            cout << "a:" << num[0] << endl;
            cout << "e:" << num[1] << endl;
            cout << "i:" << num[2] << endl;
            cout << "o:" << num[3] << endl;
            cout << "u:" << num[4] << endl;
            bo = 1;
        }
    }

    return 0;
}
