#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct Currency
{
    int galleon = 0;
    int sickle = 0;
    int knut = 0;
    friend Currency operator+(const Currency& lhs, const Currency& rhs);
};
Currency operator + (const Currency& lhs, const Currency& rhs)
{
    Currency sum;
    sum.knut = (lhs.knut + rhs.knut) % 29;
    sum.sickle += (lhs.knut + rhs.knut) / 29;
    
    sum.sickle += lhs.sickle + rhs.sickle;
    sum.galleon += sum.sickle / 17;
    sum.sickle = sum.sickle % 17;

    sum.galleon += lhs.galleon + rhs.galleon;
    return sum;
}

int main()
{
    Currency lhs, rhs;
    scanf("%d.%d.%d", &lhs.galleon, &lhs.sickle, &lhs.knut);
    scanf("%d.%d.%d", &rhs.galleon, &rhs.sickle, &rhs.knut);
    Currency sum;
    sum = lhs + rhs;
    printf("%d.%d.%d", sum.galleon, sum.sickle, sum.knut);
    return 0;
}