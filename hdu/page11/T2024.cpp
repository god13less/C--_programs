//
// Created by wang on 2021/1/21.
//

#include <iostream>
#include <string>

using namespace std;

bool isLegal(string s) {
    if (s[0] <= '9' && s[0] >= '0') return false;
    for (int i = 0; i < s.length(); i++) {
        if (!(s[i] == '_' || s[i] <= '9' && s[i] >= '0' || s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A')) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    string str;
    while (cin >> n) {
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin,str);
            if (isLegal(str)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}
