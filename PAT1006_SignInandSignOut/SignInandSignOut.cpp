#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct  record
{
    string ID_number;
    string sign_in_time;
    string sign_out_time;
};


bool CmpSignInTime(record r1, record r2)
{
    return r1.sign_in_time < r2.sign_in_time;
}
bool CmpSignOutTime(record r1, record r2)
{
    return r1.sign_out_time > r2.sign_out_time;
}
int main()
{
    int M;
    cin >> M;
    vector<record> all_records;
    all_records.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> all_records[i].ID_number >> all_records[i].sign_in_time >> all_records[i].sign_out_time;
    }
    sort(all_records.begin(), all_records.end(), CmpSignInTime);
    cout << all_records[0].ID_number << ' ';
    sort(all_records.begin(), all_records.end(), CmpSignOutTime);
    cout << all_records[0].ID_number << endl;
    return 0;
}