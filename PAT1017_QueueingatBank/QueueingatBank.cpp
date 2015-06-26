#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define BANK_OPEN (8*60*60)
#define BANK_CLOSE (17*60*60-BANK_OPEN)

struct CustomerTime
{
    long int arrive_time;
    int process_time;
};

bool cmp(CustomerTime a, CustomerTime b)
{
    return a.arrive_time < b.arrive_time;
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<CustomerTime> CustomerTimes;
    CustomerTimes.resize(N);
    string str_arrive_time;
    int hour, minute, second, processtime;
    for (int i = 0; i < N; ++i)
    {
        cin >> str_arrive_time >> processtime;
        CustomerTimes[i].process_time = processtime * 60;
        hour = (str_arrive_time[0] - '0') * 10 + (str_arrive_time[1] - '0');
        minute = (str_arrive_time[3] - '0') * 10 + (str_arrive_time[4] - '0');
        second = (str_arrive_time[6] - '0') * 10 + (str_arrive_time[7] - '0');
        CustomerTimes[i].arrive_time = hour * 60 * 60 + minute * 60 + second - BANK_OPEN;
    }
    sort(CustomerTimes.begin(), CustomerTimes.end(),cmp);       //按到达先后时间排序
    vector<long int> window_left_time;
    window_left_time.resize(K);
    long int wait_time_sum = 0, serve_num = 0;
    for (int i = 0; i < N; ++i)
    {
        sort(window_left_time.begin(), window_left_time.end()); //窗口离开时间排序，数字最小，则为下一个人进去窗口
        if (CustomerTimes[i].arrive_time>BANK_CLOSE)            //晚于17点，则不计入在内
        {
            continue;
        }
        ++serve_num;
        if (CustomerTimes[i].arrive_time <= window_left_time[0])
        {
            wait_time_sum += window_left_time[0] - CustomerTimes[i].arrive_time;
            window_left_time[0] = window_left_time[0] + CustomerTimes[i].process_time;
        }
        else
        {
            window_left_time[0] = CustomerTimes[i].arrive_time + CustomerTimes[i].process_time;
        }
    }
    double ave_wait_time = (double)(wait_time_sum) / (serve_num*60);
    printf("%.1f\n", ave_wait_time);

    return 0;
}