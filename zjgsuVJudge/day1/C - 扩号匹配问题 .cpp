//
// Created by wang on 2021/1/26.
//

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(){
    stack<int> sta1;
    char str[200];
    while (cin.getline(str,200)) {
        int len=strlen(str);
        char ans[len];
        memset(ans,' ',sizeof(ans));

        for (int i = 0; i < len; i++) {
            if (str[i] == ')') {
                if (!sta1.empty()) {
                    sta1.pop();
                } else {
                    ans[i]='?';
                }
            } else if (str[i] == '(') {
                sta1.push(i);
            }
        }
        while (!sta1.empty()) {
            ans[sta1.top()]='$';
            sta1.pop();
        }
        cout<<str<<endl;
        for (int i = 0; i < len; i++) {
            cout<<ans[i];
        }
        cout<<endl;
    }

    return 0;
}
