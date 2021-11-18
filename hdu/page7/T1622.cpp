//
// Created by wang on 2021/7/7.
// unfinished

#include <bits\stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;

struct node{
    ll len;
    string s,val;
    friend bool operator < (const node &a,const node b)
    {
        if(a.len==b.len) {
            return a.s<b.s;
        }
        return a.len<b.len;
    }
}arr[1010];

map<string,ll> ma;
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str;
    ll index=0;
    ll flag=0,bo=0,f=1;
    ll num=0;
    while (cin >> str) {
        if (str != "()") {
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == ',') {
                    index=i;
                    if (str.length() - 1 - index == 1) {
                        flag=1;
                        str=str.substr(0,index+1)+"A)";
                    }
                }
            }
            arr[num].val = str.substr(1, index-1);
            arr[num].len=str.length()-1-index-1;
            arr[num].s=str.substr(index+1,str.length()-1-index-1);
            if (ma.count(arr[num].s)) {
                bo=1;
            } else {
                ma[arr[num].s]=1;
            }
            num++;
        } else {
            if (flag == 1 && bo == 0) {
                cout << "not complete" << endl;
                ma.clear();
                index = 0;
                flag = 0;
                f = 1;
                num = 0;
                continue;
            }
            sort(arr,arr+num);
            list<string> mylist;
            for(int i=0; i<num; i++) //遍历n个小数据
            {
                if(arr[i].len>0) //层数大于 1的话
                {
                    string s;
                    int l=arr[i].s.size();//路径位数+1
                    for(int j=0; j<l-1; j++) //找此节点的父节点
                        s+=arr[i].s[j];
                    if(ma[s]!=1) //判断是否有父节点
                    {
                        f=0;
                        break;
                    }
                }
                mylist.push_back(arr[i].val);//记录节点值
            }
            if(!f) {
                cout << "not complete" << endl;
                ma.clear();
                index = 0;
                flag = 0;
                f = 1;
                num = 0;
            } else {
                bool boo=0;
                list<string>::iterator it;
                for (it = mylist.begin(); it != mylist.end(); it++) {
                    cout << *it;
                    if (boo) {
                        cout<<' ';
                    }
                    boo=1;
                }
                cout<<endl;
            }
        }
    }


    return 0;
}