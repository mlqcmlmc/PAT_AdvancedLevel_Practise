//basic B里面也有这道题
//1014	福尔摩斯的约会
#include<iostream>
#include<string>
using namespace std;
int main(int argc, char* argv[])
{
    string str1, str2, str3, str4;
    int flag = 0, N;
    string DAY[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    cin >> str1 >> str2 >> str3 >> str4;
    if (str1.size() <= str2.size())
        N = str1.size();
    else
        N = str2.size();
    for (int i = 0; i < N; i++)
    {
        if (str1[i] >= 'A'&&str1[i] <= 'G' && (!flag))
        {
            if (str1[i] == str2[i])
            {
                cout << DAY[str1[i] - 'A'] << ' ';
                flag = 1;
                continue;
            }
        }
        if (flag)
        {
            if ((str1[i] >= 'A'&&str1[i] <= 'N') || (str1[i] >= '0'&&str1[i] <= '9'))
            {
                if (str1[i] == str2[i])
                {
                    if (str1[i] >= 'A'&&str1[i] <= 'N')
                    {
                        cout << str1[i] - 'A' + 10 << ':';
                    }
                    else
                        cout << '0' << str1[i] - '0' << ':';
                    break;
                }
            }
        }
    }
    if (str3.size() <= str4.size())
        N = str3.size();
    else
        N = str4.size();

    for (int i = 0; i < N; i++)
    {
        if ((str3[i] >= 'A'&&str3[i] <= 'Z') || (str3[i] >= 'a'&&str3[i] <= 'z'))
        {
            if (str3[i] == str4[i])
            {
                if (i < 10)
                    cout << '0';
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

