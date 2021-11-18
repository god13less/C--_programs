//
// Created by wang on 2021/7/8.
//

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double EI = exp(1.0);
const int inf = 0x3f3f3f3f;

int n;
int a[50009],c[50009]; //对应原数组和树状数组

int lowbit(int x){
    return x&(-x);
}

void updata(int i,int k){    //在i位置加上k
    while(i <= n){
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i){        //求A[1 - i]的和
    int res = 0;
    while(i > 0){
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    for (int k = 1; k <=t; k++) {
        cout<<"Case "<<k<<":"<<endl;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        cin>>n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            updata(i, a[i]);
        }
        string str;
        int index,b;
        while (cin >> str && str != "End") {
            cin>>index>>b;
            if (str == "Query") {
                cout << getsum(b) - getsum(index - 1)<<endl;
            } else if (str == "Add") {
                updata(index, b);
            } else {
                updata(index, -b);
            }
        }
    }

    return 0;
}
