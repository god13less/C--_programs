//
// Created by wang on 2021/1/17.
//

#include <iostream>

using namespace std;

int main() {
    int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    char a, b;
    while (cin >> year && cin.get(a) && cin >> month && cin.get(b) && cin >> day) {
        int all = 0;

        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            m[2] = 29;
        }

        while (--month) {
            all += m[month];
        }

        all += day;
        cout << all << endl;
        m[2] = 28;
    }

    return 0;
}