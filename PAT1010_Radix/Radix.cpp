#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char, int> numbers = {  { '0', 0 }, { '1', 1 }, { '2', 2 }, { '3', 3 }, { '4',  4}, { '5', 5 }, { '6', 6 }, { '7', 7 }, { '8', 8 }, { '9', 9 }, 
                            { 'a', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, 
                            { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, 
                            { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }, { '0', 0 }}
/*����str_num,��radix1 ����ת��Ϊradix2���ƣ�����radix2���Ƶ�����*/
string RadixConversion(char c_radix1, char c_radix2, string str_num)
{
    int radix1_decimal, radix2_decimal;
    if (c_radix1 >= '0'&&c_radix1 <= '9')
    {
        radix1_decimal = c_radix1 - '0';
    }
    else if (c_radix1 >= 'a'&&c_radix1 <= 'z')
    {
        radix1_decimal = c_radix1 - 'a' + 10;
    }
    if (c_radix2 >= '0'&&c_radix2 <= '9')
    {
        radix2_decimal = c_radix2 - '0';
    }
    else if (c_radix2 >= 'a'&&c_radix2 <= 'z')
    {
        radix2_decimal = c_radix2 - 'a' + 10;
    }


}

int main()
{
    string str_N1, str_N2, str_radix;
    int tag;
    cin >> str_N1 >> str_N2 >> tag >> str_radix;
    if (tag)

        RadixConversion()
}