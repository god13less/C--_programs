//
// Created by wang on 2021/1/21.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        if (str[0] >= 97 && str[0] <= 122) {
            str[0] = str[0] - 32;
        }
        for (int i = 1; i < str.length(); i++) {
            if (str[i] == 32) {
                str[i + 1] -= 32;
            }
        }
        cout << str << endl;
    }

    return 0;
}
