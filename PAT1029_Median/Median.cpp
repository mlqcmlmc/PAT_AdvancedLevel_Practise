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
		scanf("%d", &temp);
		//cin >> temp;
		sequence1.push_back(temp);
	}
	cin >> M;
	vector<long int> sequence2;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &temp);
		//cin >> temp;
		sequence2.push_back(temp);
	}
	long int medium;
	for (int i = 0, j = 0, k = 0; i <= (M + N - 1) / 2; ++i)
	{
		if (j == N)
		{
			++k;
		}
		else if (k == M)
		{
			++j;
		}
		else if (j < N&&sequence1[j] < sequence2[k])
		{
			/*if (i == (M + N - 1) / 2)
			{
				medium;
			}*/
			if (j != N - 1)
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
		else if (k<M&&sequence1[j] > sequence2[k])
		{
			if (k != M - 1)
			{
				medium = sequence1[k];
				++k;

			}
			else
			{
				++j;
			}
		}

	}
	//sort(sequence1.begin(), sequence1.end());
	//if (!sequence1.empty())
	//{
	//	printf("%d\n", sequence1[(sequence1.size() - 1) / 2]);
	//	//cout << sequence1[(sequence1.size() - 1) / 2] << endl;
	//}
	//else
	//{

	//}
	return 0;
}