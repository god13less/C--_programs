//
// Created by wang on 2021/1/26.
//
#include <iostream>
#include <queue>

using namespace std;

struct node {
    long long id;
    long long fi;
    long long si;

    friend bool operator<(node a, node b) {
        if (a.fi != b.fi) {
            return a.fi < b.fi;
        } else {
            return a.id > b.id;
        }
    }
};

int main() {
    long long n=0;
    cin >> n;
    for (long long k = 0; k < n; k++) {
        priority_queue<node> que[110];
        node peo={0,0,0};
        long long num = 0;
        cin >> num;
        for (long long i = 0; i < num; i++) {
            cin >> peo.fi >> peo.si;
            peo.id = i + 1;
            que[peo.si].push(peo);
        }
        cout << "Case #" << k + 1 << endl;
        for (long long i = 0; i < num; i++) {
            long long int maxx = -9999;
            int now;
            for (int j = 1; j <= 100; j++) {
                if (!que[j].empty()) {
                    peo = que[j].top();
                    if (peo.fi + j * i > maxx) {
                        maxx = peo.fi + j * i;
                        now = j;
                    } else if (peo.fi + j * i == maxx && peo.id < (que[now].top()).id) {
                        now = j;
                    }
                }
            }
            if (i != num - 1) {
                cout << que[now].top().id << " ";
            } else {
                cout << que[now].top().id << endl;
            }
            que[now].pop();
        }
    }
    return 0;
}
