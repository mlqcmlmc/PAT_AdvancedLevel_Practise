#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long int N, M;
	cin >> N;
	long int temp;
	vector<long int> sequence1;
	for (int i = 0; i < N; ++i)
	{
		scanf("%ld", &temp);
		sequence1.push_back(temp);
	}
	cin >> M;
	vector<long int> sequence2;
	for (int i = 0; i < M; ++i)
	{
		scanf("%ld", &temp);
		sequence2.push_back(temp);
	}
	long int medium;
    long int h = 0, j = 0, k = 0;
    for (; h <= (M + N - 1) / 2 && j < N&&k < M; ++h)
	{
		if (sequence1[j] < sequence2[k])
		{
            medium = sequence1[j];
            ++j;
		}
		else 
		{
			medium = sequence2[k];
            ++k;

		}

	}
    if (h > (M + N - 1) / 2)
    {
        cout << medium << endl;
    }
    else if (j >= N)
    {
        medium = sequence2[(M + N - 1) / 2 - h + k];
        cout << medium << endl;
    }
    else if (k >= M)
    {
        medium = sequence1[(M + N - 1) / 2 - h + j];
        cout << medium << endl;
    }

	return 0;
}