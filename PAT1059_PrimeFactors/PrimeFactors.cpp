//#include <iostream>
//#include <map>
//using namespace std;
//bool isPrime(int num)
//{
//    for (int i = 2; i*i <= num; i++)
//    {
//        if (!(num%i))
//        {
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//    long int N;
//    cin >> N;
//    long int cur = N;
//    map<long long int,int> prime_factors;
//    while (cur % 2 == 0)
//    {
//        ++prime_factors[2];
//        cur = cur / 2;
//    }
//    bool flag = false;
//    for (int i = 3; i <= cur; )
//    {
//        flag = false;
//        if (cur%i == 0)
//        {
//            if (isPrime(i))
//            {
//                ++prime_factors[i];
//                cur = cur / i;
//                flag = true;
//            }
//        }
//        if (!flag)
//        {
//            ++i;
//            ++i;
//        }
//    }
//    printf("%d=", N);
//    auto ite = prime_factors.begin();
//    printf("%d", ite->first);
//    if (ite->second > 1)
//    {
//        printf("^%d", ite->second);
//    }
//    ++ite;
//    for (; ite != prime_factors.end();++ite)
//    {
//        printf("*%d", ite->first);
//        if (ite->second>1)
//        {
//            printf("^%d", ite->second);
//        }
//    }
//    printf("\n");
//    return 0;
//}

#include <iostream>
using namespace std;
bool isPrime(int num)
{
    for (int i = 2; i*i <= num; i++)
    {
        if (!(num%i))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    long int N;
    cin >> N;
    printf("%d=", N);
    int count_ = 0;
    if (N == 1)
    {
        printf("1\n");
    }
    else
    {
        long int cur = N;
        for (int i = 2; i <= cur; ++i)
        {
            int exponent = 0;
            if (isPrime(i))
            {
                while (cur%i == 0)
                {
                    ++exponent;
                    cur = cur / i;
                }
            }
            if (exponent == 1)
            {
                printf("%d", i);
            }
            else if (exponent > 1)
            {
                printf("%d^%d", i, exponent);
            }
           
            if (exponent >= 1 && cur != 1)
                printf("*");

        }
        printf("\n");
    }
    
    return 0;
}