//
// Created by wang on 2021/7/5.
//

#include <iostream>
#include <map>
#include <vector>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
ll t, n;
string str, tem;
map<string, string> m;
vector<string> vct;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        m.clear();
        for (int i = 0; i < n; i++) {
            cin >> str;
            for (int j = 0; j < str.length(); j++) {
                for (int k = j + 1; k < str.length(); k++) {
                    tem = str.substr(j, k);
                    if (!m.count(tem)) {
                        m[tem] = str;
                    } else {
                        vct.push_back(tem);
                    }
                }
            }
        }
        for (int i = 0; i < vct.size(); i++) {
            m.erase(vct[i]);
        }
        string te;
        bool bo = 1;
        while (cin >> te && bo) {
            if (te[te.length() - 1] == '#') {
                te = te.substr(0, te.length() - 1);
                bo = 0;
            }
            if (!m.count(te)) {
                cout << "AMBIGUITY" << endl;
                break;
            } else {
                cout << m[te]<<' ';
            }
        }
    }
    return 0;
}