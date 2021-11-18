//
// Created by wang on 2021/8/18.
//

#include <iostream>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

int n,m,x,y;
int tem, cntx, cnty;
int ans;
char c;
void save2(){
    cntx = 0;
    cnty = 0;
    ans = 0;
    for (int i = 1; i <=n ; i++) {
        tem=0;
        for (int j = 1; j <= m; j++) {
            cin>>c;
            if (c == '*') {
                tem=0;
                continue;
            } else if (tem &&c=='.') {
                cntx--;
                cnty++;
                tem=0;
            } else if (!tem && c == '.') {
                tem=1;
                cntx++;
            }
        }
    }
    ans = x * cntx + y * cnty;
}
void save1(){
    cntx=0;
    ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c;
            if (c == '.') {
                cntx++;
            }
        }
    }
    ans = cntx * x;
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        cin>>n>>m>>x>>y;
        if (2 * x <= y) {
            save1();
        } else {
            save2();
        }
        cout<<ans<<endl;
    }

    return 0;
}