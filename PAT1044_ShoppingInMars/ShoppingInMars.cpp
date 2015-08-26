#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
#define NumMax 100002
long long int input[NumMax] = { 0 };
long long int allsum[NumMax] = { 0 };
struct tag
{
	long long int begin;
	long long int end;
};
int main()
{
	long long int N, M;
	cin >> N >> M;
	vector<tag> vec_out;
	tag tmp_tag;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%ld", &input[i]);
		allsum[i] = allsum[i - 1] + input[i];
	}
	long long int begin = 0, end = 0;
	long long int sum = 0, sum_min = 200000000;
	while (!(sum<M&&end==N))
	{
		sum = allsum[end] - allsum[begin];
		if (sum<M&&end < N)
		{
			++end;
			if (sum >= M)
			{
				if (sum == sum_min)
				{
					tmp_tag.begin = begin;
					tmp_tag.end = end;
					vec_out.push_back(tmp_tag);
					sum_min = sum;
				}
				else if (sum < sum_min)
				{
					vec_out.clear();
					tmp_tag.begin = begin;
					tmp_tag.end = end;
					vec_out.push_back(tmp_tag);
					sum_min = sum;
				}
			}
		}
		else
		{
			++begin;
			if (sum >= M)
			{
				if (sum == sum_min)
				{
					tmp_tag.begin = begin;
					tmp_tag.end = end;
					vec_out.push_back(tmp_tag);
					sum_min = sum;
				}
				else if (sum < sum_min)
				{
					vec_out.clear();
					tmp_tag.begin = begin;
					tmp_tag.end = end;
					vec_out.push_back(tmp_tag);
					sum_min = sum;
				}
			}
		}
		sum = allsum[end] - allsum[begin];

	}
	for (int i = 0; i < vec_out.size(); ++i)
	{
		printf("%ld", vec_out[i].begin);
		printf("-");
		printf("%ld\n", vec_out[i].end);
	}
	return 0;
}