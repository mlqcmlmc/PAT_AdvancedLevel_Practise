#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    long long int NC, NP, temp;
    long long int sum = 0;
    vector<long long int> vec_nc, vec_np;
    cin >> NC;
    for (long long int i = 0; i < NC; ++i)
    {
        cin >> temp;
        vec_nc.push_back(temp);
    }
    cin >> NP;
    for (long long int i = 0; i < NP;++i)
    {
        cin >> temp;
        vec_np.push_back(temp);
    }
    sort(vec_nc.rbegin(), vec_nc.rend());
    sort(vec_np.rbegin(), vec_np.rend());
    long long int N = NC < NP ? NC : NP;
    for (long long int i = 0; i < N;++i)
    {
        if (vec_nc[i]>0 && vec_np[i]>0)
        {
            sum += vec_nc[i] * vec_np[i];
        }
        else
        {
            break;
        }
    }
    for (long long int i = NC - 1, j = NP - 1; i >= 0 && j >= 0; --i, --j)
    {
        if (vec_nc[i]<0&&vec_np[j]<0)
        {
            sum += vec_nc[i] * vec_np[j];
        }
        else
        {
            break;
        }
    }
    cout << sum << endl;
    return 0;
}