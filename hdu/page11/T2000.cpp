//
// Created by wang on 2021/1/16.
//

#include<iostream>

using namespace std;

int main() {
    char cha[3];
    char tem;
    while (cin >> cha[0] >> cha[1] >> cha[2]) {
        for (int i = 0; i < 3; i++) {
            for (int j = i+1; j < 3; j++) {
                if (cha[i] > cha[j]) {
                    tem = cha[j];
                    cha[j] = cha[i];
                    cha[i] = tem;
                }
            }
        }

        cout<<cha[0]<<" "<<cha[1]<<" "<<cha[2]<<endl;
    }

    return 0;
}

