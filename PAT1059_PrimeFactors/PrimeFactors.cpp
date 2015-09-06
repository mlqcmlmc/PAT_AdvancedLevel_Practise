#include <iostream>
#include <map>
using namespace std;
bool isPrime(int num)
{
    bool mark = 1;
    for (int i = 2; i*i <= num; i++)
    {
        if (!(num%i))
        {
            mark = 0;
            return mark;
        }
    }
    return mark;
}
int main()
{
    long int N;
    cin >> N;
    long int cur = N;
    map<long long int,int> prime_factors;
    while (cur%2 == 0)
    {
        ++prime_factors[2];
        cur = cur / 2;
    }
    bool flag = false;
    for (int i = 3; i <= cur; )
    {
        flag = false;
        if (cur%i == 0)
        {
            if (isPrime(i))
            {
                ++prime_factors[i];
                cur = cur / i;
                flag = true;
            }
        }
        if (!flag)
        {
            ++i;
            ++i;
        }
    }
    printf("%d=", N);
    auto ite = prime_factors.begin();
    printf("%d", ite->first);
    if (ite->second > 1)
    {
        printf("^%d", ite->second);
    }
    ++ite;
    for (; ite != prime_factors.end();++ite)
    {
        printf("*%d", ite->first);
        if (ite->second>1)
        {
            printf("^%d", ite->second);
        }
    }
    printf("\n");
    return 0;
}