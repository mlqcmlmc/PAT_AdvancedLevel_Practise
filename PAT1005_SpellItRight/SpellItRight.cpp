#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
void StrIntSum(string &str, char c)
{
    if (str.empty())
    {
        str.push_back(c);
    }
    else
    {
        str[0] = str[0] + c - '0';
        int j = 0;
        while (j<str.size() - 1 && str[j]>'9')
        {
            str[j] = str[j] - 10;
            str[j + 1] = str[j + 1] + 1;
            j++;
        }
        if (str[str.size() - 1]>'9')
        {
            str[str.size() - 1] = str[str.size() - 1] - 10;
            str.push_back('1');
        }
    }
}
int main()
{
    string number[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string strN;
    cin >> strN;
    string str_sum;
    for (int i = 0; i < strN.size(); i++)
    {
        StrIntSum(str_sum, strN[i]);
    }

    reverse(str_sum.begin(), str_sum.end());
    if (!str_sum.empty())
    {
        cout << number[str_sum[0] - '0'];
    }
    for (int i = 1; i < str_sum.size(); i++)
    {
        cout << ' ' << number[str_sum[i] - '0'];
    }
    return 0;
}