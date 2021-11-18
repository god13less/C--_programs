//
// Created by wang on 2021/10/17.
//
#include <iostream>
#include <string>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 1000000

using namespace std;
typedef long long ll;
string str;
vector<char> tem;
vector<char>::iterator it;
int tot;
string getstr(char cha){
    if(cha=='Y'){
        return "QQQ";
    } else if (cha == 'V') {
        return "QQW";
    }else if(cha=='G'){
        return "QQE";
    }else if(cha=='C'){
        return "WWW";
    }else if(cha=='X'){
        return "QWW";
    }else if(cha=='Z'){
        return "WWE";
    }else if(cha=='T'){
        return "EEE";
    }else if(cha=='F'){
        return "QEE";
    }else if(cha=='D'){
        return "WEE";
    }else if(cha=='B'){
        return "QWE";
    }
}

int main() {
    while (cin >> str) {
        tot = 3;
        string s = getstr(str[0]);
        for (int i = 0; i <= 2; i++) {
            tem.push_back(s[i]);
        }
        for (int i = 1; i < str.length(); i++) {
            int flag[3] = {0, 0, 0};
            int flag2[3] = {0, 0, 0};
            string now = getstr(str[i]);
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k <= 3; k++) {
                    if (now[j] == tem[k] && flag2[k] != 1) {
                        flag[j] = 1;
                        flag2[k] = 1;
                        break;
                    }
                }
            }
            for (int j = 0; j < 3; j++) {
                if (!flag[j]) {
                    it = tem.begin();
                    tem.erase(it);
                    tem.push_back(now[j]);
                    tot++;
                }
            }
        }
        cout << tot + str.length() << endl;
    }

    return 0;
}