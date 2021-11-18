//
// Created by wang on 2021/9/16.
//hdu1217

#include <bits\stdc++.h>

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
map<string, int> ma;
int n, m;
string str, str1;

double arr[40][40];


int main() {
    int o = 1;
    while (cin >> n && n != 0) {
        memset(arr, 0, sizeof 0);
        for (int i = 0; i < n; i++) {
            cin >> str;
            ma[str] = i;
            arr[i][i] = 1.0;
        }

        cin >> m;
        double tem;
        for (int i = 0; i < m; i++) {
            cin >> str;
            scanf("%lf", &tem);
            cin >> str1;
            arr[ma[str]][ma[str1]] = tem;
        }


        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = max(arr[i][k] * arr[k][j], arr[i][j]);
                }
            }
        }
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i][i] > 1.0) {
                cout<<"Case "<<o++<<": Yes"<<endl;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            cout<<"Case "<<o++<<": No"<<endl;
        }
    }


    return 0;
}