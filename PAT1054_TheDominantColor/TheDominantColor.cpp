#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include "stdio.h"
using namespace std;
int main()
{
    int M, N;
    cin >> M >> N;
    map<long long int, int> digital_color ;
    for (int i = 0; i < N;++i)
    {
        long long int temp;
        for (int j = 0; j < M; ++j)
        {
            cin >> temp;
            digital_color[temp]++;
        }
    }
    auto ite = digital_color.begin();
    int count_max = 0;
    long long int dominant_color;
    for (; ite != digital_color.end();++ite)
    {
        if (ite->second>count_max)
        {
            count_max = ite->second;
            dominant_color = ite->first;
        }
    }
    cout << dominant_color << endl;
    return 0;
}