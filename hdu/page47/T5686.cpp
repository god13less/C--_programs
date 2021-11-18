//
// Created by wang on 2021/7/9.
//

#include <bits\stdc++.h>

#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;

//高精度加法
//只能是两个正数相加
string add(string str1, string str2) {//高精度加法
    string str;
    int len1 = str1.length();
    int len2 = str2.length();
//前面补0，弄成长度相同
    if (len1 < len2) {
        for (int i = 1; i <= len2 - len1; i++) {
            str1 = "0" + str1;
        }
    } else {
        for (int i = 1; i <= len1 - len2; i++) {
            str2 = "0" + str2;
        }
    }
    len1 = str1.length();
    int cf = 0;
    int temp;
    for (int i = len1 - 1; i >= 0; i--) {
        temp = str1[i] - '0' + str2[i] - '0' + cf;
        cf = temp / 10;
        temp %= 10;
        str = char(temp + '0') + str;
    }
    if (cf != 0) {
        str = char(cf + '0') + str;
    }
    return str;
}
string arr[203];

int main() {
    int str;
    arr[1] = "1";
    arr[2] = "2";
    for (int i = 3; i <= 202; i++) {
        arr[i] = add(arr[i - 1],arr[i - 2]);
    }
    while (cin >> str) {
        cout<<arr[str]<<endl;
    }

    return 0;
}