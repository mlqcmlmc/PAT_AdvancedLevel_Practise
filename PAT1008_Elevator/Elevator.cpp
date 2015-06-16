#include<iostream>

using namespace std;
int main()
{
    int N;
    cin >> N;
    int floor = 0, lastfloor = 0;
    int total_time = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> floor;
        if ((floor - lastfloor)>0)
        {
            total_time += (floor - lastfloor) * 6;
        }
        else if ((floor - lastfloor) < 0)
        {
            total_time += (lastfloor - floor) * 4;
        }
        lastfloor = floor;
        total_time += 5;
    }
    cout << total_time << endl;
    return 0;
}