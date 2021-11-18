//
// Created by wang on 2021/1/21.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,num;
    string str;
    while (cin >> n) {
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, str);
            num=0;
            for (int j = 0; j < str.length(); j++) {
                if (str[j] < 0) {
                    num++;
                }
            }
            cout<<num/2<<endl;
        }

    }

    return 0;
}
