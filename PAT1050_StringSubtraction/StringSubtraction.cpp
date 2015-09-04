#include <iostream>
#include <string>
using namespace std;
int ascii_[128] = { 0 };
int main()
{
    string S1, S2, remaining;
    getline(cin, S1);
    getline(cin, S2);
    for (int i = 0; i < S2.size();++i)
    {
        ascii_[S2[i]] = 1;
    }
    for (int i = 0; i < S1.size(); ++i)
    {
        if (!ascii_[S1[i]])
        {
            remaining.push_back(S1[i]);
        }
    }
    cout << remaining << endl;
    return 0;
}