#include <iostream>
using namespace std;

#define MAXN 10001
int a[MAXN];

int main()
{
    int K, count_negative = 0;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            count_negative++;
        }
    }
    if (count_negative == K)
    {
        cout << 0 << ' ' << a[0] << ' ' << a[K - 1] << endl;
        return 0;
    }
    int first_number = a[0], last_number = a[K - 1], first_index = 0;
    int summax = a[0], sum = 0;
    for (int i = 0; i<K; i++)
    {
        if (sum < 0)
        {
            sum = a[i];
            first_index = i;
        }
        else
        {
            sum += a[i];
        }

        if (sum > summax)
        {
            summax = sum;
            first_number = a[first_index];
            last_number = a[i];
        }
    }
    cout << summax << ' ' << first_number << ' ' << last_number << endl;
    return 0;
}
