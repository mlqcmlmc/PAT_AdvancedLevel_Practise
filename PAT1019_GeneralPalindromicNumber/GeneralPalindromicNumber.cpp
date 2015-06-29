#include<iostream>
#include<vector>
using namespace std;
vector<long long int> Dec2Base(long long int num, long long int b)
{
    vector<long long int> base_num;
    if (num == 0)
    {
        base_num.push_back(num);
    }
    while (num)
    {
        base_num.push_back(num%b);
        num = num / b;
    }
    return base_num;
}

int main()
{
    long long int N, base;
    cin >> N >> base;
    auto out_num = Dec2Base(N, base);
    auto itbegin = out_num.begin();
    auto itend = out_num.end() - 1;
    int flag = 1;
    while (itbegin < itend)
    {
        if (*itbegin != *itend)
        {
            flag = 0;
            break;
        }
        ++itbegin;
        --itend;
    }
    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    for (int i = out_num.size()-1; i > 0; --i)
    {
        cout << out_num[i] << " ";
    }
    cout << out_num[0];

    return 0;
}