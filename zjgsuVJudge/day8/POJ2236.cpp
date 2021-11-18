//
// Created by wang on 2021/2/18.
//

#include <iostream>

#define maxn 300050

using namespace std;
typedef long long ll;

int n, d, t1, t2,k;
int pre[maxn];
char str;

struct com {
    int x, y, id;

    com() {}

    com(int a, int b, int c) : x(a), y(b), id(c) {}
} a[maxn],b[maxn];

int dis(com a, com b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int Find(int a) {
    while (pre[a] != a) {
        a = Find(pre[a]);
    }
    return a;
}

void Union(int x, int y) {
    int fx = Find(x);
    int fy= Find(y);
    if (fx != fy) {
        pre[fy]=fx;
    }
}

int main() {
    k=0;
    cin >> n >> d;
    d = d * d;
    a[0] = com(0, 0, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t1 >> t2;
        a[i] = com(t1, t2, i);
        pre[i] = i;
    }
    while (cin >> str) {
        if (str == 'O') {
            cin>>t1;
            b[k++] = a[t1];
            for (int i = 0; i <k ; i++) {
                if (dis(a[t1], b[i])<=d) {
                    Union(t1,b[i].id);
                }
            }
        } else if (str=='S') {
            cin>>t1>>t2;
            if (Find(t1) == Find(t2)) {
                cout<<"SUCCESS"<<endl;
            } else {
                cout<<"FAIL"<<endl;
            }
        }
    }

    return 0;
}
