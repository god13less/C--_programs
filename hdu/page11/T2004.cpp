//
// Created by wang on 2021/1/17.
//

#include <iostream>

using namespace std;

int main() {
    int score;
    while (cin >> score) {
        if (score >= 0 && score <= 59) {
            cout << "E" << endl;
            continue;
        } else if (score >= 60 && score <= 69) {
            cout << "D" << endl;
            continue;
        } else if (score >= 70 && score <= 79) {
            cout<<"C"<<endl;
            continue;
        } else if (score >= 80 && score <= 89) {
            cout << "B" << endl;
            continue;
        } else if (score >= 90 && score <= 100) {
            cout<<"A"<<endl;
            continue;
        } else {
            cout<<"Score is error!"<<endl;
        }
    }
    return 0;
}
