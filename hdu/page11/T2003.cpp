//
// Created by wang on 2021/1/16.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a;
    cout << setprecision(2);
    cout.setf(ios::fixed, ios::floatfield);
    while (cin >> a) {
        a=abs(a);
        cout<<a<<endl;
    }
    return 0;
}