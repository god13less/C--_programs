//
// Created by wang on 2021/1/16.
//

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
    double x1, y1, x2, y2;
    double dist;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        dist=pow((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2),0.5);
        printf("%.2f", dist);
        cout<<endl;
    }
    return 0;
}
