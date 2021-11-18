//
// Created by wang on 2021/4/29.
//

#include <iostream>
#include <iomanip>

using namespace std;

void change(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}
int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    double minx, maxx, miny, maxy;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        if(x1 > x2)
            change(x1, x2);
        if(x3 > x4)
            change(x3, x4);
        if(y1 > y2)
            change(y1, y2);
        if (y3 > y4)
            change(y3, y4);
        minx = x1 > x3 ? x1 : x3;
        maxx = x2 < x4 ? x2 : x4;
        miny = y1 > y3 ? y1 : y3;
        maxy = y2 < y4 ? y2 : y4;
        if (minx > maxx || miny > maxy)
            cout << 0.00 << endl;
        else
            cout << fixed << setprecision(2) << (maxx - minx) * (maxy - miny) << endl;
    }
    return 0;
}

