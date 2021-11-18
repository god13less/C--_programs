//
// Created by wang on 2021/4/29.
//

#include <iostream>
#include <map>

#define N 1000005

using namespace std;
typedef long long ll;

map<char, int> a;

int main() {
    int j = 'A';
    int k = 'a';
    for (int i = 1; i <= 26; i++) {
        a[j++] = i;
        a[k++] = -i;
    }

    int n, y;
    char chr;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> chr >> y;
        cout << a[chr]+y << endl;
    }
    return 0;
}