//
// Created by wang on 2021/10/20.
//

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
string str_arr[55];
int t;
string fun(string a){
    string b = a.substr(1, a.length() - 1);
    b = b + a[0];
    return b;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> str_arr[i];
    }
    int ans=0;
    int minn = 1000000000;
    int len = str_arr[1].length();
    int cnt = 0;
    for (int i = 1; i <= t; i++) {
        ans = 0;
        for (int j = 1; j <= t; j++) {
            cnt = 0;
            string w = str_arr[j];
            while (w != str_arr[i] && cnt <= len) {
                ans++;
                w = fun(w);
                cnt++;
            }
            if (cnt > len) {
                cout<<-1<<endl;
                return 0;
            }
        }
        minn = min(minn, ans);
    }
    cout<<minn<<endl;
    return 0;
}