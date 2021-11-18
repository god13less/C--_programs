//
// Created by wang on 2021/1/23.
//

#include <iostream>

using namespace std;

bool isPassword(char pas[16]);

int main() {
    int n;
    char password[16];
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> password;
            if (isPassword(password)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}

bool isPassword(char pas[16]) {
    int len, tem;
    int bo[4];
    for (int i = 0; pas[i] != '\0'; i++) {
        len = i + 1;
    }
    if (len < 8 || len > 16) {
        return false;
    }
    for (int i = 0; i < 4; i++) {
        bo[i]=0;
    }
    for (int i = 0; i < len; i++) {
        if (pas[i] >= 65 && pas[i] <= 90) {
            bo[0] = 1;
        } else if (pas[i] >= 97 && pas[i] <= 122) {
            bo[1] = 1;
        } else if (pas[i] >= 48 && pas[i] <= 57) {
            bo[2] = 1;
        } else if (pas[i] == 126 || pas[i] == 33 || pas[i] == 40 || pas[i] == 35 || pas[i] == 36 || pas[i] == 37 ||
                   pas[i] == 94) {
            bo[3] = 1;
        }
    }
    tem = 0;
    for (int i = 0; i < 4; i++) {
        if (bo[i]) {
            tem++;
        }
    }
    if (tem >= 3) {
        return true;
    } else {
        return false;
    }

}