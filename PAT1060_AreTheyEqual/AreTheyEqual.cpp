#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N;
    string A, B;
    cin >> N >> A >> B;
    int exponent_A = 0;
    int exponent_B = 0;
    auto index_A = A.find('.');
    auto index_B = B.find('.');


    if (index_A == string::npos)
    {
        exponent_A = A.size();
    }
    else if (A[index_A-1]!='0')
    {
        exponent_A = index_A;
    }
    else
    {
        int index_ = index_A+1;
        while (index_ < A.size() && A[index_] == '0')
        {
            ++index_;
        }
        exponent_A = (index_ - index_A - 1);
        exponent_A = -exponent_A;
    }


    if (index_B == string::npos)
    {
        exponent_B = B.size();
    }
    else if (B[index_B - 1] != '0')
    {
        exponent_B = index_B;
    }
    else
    {
        int index_ = index_B + 1;
        while (index_ < B.size() && B[index_] == '0')
        {
            ++index_;
        }
        exponent_B = (index_ - index_B - 1);
        exponent_B = -exponent_B;
    }






    if (exponent_A == exponent_B&&exponent_A > 0)
    {
        if (exponent_A != A.size())
        {
            A.erase(exponent_A,1);
        }
        if (exponent_B != B.size())
        {
            B.erase(exponent_B,1);
        }
        if (N > A.size())
        {
            A.insert(A.size(), N - A.size(), '0');

        }
        if (N > B.size())
        {
            B.insert(B.size(), N - B.size(), '0');
        }
        string sub_A = A.substr(0, N);
        string sub_B = B.substr(0, N);
        if (sub_A==sub_B)
        {
            printf("YES");
            printf(" 0.%s*10^%d", sub_A.c_str(), exponent_A);
        }
        else
        {
            printf("NO");
            printf(" 0.%s*10^%d 0.%s*10^%d", sub_A.c_str(), exponent_A, sub_B.c_str(), exponent_A);
        }
    }
    else if (exponent_A == exponent_B&&exponent_A <= 0)
    {
        int index_ = 0;
        while (index_ < A.size() && (A[index_] == '0' || A[index_] == '.'))
        {
            ++index_;
        }
        A = A.substr(index_);
        while (index_ < B.size() && (B[index_] == '0' || B[index_] == '.'))
        {
            ++index_;
        }
        B = B.substr(index_);
        if (N > A.size())
        {
            A.insert(A.size(), N - A.size(), '0');

        }
        if (N > B.size())
        {
            B.insert(B.size(), N - B.size(), '0');
        }
        string sub_A = A.substr(0, N);
        string sub_B = B.substr(0, N);
        if (sub_A == sub_B)
        {
            printf("YES");
            printf(" 0.%s*10^%d", sub_A.c_str(), exponent_A);
        }
        else
        {
            printf("NO");
            printf(" 0.%s*10^%d 0.%s*10^%d", sub_A.c_str(), exponent_A, sub_B.c_str(), exponent_A);
        }
    }
    /*else
    {
        if (exponent_A != A.size())
        {
            A.erase(exponent_A, 1);
        }
        if (exponent_B != B.size())
        {
            B.erase(exponent_B, 1);
        }
        if (N > A.size())
        {
            A.insert(A.size(), N - A.size(), '0');

        }
        if (N > B.size())
        {
            B.insert(B.size(), N - B.size(), '0');
        }
        string sub_A = A.substr(0, N);
        string sub_B = B.substr(0, N);
        printf("NO");
        printf(" 0.%s*10^%d 0.%s*10^%d", sub_A.c_str(), exponent_A, sub_B.c_str(), exponent_B);
    }*/
    return 0;

}