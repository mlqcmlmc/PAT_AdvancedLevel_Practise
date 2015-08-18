#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "stdio.h"
using namespace std;
#define num 100000
int flag[num] = { 0 };
int main()
{
    long int addr1, addr2, temp1, temp2;
    char c;
    long int N;
    cin >> addr1 >> addr2 >> N;
    map<long int, long int> map_addrs;
    for (long int i = 0; i < N; ++i)
    {
        scanf("%ld %c %ld", &temp1, &c, &temp2);
        //cin >> temp1 >> c >> temp2;
        map_addrs.insert(make_pair(temp1, temp2));
    }
    long int key = addr1;
    while (key != -1)
    {
        flag[key] = 1;
        key = map_addrs[key];
    }
    key = addr2;
    while (key != -1)
    {
        if (flag[key] == 1)
        {
            printf("%05d\n", key);
            break;
        }
        key = map_addrs[key];
    }
    if (key == -1)
    {
        printf("-1\n");
    }
    return 0;
}
