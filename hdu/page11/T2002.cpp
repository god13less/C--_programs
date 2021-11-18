//
// Created by wang on 2021/1/16.
//

#include <iostream>
#include <stdio.h>

#define PI 3.1415927
using namespace std;

int main() {
    double r,V;
    while (cin >> r) {
        V=4*PI*r*r*r/3;
        printf("%.3f",V);
        cout<<endl;
    }
    return 0;
}
