//
// Created by wang on 2021/5/10.
//

#include<cstdio>
using namespace std;

int main()
{
    __int64 a,b;
    while(~scanf("%I64X%I64X",&a,&b))
    {
        if(a + b >= 0)
            printf("%I64X\n",a+b);
        else
            printf("-%I64X\n",-(a+b));
    }
    return 0;
}
