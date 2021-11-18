//
// Created by wang on 2021/1/21.
//

#include <iostream>

using namespace std;

int main(){
    int m,n,row,column,tem;
    int arr[100][100];
    while (cin >> m >> n) {
        //initialize
        row=1;
        column=1;
        //input
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin>>arr[i][j];
            }
        }
        //find out Max
        tem=arr[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (abs(tem) < abs(arr[i][j])) {
                    tem=arr[i][j];
                    row=i+1;
                    column=j+1;
                }
            }
        }
        //output
        cout<<row<<" "<<column<<" "<<tem<<endl;

    }

    return 0;
}