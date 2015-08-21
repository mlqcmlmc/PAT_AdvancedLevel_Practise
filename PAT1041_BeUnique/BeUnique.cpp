#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "stdio.h"
using namespace std;
int num[10001] = { 0 };
int input[100001] = { 0 };
int main()
{
    int N, temp, pos;
	int flag = 0;
    vector<int> vec;
    cin >> N;
	for (int i = 0; i < N;++i)
	{
		scanf("%d", &input[i]);
		++num[input[i]];
	}
	for (int i = 0; i < N;++i)
	{
		if (num[input[i]]==1)
		{
			cout << input[i] << endl;
			flag = 1;
			break;
		}
		
	}
	if (!flag)
	{
		cout << "None" << endl;

	}
    return 0;
}