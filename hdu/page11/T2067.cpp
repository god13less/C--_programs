//
// Created by wang on 2021/5/25.
//
//calculate
#include <bits/stdc++.h>

using namespace std;
const int N = 40;
typedef long long ll;
ll C[N];

// // 利用递推式计算,long long 34项就溢出了
// void calculate(){
//     C[0] = 1;
//     for (int i = 1; i < N; i++){
//         C[i] = (4 * i - 2) * C[i - 1] / (i + 1);
//     }
// }

// 利用前面项的乘积和累加和,36项开始溢出
void calculate() {
    C[0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            C[i] += C[j] * C[i - 1 - j];
        }
    }
}

int main() {
    calculate();
    // for (int i = 0; i < N; i++)
    //     printf("%-3d:%lld\n",i,C[i]);
    int cnt = 1;
    int n;
    while (cin >> n && n != -1) {
        cout << cnt << ' ' << n << ' ' << C[n] * 2 << endl;
        ++cnt;
    }
    return 0;
}
