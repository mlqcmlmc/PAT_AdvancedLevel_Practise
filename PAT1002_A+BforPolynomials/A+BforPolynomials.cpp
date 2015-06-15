#include<iostream>
#include<map>
#include<algorithm>
#include "stdio.h"
using namespace std;
int main()
{
    map<int, double> sum;
    double coe, poly1[1001] = { 0 }, poly2[1001] = { 0 }, polysum[1001] = { 0 };
    int exp, N1, N2, count = 0;
    cin >> N1;
    for (int i = 0; i < N1; i++)
    {
        cin >> exp >> coe;
        poly1[exp] = coe;
        polysum[exp] = poly1[exp];
    }
    cin >> N2;
    for (int i = 0; i < N2; i++)
    {
        cin >> exp >> coe;
        poly2[exp] = coe;
        polysum[exp] = poly1[exp] + poly2[exp];
    }
    for (int i = 1000; i >= 0; i--)
    {
        if (abs(polysum[i]) > 10e-5)
        {
            sum.insert({ i, polysum[i] });
        }
    }
    cout << sum.size();
    auto itsum = sum.end();
    while (itsum != sum.begin())
    {
        --itsum;
        printf(" %d %.1f", itsum->first, itsum->second);

    }
    cout << endl;
    return 0;
}