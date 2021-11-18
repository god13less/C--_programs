//
// Created by wang on 2021/1/30.
//

#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int main(){
    string a,b;
    ll alen,blen;
    int b1,b2;
    while (cin >> a >> b) {
        for (int i = 0; a[i]=='0'; i++) {
            a = a.substr(i + 1);
        }
        for (int i = 0; b[i] == '0'; i++) {
            b = b.substr(i + 1);
        }
        b1=0;b2=0;
        alen=a.length();
        blen=b.length();
        for (int i = 0; i < alen; i++) {
            if (a[i] == '.') {
                b1=1;
            }
        }
        for (int i = 0; i < blen; i++) {
            if (b[i] == '.') {
                b2=1;
            }
        }
        if (b1) {
            for (ll i = alen-1; a[i]=='0' ; i--) {
                a = a.substr(0, a.length() - 1);
            }
        } else {
            a+='.';
        }
        if (b2) {
            for (ll i = blen - 1; b[i] == '0'; i--) {
                b = b.substr(0, b.length() - 1);
            }
        } else{
            b+='.';
        }
        if (a.length() != b.length()) {
            cout<<"NO"<<endl;
        } else {
            if (a == b) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}
