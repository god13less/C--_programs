//
// Created by wang on 2021/1/19.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, temMax, temMin,all;
    double ans;
    double score[100];
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> score[i];
        }
        all=0;
        temMax = score[0];
        temMin = score[0];

        for (int i = 0; i < n; i++) {
            if (temMax < score[i]) {
                temMax = score[i];
            }
            if (temMin > score[i]) {
                temMin = score[i];
            }
            all += score[i];
        }
        ans=(all-temMin-temMax)/(n-2.0);
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }

    return 0;
}
