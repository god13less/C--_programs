//
// Created by wang on 2021/1/22.
//

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double area(int n, int arr[200]);

double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3);

int main() {
    int n;
    int arr[200];
    double S;
    while (cin >> n) {
        if (n == 0) {
            return 0;
        }
        for (int i = 0; i < 2 * n; i++) {
            cin >> arr[i];
        }
        S = area(n, arr);
        cout<<fixed<<setprecision(1)<<S<<endl;
    }

    return 0;
}

double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    double a, b, c, p;
    a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double area(int n, int arr[200]) {
    int x1, y1, x2, y2, x3, y3;
    double S = 0;
    x1 = arr[0];
    y1 = arr[1];
    for (int i = 0; i < n - 2; i++) {
        x2=arr[2*i+2];
        y2=arr[2*i+3];
        x3=arr[2*i+4];
        y3=arr[2*i+5];
        S += triangleArea(x1, y1, x2, y2, x3, y3);
    }
    return S;
}
