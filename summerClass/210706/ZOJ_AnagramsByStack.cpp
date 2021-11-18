//
// Created by wang on 2021/7/6.
//

#include <iostream>
#include <stack>
#include <vector>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

string str1,str2;
stack<char> build;
vector<char> operate;
int length;

void dfs(int iPush,int iPop){
    if (iPush == length && iPop ==length) {
        for (int i = 0; i < operate.size(); i++) {
            cout << operate[i] << " ";
        }
        cout<<endl;
    }
    //进行压栈遍历
    if (iPush + 1 <= length) {
        build.push(str1[iPush]);
        operate.push_back('i');
        dfs(iPush + 1, iPop);
        build.pop();
        operate.pop_back();
    }
    //进行出栈遍历
    if (iPop + 1 <= iPush && iPop + 1 <= length && build.top() == str2[iPop]) {
        char tc=build.top();
        build.pop();
        operate.push_back('o');
        dfs(iPush, iPop + 1);
        build.push(tc);
        operate.pop_back();
    }
}

int main() {
    while (cin >> str1 >> str2) {
        length=str1.length();
        cout<<'['<<endl;
        dfs(0, 0);
        cout<<']'<<endl;
    }
    return 0;
}