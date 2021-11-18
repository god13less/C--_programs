//
// Created by wang on 2021/1/21.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m, num, tem, bo, all;
    double rowAverage[50], columnAverage[5];
    int score[50][5];
    while (cin >> n >> m) {
        //input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> score[i][j];
            }
        }
        //count rowAverage
        tem = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tem += score[i][j];
            }
            rowAverage[i] = tem / (double) m;
            tem = 0;
        }
        //count columnAverage
        tem = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tem += score[j][i];
            }
            columnAverage[i] = tem / (double) n;
            tem = 0;
        }
        //count the number of student who is up to the mustard
        num = 0;
        for (int i = 0; i < n; i++) {
            all = 0;
            for (int j = 0; j < m; j++) {
                if (score[i][j] >= columnAverage[j]) {
                    all++;
                }
            }
            if (all == m) {
                num++;
            }
        }
        //output
        bo = 0;
        for (int i = 0; i < n; i++) {
            if (bo) {
                cout << " ";
            }
            cout << fixed << setprecision(2) << rowAverage[i];
            bo = 1;
        }
        cout << endl;

        bo = 0;
        for (int i = 0; i < m; i++) {
            if (bo) {
                cout << " ";
            }
            cout << fixed << setprecision(2) << columnAverage[i];
            bo = 1;
        }
        cout << endl;

        cout << num << endl << endl;
    }

    return 0;
}
