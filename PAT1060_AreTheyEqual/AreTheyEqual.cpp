//题意：将两个float型数据使用科学计数法表示，并比较两者是否相同
//关键：要考虑所给输入数据的多种情况，比如 0,0.0,0.0123,05.032,00.020等这种比较特殊的情况。
#include <iostream>  
#include <fstream>  
#include <cstring>  

using namespace std; 

int convert(const char* c, int n, char* &res)
{
    int exponent = 0;
    int index_ = 0;
    int res_index = 0;
    while (c[index_] == '0')
    {
        ++index_;
    }
    int begin_ = index_;
    if (c[index_] == '.')
    {
        exponent = 0;
        ++index_;
        while (c[index_] == '0' && c[index_] != '\0')
        {
            --exponent;
            ++index_;
        }
        if (c[index_] == '\0')
        {
            exponent = 0;
        }
        while (c[index_] != '\0'&&res_index < n)
        {
            res[res_index] = c[index_];
            ++index_;
            ++res_index;
        }

    }
    else
    {

        while (c[index_] != '\0'&&res_index < n)
        {
            if (c[index_]=='.')
            {
                exponent = index_ - begin_;
                ++index_;
            }
            else
            {
                res[res_index] = c[index_];
                ++index_;
                ++res_index;
            }
        }
        if (exponent==0)
        {
            while (c[index_] != '\0'&&c[index_] != '.')
                ++index_;
            exponent = index_ - begin_;
        }
    }

    while (res_index < n)//不足则后面补0
    {
        res[res_index] = '0';
        ++res_index;
    }
    res[n] = '\0';
    return exponent;
}

int main()
{
    int n;
    cin >> n;
    char A[105], B[105];
    cin >> A >> B;
    int Ac, Bc;
    char *Ares, *Bres;
    Ares = new char[n + 1];
    Bres = new char[n + 1];
    Ac = convert(A, n, Ares);
    Bc = convert(B, n, Bres);
    if (Ac == Bc && strcmp(Ares, Bres) == 0)
    {
        cout << "YES 0." << Ares << "*10^" << Ac << endl;
    }
    else
    {
        cout << "NO 0." << Ares << "*10^" << Ac << " 0." << Bres << "*10^" << Bc << endl;
    }
    return 0;
}