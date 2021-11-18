//
// Created by wang on 2021/1/30.
//

#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;
typedef long long ll;

int main() {
    string a;
    set<string> s;
    while (getline(cin, a)) {
        if (a == "#") {
            break;
        }
        stringstream sstream(a);
        string b;
        while (sstream >> b) {
            s.insert(b);
        }
        cout << s.size() << endl;
        s.clear();
    }
    return 0;
}
