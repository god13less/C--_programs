//
// Created by wang on 2021/1/26.
//

#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,bo,index;
    string str;
    while (cin >> n >> str) {
        index=0;
        while (1) {
            bo=1;
            for (int i = index; i < str.length(); i++) {
                if (str.substr(i, 3) == "fox") {
                    str=str.substr(0,i)+str.substr(i+3);
                    if (i > 5) {
                        index=i-2;
                    } else {
                        index=0;
                    }
                    bo=0;
                    break;
                }
            }
            if (bo) {
                break;
            }
        }
        cout<<str.length()<<endl;
    }

    return 0;
}
