//
// Created by wang on 2021/8/28.
//

#include <bits/stdc++.h>
#define inf 0x3f3f3f3f

using namespace std;
typedef long long ll;

int n,X,Y;
char str[200009];
struct node{
    int x,y;
    friend bool operator < (const node &a,const node b)
    {
        if(a.x==b.x) {
            return a.y<b.y;
        }
        return a.x<b.x;
    }
}arr[200009];
int a_x[4]={0,0,-1,1};
int a_y[4]={1,-1,0,0};


int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        scanf("%s", &str);
        arr[0].x = 0;
        arr[0].y = 0;
        int xy;
        int ans=0;
        for (int i = 0; i < n; i++) {
            if(str[i]=='U'){
                xy=0;
            } else if (str[i] == 'D') {
                xy=1;
            } else if (str[i] == 'L') {
                xy=2;
            } else if (str[i] == 'R') {
                xy = 3;
            }
            arr[i + 1].x = arr[i].x + a_x[xy];
            arr[i + 1].y = arr[i].y + a_y[xy];
        }
        sort(arr, arr + n + 1);


//        for (int i = 0; i <= n; i++) {
//            cout << i << " : " << arr[i].x << ' ' << arr[i].y<<endl;
//        }


        for (int i = 0; i < n;) {
//            cout << i << ' ';
            for (int j = i+1; j <= n; j++) {
                if (arr[i].x != arr[j].x || arr[i].y != arr[j].y) {
                    i = j ;
                    break;
                }
                if (arr[i].y == arr[j].y) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}