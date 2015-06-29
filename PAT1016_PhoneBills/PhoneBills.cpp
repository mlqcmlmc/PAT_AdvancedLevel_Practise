#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"stdio.h"
using namespace std;

double eachhour[24];
double daybill = 0.0;
int N;

struct CallRecord
{
    string name;
    string time;
    string tag;
};
struct TimeInt
{
    int month;
    int day;
    int hour;
    int minute;
};
struct CustomerRecords
{
    string name;
    int month;
    vector<TimeInt> onlinetime;
    vector<TimeInt> offlinetime;

};

bool cmp(CallRecord a, CallRecord b)
{
    if (a.name == b.name)
    {
        return a.time < b.time;
    }
    else
    {
        return a.name < b.name;
    }
}

vector<CustomerRecords> CreatCustomers(vector<CallRecord> all_callrecord)
{
    vector<CustomerRecords> allrecords;
    CustomerRecords customer_records;
    TimeInt time2int;
    string lastname = "", last_record_name = "";
    int online_flag = 0;
    for (int i = 0; i < N; ++i)
    {
        if (lastname == all_callrecord[i].name)
        {
            if (online_flag == 1 && all_callrecord[i].tag == "off-line")
            {
                if (last_record_name != all_callrecord[i].name)
                {
                    time2int.month = stoi(all_callrecord[i - 1].time.substr(0, 2));
                    time2int.day = stoi(all_callrecord[i - 1].time.substr(3, 2));
                    time2int.hour = stoi(all_callrecord[i - 1].time.substr(6, 2));
                    time2int.minute = stoi(all_callrecord[i - 1].time.substr(9, 2));
                    customer_records.onlinetime.push_back(time2int);

                    time2int.month = stoi(all_callrecord[i].time.substr(0, 2));
                    time2int.day = stoi(all_callrecord[i].time.substr(3, 2));
                    time2int.hour = stoi(all_callrecord[i].time.substr(6, 2));
                    time2int.minute = stoi(all_callrecord[i].time.substr(9, 2));
                    customer_records.offlinetime.push_back(time2int);

                    customer_records.name = all_callrecord[i].name;
                    customer_records.month = time2int.month;

                    allrecords.push_back(customer_records);

                    customer_records.onlinetime.clear();
                    customer_records.offlinetime.clear();
                    last_record_name = all_callrecord[i].name;
                }
                else
                {
                    time2int.month = stoi(all_callrecord[i - 1].time.substr(0, 2));
                    time2int.day = stoi(all_callrecord[i - 1].time.substr(3, 2));
                    time2int.hour = stoi(all_callrecord[i - 1].time.substr(6, 2));
                    time2int.minute = stoi(all_callrecord[i - 1].time.substr(9, 2));
                    allrecords[allrecords.size() - 1].onlinetime.push_back(time2int);

                    time2int.month = stoi(all_callrecord[i].time.substr(0, 2));
                    time2int.day = stoi(all_callrecord[i].time.substr(3, 2));
                    time2int.hour = stoi(all_callrecord[i].time.substr(6, 2));
                    time2int.minute = stoi(all_callrecord[i].time.substr(9, 2));
                    allrecords[allrecords.size() - 1].offlinetime.push_back(time2int);


                    customer_records.onlinetime.clear();
                    customer_records.offlinetime.clear();
                }


                online_flag == 0;
            }
            else if (all_callrecord[i].tag == "on-line")
            {
                online_flag = 1;
            }
        }
        else
        {
            if (all_callrecord[i].tag == "on-line")
            {
                online_flag = 1;
            }

            lastname = all_callrecord[i].name;
        }
    }
    

    return allrecords;
}

bool isHourEqual(const TimeInt a, const TimeInt b)
{
    if ((a.day == b.day) && (a.hour == b.hour))
    {
        return 1;
    }
    else
    {
        return 0;

    }
}
long double CalculateBill(const TimeInt online, const TimeInt offline)
{
    long double bill = 0.0;
    TimeInt begin = online;
    TimeInt end = offline;
    bill += eachhour[begin.hour] * (60 - begin.minute);
    ++begin.hour;
    begin.minute = 0;
    if ((begin.day < end.day) && (begin.hour <= end.hour))
    {
        bill += (end.day - begin.day)*daybill;
        begin.day = end.day;
    }
    while (!isHourEqual(begin, end))
    {
        bill += eachhour[begin.hour] * 60;
        ++begin.hour;
        if (begin.hour >= 24)
        {
            begin.hour = 0;
            ++begin.day;
        }
    }
    bill += eachhour[end.hour] * end.minute;
    return bill;
}
int main()
{
    for (int i = 0; i < 24; ++i)
    {
        cin >> eachhour[i];
        eachhour[i] = eachhour[i] / 100.0;
        daybill += eachhour[i];
    }
    daybill = daybill * 60;
    cin >> N;
    vector<CallRecord> all_callrecord;
    CallRecord temp;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp.name >> temp.time >> temp.tag;
        all_callrecord.push_back(temp);
    }
    sort(all_callrecord.begin(), all_callrecord.end(), cmp);
    
    vector<CustomerRecords> allrecords = CreatCustomers(all_callrecord);

    string str_online_time, str_offline_time;
    long int lasting_time, online_time, offline_time;
    long double bill = 0.0, sumbill = 0.0;
    for (int i = 0; i < allrecords.size(); ++i)
    {
        sumbill = 0.0;
        cout << allrecords[i].name << ' ';
        printf("%02d\n", allrecords[i].month);
        for (int j = 0; j < allrecords[i].onlinetime.size(); ++j)
        {
            printf("%02d:%02d:%02d ", allrecords[i].onlinetime[j].day, allrecords[i].onlinetime[j].hour, allrecords[i].onlinetime[j].minute);
            printf("%02d:%02d:%02d ", allrecords[i].offlinetime[j].day, allrecords[i].offlinetime[j].hour, allrecords[i].offlinetime[j].minute);

            offline_time = (allrecords[i].offlinetime[j].day * 24 + allrecords[i].offlinetime[j].hour) * 60 + allrecords[i].offlinetime[j].minute;
            online_time = (allrecords[i].onlinetime[j].day * 24 + allrecords[i].onlinetime[j].hour) * 60 + allrecords[i].onlinetime[j].minute;
            lasting_time = offline_time - online_time;
            bill = CalculateBill(allrecords[i].onlinetime[j], allrecords[i].offlinetime[j]);
            sumbill += bill;
            printf("%d $%.2f\n", lasting_time, bill);
        }
        printf("Total amount: $%.2f\n", sumbill);

    }

    return 0;
}