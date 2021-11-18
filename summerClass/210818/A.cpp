//
// Created by wang on 2021/8/18.
//

#include <iostream>
#include <cstring>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

string S;
int ans[maxn];


int main() {
    cin>>S;
    memset(ans, 0, sizeof ans);
    int n = S.length();
    S += 'R';
    int indexL,indexR;
    int numL=0,numR=1;
    for (int i = 1; i < n; i++) {
        if (S[i - 1] == 'R' && S[i] == 'L') {
            indexL = i;
            indexR = i-1;
        }
        if (S[i] == 'R') {
            numR++;
        } else if (S[i] == 'L') {
            numL++;
        }
        if (S[i] == 'L' && S[i + 1] == 'R') {
            int divide = abs(numL - numR);
            int sum = numL + numR;
            if (divide % 2 == 0) {
                ans[indexL] = ans[indexR] = sum / 2;
            } else if (numL % 2 != 0 && numR % 2 == 0) {
                ans[indexL] = ans[indexR] = sum / 2;
                if (numL < numR) {
                    ans[indexL]++;
                }
                if (numL > numR) {
                    ans[indexL]++;
                }
            } else if (numL % 2 == 0 && numR % 2 != 0) {
                ans[indexL] = ans[indexR] = sum / 2;
                if (numL < numR) {
                    ans[indexR]++;
                }
                if (numL > numR) {
                    ans[indexR]++;
                }
            }
            numL = 0, numR = 0;
        }

    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}