//
// Created by wang on 2021/9/29.
//
#include <bits/stdc++.h>

#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;
int q, n;
ll k;
ll arr[100020];
string str=R"(What are you doing while sending ")";
string str0=R"(What are you doing at the end of the world? Are you busy? Will you save us?)";
string str1=R"("? Are you busy? Will you send ")";
string str2=R"("?)";

void init(int x){
    arr[0]=75;
    for (int i = 1; i <=x ; i++) {
        arr[i] = 68 + arr[i-1]*2;
    }
}


int main() {
    cin >> q;
    init(100000);
    for (int i = 1; i <= q; i++) {
        cin >> n >> k;
        ll maxn = arr[i];
        if (k > maxn) {
            cout<<'.';
        }else if (k <= (maxn / 2) - 75) {
            k=k%34;
            cout << str[(k + 33) % 34];
        } else if (k > (maxn / 2) - 75 && k <= maxn / 2) {
            k -= (maxn / 2) - 75 - 1;
            cout << str0[k];
        } else if (k > maxn / 2 && k <= (maxn / 2) + 32 * n) {
            k -= maxn / 2;
            k=k%32;
            cout << str1[(k + 31) % 32];
        } else if (k > (maxn / 2) + 32 * n && k <= maxn - 2 * n) {
            k -= (maxn / 2) + 32 * n-1;
            cout << str0[k];
        } else if (k > maxn - 2 * n && k <= maxn) {
            k -= maxn - 2 * n;
            k = k % 2;
            cout << str2[(k + 1) % 2];
        }
    }
    cout<<endl;
    return 0;
}
