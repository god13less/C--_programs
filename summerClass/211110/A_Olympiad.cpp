//
// Created by wang on 2021/11/10.
//
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000

using namespace std;
typedef long long ll;
inline ll read(){
    int x=0;char ch;
    for(ch=getchar();!isdigit(ch);ch=getchar());
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return x;
}
int n;
int arr[maxn];
set<int> st;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tem;
        cin >> tem;
        if (tem) {
            st.insert(tem);
        }
    }
    cout<<st.size()<<endl;
    return 0;
}
