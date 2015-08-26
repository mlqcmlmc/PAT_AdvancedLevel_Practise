#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define CardNum 55
int main()
{
	vector<string> before_order, after_order;
	int order[55];
	before_order.resize(CardNum);
	after_order.resize(CardNum);
	for (int i = 1; i < CardNum; ++i)
	{
		string str;
		if (i <= 13)
		{
			str.push_back('S');
			str += to_string(i); 
		}
		else if (i <= 26)
		{
			str.push_back('H');
			str += to_string(i - 13);
		}
		else if (i <= 39)
		{
			str.push_back('C');
			str += to_string(i - 26);
		}
		else if (i <= 52)
		{
			str.push_back('D');
			str += to_string(i - 39);
		}
		else
		{
			str.push_back('J');
			str += to_string(i - 52);
		}
		before_order[i] = str;
	}
	int N, num;
	cin >> N;
	for (int i = 1; i < CardNum; ++i)
	{
		cin >> num;
		order[i] = num;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j < CardNum; ++j)
		{
			after_order[order[j]] = before_order[j];
		}
		before_order = after_order;
	}
	cout << after_order[1];
	for (int i = 2; i < CardNum; ++i)
	{
		cout << ' ' << after_order[i];
	}
	cout << endl;
	return 0;
}