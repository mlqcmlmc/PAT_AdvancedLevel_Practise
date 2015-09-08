#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>  
int main(){
    int n, i;
    long long int a, b, c;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        bool flg = true;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long res = a + b;
        if (a > 0 && b > 0 && res <= 0)
            flg = true;
        else if (a < 0 && b < 0 && res >= 0)
            flg = false;
        else
        {
            if (res <= c)
                flg = false;
        }
        if (flg)
        {
            printf("Case #%d: true\n", i);
        }
        else{
            printf("Case #%d: false\n", i);
        }
    }
    return 0;
}