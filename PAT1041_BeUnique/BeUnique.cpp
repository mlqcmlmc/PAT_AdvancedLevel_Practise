#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int a[100001] = { 0 };
int main()
{
    int N, temp, pos;
    vector<int> vec;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;        
        auto ite = find(vec.begin(), vec.end(), temp);
        if (ite==vec.end())
        {
            vec.push_back(temp);
        }
        else
        {
            pos = ite - vec.begin();
            a[pos] = 1;
        }
    }
    int i;
    for (i = 0; i < vec.size();++i)
    {
        if (a[i] == 0)
        {
            cout << vec[i] << endl;
            break;
        }
    }
    if (i==vec.size())
    {
        cout << "None" << endl;
    }
    return 0;
}