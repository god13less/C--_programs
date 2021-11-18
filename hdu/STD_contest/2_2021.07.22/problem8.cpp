//
// Created by wang on 2021/7/22.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

int n,m,t,p;
struct node {
    string name;
    int pay, w;

    friend bool operator<(const node &a, const node &b){
        if (a.name == b.name) {
            if (a.w == b.w) {
                return a.pay < b.pay;
            } else {
                return a.w > b.w;
            }
        } else {
            return a.name < b.name;
        }
    }
} arr[20000];
map<string, int> ma;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        string str;
        for (int i = 1; i <= n; i++) {
            cin >> str;
            ma[str] = 0;
        }
        cin >> m;
        int w,pay;
        for (int i = 1; i <= m; i++) {
            cin >> str >> w >> pay;
            arr[i].w = w;
            arr[i].name = str;
            arr[i].pay = pay;
        }
        cin>>t>>p;
    }

    return 0;
}
