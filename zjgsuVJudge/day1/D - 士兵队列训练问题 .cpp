//
// Created by wang on 2021/1/26.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    queue<int> que1, tem;
    int n, num, k, p, len;
    int ans[3];
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> num;
            for (int j = 1; j <= num; j++) {
                que1.push(j);
            }
            k = 0;
            while (que1.size() > 3) {
                p = 1;
                len = que1.size();
                for (int j = 0; j < len; j++) {
                    if (p != 2 + k) {
                        p++;
                        tem.push(que1.front());
                        que1.pop();
                    } else {
                        que1.pop();
                        p = 1;
                    }
                }
                k = !k;
                while (!tem.empty()) {
                    que1.push(tem.front());
                    tem.pop();
                }
            }
            len=que1.size();
            k = 0;
            while (!que1.empty()) {
                ans[k++] = que1.front();
                que1.pop();
            }
            sort(ans, ans + len);
            k=0;
            for (int j = 0; j < len; j++) {
                if (k) {
                    cout<<" ";
                }
                cout<<ans[j];
                k=1;
            }
            cout<<endl;
        }
    }
    return 0;
}