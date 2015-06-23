#include<iostream>
#include<algorithm>
using namespace std;
int  ReverseNumber(int num, int d)
{
	int rev_num = 0;
	while (num)
	{
		rev_num = rev_num*d + (num % d);
		num = num / d;
	}
	return rev_num;
}

bool isprime(int num)
{
	if (num < 2)
	{
		return 0;
	}
	for (int i = 2; i <= sqrt(num); ++i)
	{
		if (num%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int N = 1, D = 10;
	int rev_N;
	cin >> N;
	while (N > 0)
	{
		cin >> D;
		int rev_N = ReverseNumber(N, D);
		if (isprime(N) && isprime(rev_N))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}

		cin >> N;
	}
	return 0;
}