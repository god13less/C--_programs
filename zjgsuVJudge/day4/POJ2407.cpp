//
// Created by wang on 2021/2/5.
//

#include <iostream>

using namespace std;
typedef long long ll;

int phi(int n) {
    int rea = n;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            rea = rea - rea / i;
            do
                n /= i;
            while (n % i == 0);
        }
    if (n > 1)
        rea = rea - rea / n;
    return rea;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << phi(n) << endl;
    }
    return 0;
}
