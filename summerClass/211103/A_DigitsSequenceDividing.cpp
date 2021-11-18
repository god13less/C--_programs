//
// Created by wang on 2021/11/3.
//

#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000060

using namespace std;
typedef long long ll;

int t, n;
string str;
vector<int> vec;

void save() {
    if (str.length() == 2 && str[0] >= str[1]) {
        cout<<"NO"<<endl;
    } else {
        cout << "YES" << endl << 2 << endl;
        cout << str[0] << ' ' << str.substr(1, str.length() - 1)<<endl;
    }
}

int main() {
    cin >> t;
    while (t--) {
        vec.clear();
        cin >> n >> str;
        save();
    }
    return 0;
}