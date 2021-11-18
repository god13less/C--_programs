//
// Created by wang on 2021/1/29.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int n, num;
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 1) {
            string s;
            cin >> s;
            str = str + s;
            cout << str << endl;
        } else if (num == 2) {
            int a, b;
            cin >> a >> b;
            str = str.substr(a, b);
            cout << str << endl;
        } else if (num == 3) {
            int a;
            string  s;
            cin>>a>>s;
            str=str.substr(0,a)+s+str.substr(a);
            cout << str << endl;
        } else if (num == 4) {
            string s;
            int bo=1;
            cin>>s;
            for (int j = 0; j < str.length(); j++) {
                if (str.substr(j, s.length()) == s) {
                    cout<<j<<endl;
                    bo=0;
                    break;
                }
            }
            if (bo) {
                cout<<-1<<endl;
            }
        }
    }

    return 0;
}
