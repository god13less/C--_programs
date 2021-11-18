//
// Created by wang on 2021/1/26.
//

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    stack<char> stack1;
    int n, k,j;
    int flag[1000];
    char str1[1000], str2[1000];
    while (cin >> n) {
        cin >> str1 >> str2;
        memset(flag, -1, sizeof(flag));
        k=0;
        j=0;
        for (int i = 0; i < n; i++) {
            stack1.push(str1[i]);
            flag[k++] = 1;
            while (!stack1.empty() && stack1.top() == str2[j]) {
                stack1.pop();
                flag[k++]=0;
                j++;
            }
        }
        if (j == n) {
            cout<<"Yes."<<endl;
            for (int i = 0; i < k; i++) {
                if (flag[i]) {
                    cout<<"in"<<endl;
                } else {
                    cout<<"out"<<endl;
                }
            }
        } else {
            cout<<"No."<<endl;
        }
        cout<<"FINISH"<<endl;
        while (!stack1.empty()) {
            stack1.pop();
        }
    }

    return 0;
}