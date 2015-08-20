#include <iostream>
#include<string>
using namespace std;
struct Student
{
    string name;
    char gender;
    string id;
    int grade;

};
int main()
{
    Student f_highgrade, m_lowgrade, temp_stu;
    f_highgrade.grade = -1;
    m_lowgrade.grade = 101;
    long int N;
    cin >> N;
    for (long int i = 0; i < N; ++i)
    {
        cin >> temp_stu.name >> temp_stu.gender >> temp_stu.id >> temp_stu.grade;
        if (temp_stu.gender == 'F')
        {
            if (temp_stu.grade>f_highgrade.grade)
            {
                f_highgrade = temp_stu;
            }
        }
        else
        {
            if (temp_stu.grade<m_lowgrade.grade)
            {
                m_lowgrade = temp_stu;
            }
        }
    }
    if (m_lowgrade.grade!=101&&f_highgrade.grade!=-1)
    {
        cout << f_highgrade.name << ' ' << f_highgrade.id << endl;
        cout << m_lowgrade.name << ' ' << m_lowgrade.id << endl;
        cout << f_highgrade.grade - m_lowgrade.grade << endl;
    }
    else if (f_highgrade.grade==-1)
    {
        cout << "Absent" << endl;
        cout << m_lowgrade.name << ' ' << m_lowgrade.id << endl;
        cout << "NA" << endl;
    }
    else if (m_lowgrade.grade==101)
    {
        cout << f_highgrade.name << ' ' << f_highgrade.id << endl;
        cout << "Absent" << endl;
        cout << "NA" << endl;
    }
    return 0;
}