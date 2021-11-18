//
// Created by wang on 2021/2/6.
//

#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

char str1[51], str2[51];

int f1(char str1[], char str2[]) {//单选
    int ans = 0, len = strlen(str1);
    char s1[51];
    for (int i = 0; i < len; i++) {
        s1[i] = str1[i];
    }
    for (int i = 0; i < len; i++) {
        if (s1[i] != str2[i]) {
            ans++;
        }
    }
    return ans;
}

int f2(char str1[], char str2[]) {//全选加单选
    int ans = 1, len = strlen(str1);
    char s1[51];
    for (int i = 0; i < len; i++) {
        s1[i] = str1[i];
    }
    for (int i = 0; i < len; i++) {
        s1[i] = '1';
    }
    for (int i = 0; i < len; i++) {
        if (s1[i] != str2[i]) {
            ans++;
        }
    }
    return ans;
}

int f3(char str1[], char str2[]) {//全选加反选加单选
    int ans = 2, len = strlen(str1);
    char s1[51];
    for (int i = 0; i < len; i++) {
        s1[i] = str1[i];
    }
    for (int i = 0; i < len; i++) {
        s1[i] = '0';
    }
    for (int i = 0; i < len; i++) {
        if (s1[i] != str2[i]) {
            ans++;
        }
    }
    return ans;
}

int f4(char str1[], char str2[]) {//反选加单选
    int ans = 1, len = strlen(str1);
    char s1[51];
    for (int i = 0; i < len; i++) {
        s1[i] = str1[i];
    }
    for (int i = 0; i < len; i++) {
        if (s1[i] == '0') {
            s1[i] = '1';
        } else {
            s1[i] = '0';
        }
    }
    for (int i = 0; i < len; i++) {
        if (s1[i] != str2[i]) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int n, ans[3], a;
    while (cin >> n >> str1 >> str2) {
        //cout<<n<<' '<<str1<<" "<<str2<<endl<<endl;
        ans[0] = f1(str1, str2);
        ans[1] = f2(str1, str2);
        ans[2] = f3(str1, str2);
        a = f4(str1, str2);
        for (int i = 0; i < 3; i++) {
            if (a > ans[i]) {
                a = ans[i];
            }
        }
        cout << a << endl;

    }
    return 0;
}