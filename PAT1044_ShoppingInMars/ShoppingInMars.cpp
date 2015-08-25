#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
#define NumMax 100001
long long int input[NumMax] = { 0 };
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
	for (int i = 0; i < N; ++i)
	{
		scanf("%ld", &input[i]);
		//cin >> input[i];
	}
	long long int sum = 0, sum_min = -1;
	long long int i, j;
	long long int* begin = input;
	long long int* end = input;
	for (; begin < input + N;)
	{
		for (; end < input + N; )
		{
			sum += *end;
			++end;
			if (sum >= M)
			{
				break;
			}
		}
		if (sum_min<0)
		{
			tmp_tag.begin = begin-input ;
			tmp_tag.end = end-input ;
			vec_out.push_back(tmp_tag);
			sum_min = sum;
		}
		else if (sum == sum_min&&sum >= M)
		{
			tmp_tag.begin = begin - input;
			tmp_tag.end = end - input;
			vec_out.push_back(tmp_tag);
		}
		else if (sum < sum_min&&sum >= M)
		{
			vec_out.clear();
			tmp_tag.begin = begin - input ;
			tmp_tag.end = end - input ;
			vec_out.push_back(tmp_tag);
			sum_min = sum;
		}

		while (sum >= M)
		{
			sum = sum - *begin;
			++begin;
		}
		sum = sum + *(begin - 1);

	}
	for (int i = 0; i < vec_out.size(); ++i)
	{
		cout << vec_out[i].begin << '-' << vec_out[i].end << endl;
	}
	return 0;
}