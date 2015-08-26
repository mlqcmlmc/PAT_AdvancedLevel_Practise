#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string in_str;
    getline(cin, in_str);
    int longest = 0;
    if (in_str.size()!=0)
    {
        longest = 1;
    }
    for (int i = 1; i < in_str.size(); ++i)
    {

        for (int j = 1; i - j>=0 && i + j < in_str.size(); j++)
        {
            if (in_str[i - j] != in_str[i + j])
            {
                break;
            }
            longest = max(longest, (j * 2 + 1));
        }
        for (int k = 1; i - k>=0 && i + k - 1 < in_str.size(); k++)
        {
            if (in_str[i - k] != in_str[i + k - 1])
            {
                break;
            }
            longest = max(longest, 2 * k);
        }
    }
    cout << longest << endl;
    return 0;

}