//
// Created by wang on 2021/2/2.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;

string str, s;
ll pi[2000000];

void prefix_function(string s) {
    memset(pi, 0, sizeof pi);
    for (int i = 1; i < s.length(); i++) {
        int index = pi[i - 1];
        while (index > 0 && s[i] != s[index]) {
            index = pi[index - 1];
        }
        if (s[i] == s[index]) {
            index++;
        }
        pi[i] = index;
    }
}

vector<int> kmp(string s1, string s2) {
    vector<int> appear;
    int p = 0;
    for (int i = 0; i < s1.size(); i++) {
        while (p > 0 && s1[i] != s2[p]) {
            p = pi[p - 1];
        }
        if (s1[i] == s2[p]) {
            p++;
        }
        if (p == s2.size()) {
            appear.push_back(i + 2 - s2.size());
        }
    }
    return appear;
}

int main() {
    vector<int> ans;
    cin>>str>>s;
    prefix_function(s);
    ans = kmp(str, s);
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans.at(i)<<endl;
    }
    for (int i = 0; i < s.length(); i++) {
        if (i!=s.length()-1){
            cout<<pi[i]<<" ";
        } else {
            cout<<pi[i];
        }
    }
    return 0;
}