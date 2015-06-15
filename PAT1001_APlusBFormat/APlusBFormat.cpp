#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define int64 long long int
int main()
{
    int64 a, b, sum = 0;
    int flag = 0, count = 0;
    string strsum;
    cin >> a >> b;
    sum = a + b;
    if (sum < 0)
    {
        flag = 1;
        sum = -sum;
    }
    while (sum > 0)
    {
        strsum.push_back(sum % 10 + '0');
        sum = sum / 10;
        count++;
        if (sum && (count % 3 == 0))
        {
            strsum.push_back(',');
        }
    }

    reverse(strsum.begin(), strsum.end());
    if (flag)
    {
        cout << '-';
    }
    if (strsum.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        cout << strsum << endl;
    }
    return 0;
}