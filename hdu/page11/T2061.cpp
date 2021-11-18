#include <stdio.h>
int main()
{
    int n, l = 0, k, i, x;
    double c[100], s[100], sum1, sum2;
    char name[100];
    scanf("%d", &n);
    while (l < n)
    {
        scanf("%d", &k);
        x = 0;
        sum1 = sum2 = 0;
        for (i = 0; i < k; i++)
        {
            scanf("%s %lf %lf", name, &c[i], &s[i]);
            sum1 += c[i];
            sum2 += c[i] * s[i];
            if (s[i] < 60)
                x = 1;
        }
        if (x == 1)
            printf("Sorry!\n");
        else
            printf("%.2lf\n", sum2 / sum1);
        l++;
        if (l != n)
            printf("\n");
    }
    return 0;
}