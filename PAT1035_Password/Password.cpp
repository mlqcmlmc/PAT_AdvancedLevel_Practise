#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Users
{
    string name;
    string password;
};
int main()
{
    int N;
    int flag = 0;
    cin >> N;
    vector<Users> modify;
    Users temp;
    for (int i = 0; i < N; ++i)
    {
        flag = 0;
        cin >> temp.name >> temp.password;
        for (int j = 0; j < temp.password.size(); ++j)
        {
            if (temp.password[j] == '1')
            {
                temp.password[j] = '@';
                flag = 1;
            }
            else if (temp.password[j] == 'l')
            {
                temp.password[j] = 'L';
                flag = 1;
            }
            else if (temp.password[j] == '0')
            {
                temp.password[j] = '%';
                flag = 1;
            }
            else if (temp.password[j] == 'O')
            {
                temp.password[j] = 'o';
                flag = 1;
            }
        }
        if (flag)
        {
            modify.push_back(temp);
        }
    }
    if (modify.empty())
    {
        if (N==1)
        {
            printf("There is %d account and no account is modified", N);
        } 
        else
        {
            printf("There are %d accounts and no account is modified", N);
        }
    } 
    else
    {
        cout << modify.size() << endl;
        for (int i = 0; i < modify.size(); ++i)
        {
            cout << modify[i].name << ' ' << modify[i].password << endl;
        }
    }
    return 0;
}