//
// Created by wang on 2021/8/18.
//

#include <iostream>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

int n,m,k,cards,maxJokers,ans;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cards = n / k;
        if (cards >= m) {
            ans = m;
        } else {
            maxJokers=cards;
            int otherJokers = m - maxJokers;
            if (otherJokers % k) {
                otherJokers = otherJokers / k + 1;
            } else {
                otherJokers /= k;
            }
            ans = maxJokers - otherJokers;
        }
        cout<<ans<<endl;
    }

    return 0;
}