#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

inline int read() {
    int x = 0;
    char ch;
    for (ch = getchar(); !isdigit(ch); ch = getchar());
    for (; isdigit(ch); ch = getchar())x = (x << 1) + (x << 3) + (ch ^ 48);
    return x;
}

map<char, int> ma;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (!ma.count(str[i])) {
            cnt++;
            ma[str[i]] = 1;
        } else {
            ma[str[i]]++;
        }
    }
    map<char, int>::iterator it;
    int minx = 9999999;
    for (it = ma.begin(); it != ma.end(); it++) {
        minx = min(minx, it->second);
//        cout << it->second << " ";
    }
    if (cnt < k) {
        cout << 0 << endl;
    } else {
        cout << minx * k << endl;
    }
    return 0;
}