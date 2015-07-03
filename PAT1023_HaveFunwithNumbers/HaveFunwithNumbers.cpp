#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string strNum, strDoubleNum;
	char c;
	int one;
	int carryflag = 0;
	cin >> strNum;
	for (int i = strNum.size() - 1; i >= 0; --i)
	{
		if (carryflag)
		{
			one = (strNum[i] - '0') * 2 + 1;
			if (one < 10)
			{
				strDoubleNum.push_back(one + '0');
			}
			else
			{
				strDoubleNum.push_back(one - 10 + '0');

			}
		}
		else
		{
			one = (strNum[i] - '0') * 2;
			if (one < 10)
			{
				strDoubleNum.push_back(one + '0');
			}
			else
			{
				strDoubleNum.push_back(one - 10 + '0');

			}
		}
		if (one < 10)
		{
			carryflag = 0;
		}
		else
		{
			carryflag = 1;
		}
	}
	if (carryflag)
	{
		strDoubleNum.push_back('1');
	}
	reverse(strDoubleNum.begin(), strDoubleNum.end());
	string strsort1 = strNum, strsort2 = strDoubleNum;
	sort(strsort1.begin(), strsort1.end());
	sort(strsort2.begin(), strsort2.end());
	if (strsort1 == strsort2)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	cout << strDoubleNum << endl;


	return 0;
}