#include<cstdio>

using namespace std;

int main() {
    int i, n, l;
    scanf("%d", &n);
    if (n > 2) {
        printf("Yes\n");
        printf("%d ", n / 2);
        for (i = 2; i <= n; i += 2) {
            printf("%d ", i);
        }
        l = n / 2;
        if (n % 2 != 0) {
            l += 1;
        }
        printf("\n%d ", l);
        for (i = 1; i <= n; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        printf("No\n");
    }
    return 0;
}