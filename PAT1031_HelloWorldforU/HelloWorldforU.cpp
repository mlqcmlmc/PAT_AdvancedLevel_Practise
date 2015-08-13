#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int n1, n2, n3;
    n1 = (str.size() + 2) / 3;
    n3 = n1;
    n2 = str.size() + 2 - n1 - n3;
    for (int i = 0; i < n1 - 1; ++i)
    {
        string str_line;
        str_line.push_back(str[i]);
        for (int j = 0; j < n2 - 2; ++j)
        {
            str_line.push_back(' ');
        }
        str_line.push_back(str[str.size() - 1 - i]);
        cout << str_line << endl;
        str_line.clear();
    }
    string last_line = str.substr(n1 - 1, n2);
    cout << last_line << endl;
    return 0;
}