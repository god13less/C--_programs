//
// Created by wang on 2021/7/7.
//

#include <bits\stdc++.h>

#define endl "\n"
#define maxn 3600
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;
struct node {
    ll x1, x2, x3, x4;
} no;

map<char, node> ma;
int m, n;
char ch[55][55];//用于储存字母；
int arr[55][55];//用于储存对应字母的序号，以便并查集操作
int pre[maxn];
int num[maxn];

void init() {
    no = {1, 1, 0, 0};
    ma['A'] = no;
    no = {0, 1, 1, 0};
    ma['B'] = no;
    no = {1, 0, 0, 1};
    ma['C'] = no;
    no = {0, 0, 1, 1};
    ma['D'] = no;
    no = {0, 1, 0, 1};
    ma['E'] = no;
    no = {1, 0, 1, 0};
    ma['F'] = no;
    no = {1, 1, 1, 0};
    ma['G'] = no;
    no = {1, 1, 0, 1};
    ma['H'] = no;
    no = {1, 0, 1, 1};
    ma['I'] = no;
    no = {0, 1, 1, 1};
    ma['J'] = no;
    no = {1, 1, 1, 1};
    ma['K'] = no;
}

void init2() {
    int nu = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = nu;
            nu++;
        }
    }
    for (int i = 1; i <= n * m; i++) {
        pre[i] = i;
        num[i] = 1;
    }
}

int Find(int x) {
    if (x == pre[x]) {
        return x;
    }
    return pre[x] = Find(pre[x]);
}

void Union(int x, int y) {
    int fx = Find(x);
    int fy = Find(y);
    if (fx == fy) {
        return;
    }
    pre[fx] = fy;
    num[fy] += num[fx];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    string s;
    while (cin >> m >> n && m > 0 && n > 0) {
        init2();
        for (int i = 1; i <= m; i++) {
            cin >> s;
            for (int j = 1; j <= n; j++) {
                ch[i][j] = s[j - 1];
            }
        }
        //行遍历
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <=n-1 ; j++) {
                if(ma[ch[i][j]].x3==1&&ma[ch[i][j+1]].x1==1) {
                    Union(arr[i][j], arr[i][j + 1]);
                }
            }
        }
        //列遍历
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m - 1; j++) {
                if(ma[ch[j][i]].x4==1&&ma[ch[j+1][i]].x2==1) {
                    Union(arr[j][i], arr[j+1][i]);
                }
            }
        }
        int ans=0;
        for (int i = 1; i <= n * m; i++) {
            if (pre[i] == i) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}










