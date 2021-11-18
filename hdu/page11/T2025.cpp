//
// Created by wang on 2021/1/21.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    char tem;
    while (getline(cin,str)) {
        tem=str[0];
        for (int i = 1; i < str.length(); i++) {
            if (tem < str[i]) {
                tem=str[i];
            }
        }
        for (int i = 0; i < str.length(); i++) {
            cout<<str[i];
            if (tem == str[i]) {
                cout<<"(max)";
            }
        }
        cout<<endl;
    }

    return 0;
}
