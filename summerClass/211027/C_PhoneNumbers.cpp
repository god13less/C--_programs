//
// Created by wang on 2021/10/27.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
map<string, int> mp;
int N, n, cnt;
int cn[100];
vector<string> str_arr[25];
string name_str, tem_str;

int main() {
    cnt = 0;
    cin >> N;
    while (N--) {
        cin >> name_str >> n;
        if (!mp.count(name_str)) {
            cnt++;
            mp[name_str] = cnt;
        }
        while (n--) {
            cin >> tem_str;
            int num_tem=str_arr[mp[name_str]].size();
            if (num_tem) {
                bool boooo = true;
                for (int i = 0; i < num_tem; i++) {
                    string te_str = str_arr[mp[name_str]][i];
                    if (te_str.size() >= tem_str.size()) {
                        if (te_str.substr(te_str.length() - tem_str.length(), tem_str.length()) == tem_str) {
                            break;
                        } else {
                            if (boooo) {
                                str_arr[mp[name_str]].push_back(tem_str);
                                boooo = false;
                            }
                        }
                    } else {
                        if (tem_str.substr(tem_str.length() - te_str.length(), te_str.length()) == te_str) {
                            remove(str_arr[mp[name_str]].begin(), str_arr[mp[name_str]].end(), te_str);
                        }
                        if (boooo) {
                            str_arr[mp[name_str]].push_back(tem_str);
                            boooo = false;
                        }
                    }
                }

            }else{
                str_arr[mp[name_str]].push_back(tem_str);
            }
        }
    }
    cout << cnt << endl;
    vector<string>::iterator it;
    for (int i = 1; i <= cnt; i++) {
        cout<<str_arr[i].size()<<' ';
        for (it = str_arr[i].begin(); it != str_arr[i].end(); it++) {
            cout << *it << ' ';
        }
        cout<<endl;
    }

    return 0;
}
