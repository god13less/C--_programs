//
// Created by wang on 2021/1/21.
//

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main(){
    int n;
    string str;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin>>str;
            if (isPalindrome(str)) {
                cout<<"yes"<<endl;
            } else {
                cout<<"no"<<endl;
            }
        }
    }

    return 0;
}

bool isPalindrome(string str){
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}
