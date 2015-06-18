/*个人感觉这个题目好多地方没有说清楚，假如说，你的输入是6 6 1 10时，你的输出应该是10呢还是7呢*/
//
//
//
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//
///*将radix进制的数字转换为10进制数字*/
//long long int RadixConvert2Decimal(string str_num, long long int radix)
//{
//    long long int num_decimal = 0;
//    for (int i = 0; i < str_num.size(); ++i)
//    {
//        if (str_num[i] >= 'a'&&str_num[i] <= 'z')
//            num_decimal = num_decimal * radix + str_num[i] - 'a' + 10;
//        else
//            num_decimal = num_decimal * radix + str_num[i] - '0';
//    }
//    return num_decimal;
//
//}
//
//long long int FindMinRadix(string str_num)
//{
//    int maxnum = -1;
//    int temp;
//    for (int i = 0; i < str_num.size(); ++i)
//    {
//        if (str_num[i] >= 'a'&&str_num[i] <= 'z')
//            temp = str_num[i] - 'a' + 10;
//        else
//            temp = str_num[i] - '0';
//        if (temp>maxnum)
//        {
//            maxnum = temp;
//        }
//    }
//    return maxnum + 1;
//}
//
//
//long long int BinarySearch(long long int L, long long int R, long long int value_decimal, string str_value_unknown)
//{
//    long long int mid;
//    long long int value_unknown;
//    while (L <= R)//如果L>R则不进入循环，直接返回-1
//    {
//        mid = (L + R) / 2;
//        value_unknown = RadixConvert2Decimal(str_value_unknown, mid);
//        if (value_unknown == value_decimal)
//        {
//            return mid;
//        }
//        else if ((value_unknown > value_decimal) || (value_unknown<0))
//        {
//            R = mid-1;
//        }
//        else
//        {
//            L = mid + 1;
//        }
//    }
//    return -1;
//}
//int main()
//{
//    string str_N1, str_N2;
//    int tag;
//    long long int radix;
//    cin >> str_N1 >> str_N2 >> tag >> radix;
//    string str_known, str_unknown;
//    if (tag == 1)
//    {
//        str_known = str_N1;
//        str_unknown = str_N2;
//    }
//    else
//    {
//        str_known = str_N2;
//        str_unknown = str_N1;
//    }
//    long long int value_decimal = RadixConvert2Decimal(str_known, radix);
//    long long int min_radix = FindMinRadix(str_unknown);
//    //long long int max_radix = max<long long>(value_decimal + 1, min_radix);
//    long long int max_radix = value_decimal+1;
//
//    long long int out_radix = BinarySearch(min_radix, max_radix, value_decimal, str_unknown);
//
//    if (out_radix == -1)
//    {
//        cout << "Impossible" << endl;
//    }
//    else 
//    {
//        cout << out_radix << endl;
//    }
//    return 0;
//}
//
//


#pragma warning (disable:4786)  
#include<iostream>  
#include<iomanip>  
#include<string>  
#include<cstdio>  
#include<algorithm>  
#include<map>  
using namespace std;

string a[3];
long long int  tag, radix;
long long int num1;

long long int tolongint(string s, long long int  dig)
{
    long long int ans = 0;
    long long int d = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int num;
        if (s[i] >= '0' && s[i] <= '9') num = s[i] - '0';
        else num = s[i] - 'a' + 10;

        ans = ans + num*d;
        d *= dig;
    }
    return ans;
}

int cmp(string s, long long int  dig)
{
    long long int ans = 0;
    long long int d = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int num;
        if (s[i] >= '0' && s[i] <= '9') num = s[i] - '0';
        else num = s[i] - 'a' + 10;

        ans = ans + num*d;
        if (ans>num1) return 1;
        d *= dig;
    }
    if (ans == num1) return 0;
    return -1;
}

int Maxnum(string s)
{
    int d = -1;
    for (int i = 0; i<s.size(); i++)
    {
        int num;
        if (s[i] >= '0' && s[i] <= '9') num = s[i] - '0';
        else num = s[i] - 'a' + 10;

        if (num>d) d = num;
    }
    return d + 1;
}

long long int Max(long long int a, long long int b)
{
    return a>b ? a : b;
}

long long int BinarySearch(int cur)
{
    long long int L = Maxnum(a[cur]);
    long long int R = Max(L, num1), M;

    while (L <= R)
    {
        M = (L + R) / 2;
        int res = cmp(a[cur], M);

        if (res == 0) return M;
        else if (res == 1) R = M - 1;
        else L = M + 1;
    }
    return -1;
}

int main()
{
    while (cin >> a[1] >> a[2] >> tag >> radix)
    {
        if (a[1] == "1" && a[2] == "1")
        {
            cout << "2" << endl;
            continue;
        }
        if (a[1] == a[2])
        {
            cout << radix << endl;
            continue;
        }
        num1 = tolongint(a[tag], radix);

        int cur;
        if (tag == 1) cur = 2;
        else cur = 1;

        long long int ans = BinarySearch(cur);

        if (ans == -1) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}