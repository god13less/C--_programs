//
//
// fuck you
#include<string>
#include<iostream>

using namespace std;

//高精度加法
//只能是两个正数相加
#include<iostream>
#include<string>
using namespace std;
string add(string s1,string s2)
{
    string s;
    int len1=s1.size()-1;
    int len2=s2.size()-1;
    int sum=0;
    int flag=0;
    while(len1>=0&&len2>=0)
    {
        sum=flag+s1[len1]-'0'+s2[len2]-'0';
        s=s+char(sum%10+'0');
        flag=sum/10;
        len1--;
        len2--;
    }
    while(len1>=0)
    {
        sum=flag+s1[len1]-'0';
        s=s+char(sum%10+'0');
        flag=sum/10;
        len1--;
    }
    while(len2>=0)
    {
        sum=flag+s2[len1]-'0';
        s=s+char(sum%10+'0');
        flag=sum/10;
        len2--;
    }
    if(flag>0)
    {
        s=s+char(flag+'0');
    }
    //s转置
    char tmp=' ';
    int end=s.size();
    for(int i=0;i<end/2;i++)
    {
        tmp=s[i];
        s[i]=s[s.size()-i-1];
        s[s.size()-i-1]=tmp;
    }
    return s;
}
bool largerTA(string a,string b)
{
    if(b.size()>a.size())
        return true;
    if(b.size()<a.size())
        return false;
    if(b.size()==a.size())
    {
        if(b>=a)
            return true;
        else
            return false;
    }
}
bool smallerTB(string a,string b)
{
    if(a.size()<b.size())
        return true;
    if(a.size()>b.size())
        return false;
    if(b.size()==a.size())
    {
        if(a<=b)
            return true;
        else
            return false;
    }
}
int main()
{
    string a;
    string b;
    string s[1000];
    s[1]="0";
    s[2]="1";
    while(cin>>a)
    {
        int sum=0;
        cin>>b;
        if(a=="0"&&b=="0")
            break;
        else
        {
            for(int i=3;;i++)
            {
                s[i]=add(s[i-1],s[i-2]);
                if(largerTA(a,s[i])&&smallerTB(s[i],b))
                    sum++;
                if(!smallerTB(s[i],b))
                    break;
            }
        }
        cout<<sum<<endl;
    }
}