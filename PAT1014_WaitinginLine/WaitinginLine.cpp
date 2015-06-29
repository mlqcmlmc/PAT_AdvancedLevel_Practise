#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include"stdio.h"
using namespace std;
int N, M, K, Q;
struct Window
{
    int mark = 0;
    int window_first = 0;
    int window_last = 0;
    queue<int> window_time;
};
bool cmp(Window a, Window b)
{
    if (a.window_first == b.window_first) return a.mark < b.mark;
    else return a.window_first < b.window_first;
}
int main()
{
    cin >> N >> M >> K >> Q;
    vector<int> left_time, serve_time;
    vector<Window> windows;
    windows.resize(N);
    for (int i = 0; i < N; ++i)
    {
        windows[i].mark = i;
    }
    int temp_time;
    for (int i = 0; i < K; ++i)
    {
        cin >> temp_time;
        if (windows[i%N].window_time.size() < M - 1)
        {
            windows[i%N].window_time.push(temp_time);
            windows[i%N].window_last += temp_time;			//����ÿ�����ڵ����һ���˵��뿪ʱ��
            left_time.push_back(windows[i%N].window_last);	//����ÿ���˿͵��뿪ʱ��
        }
        else if (windows[i%N].window_time.size() == M - 1)
        {
            windows[i%N].window_time.push(temp_time);
            windows[i%N].window_last += temp_time;			//����ÿ�����ڵ����һ���˵��뿪ʱ��
            auto data = windows[i%N].window_time.front();
            windows[i%N].window_first += data;				//����ÿ�����ڵĵ�һ���˵��뿪ʱ��
            left_time.push_back(windows[i%N].window_last);	//����ÿ���˿͵��뿪ʱ��
        }
        else
        {
            sort(windows.begin(), windows.end(), cmp);		//����ÿ�����ڵ�һ���˽�Ҫ�뿪����Сʱ��
            windows[0].window_time.push(temp_time);
            windows[0].window_last += temp_time;			//����ÿ�����ڵ����һ���˵��뿪ʱ��
            windows[0].window_time.pop();
            auto data = windows[0].window_time.front();
            windows[0].window_first += data;				//����ÿ�����ڵĵ�һ���˵��뿪ʱ��
            left_time.push_back(windows[0].window_last);	//����ÿ���˿͵��뿪ʱ��
        }
        serve_time.push_back(left_time[i] - temp_time);
    }
    int out_customer, shi, fen;
    for (int i = 0; i < Q; ++i)
    {
        cin >> out_customer;
        // �������׳���ĵط�������17:00���Ժ�ʼ����Ŀͻ����"Sorry"��������17 : 00֮ǰ������������"Sorry"��
        //��ͻ�cId��16:59��ʼ���񣬷���ʱ��Ϊ2���������Ӧ����17:01��������"Sorry"��
        if (serve_time[out_customer - 1] < 540)
        {
            shi = 8 + left_time[out_customer - 1] / 60;
            fen = left_time[out_customer - 1] % 60;
            printf("%02d:%02d", shi, fen);
            printf("\n");
        }
        else
        {
            cout << "Sorry" << endl;
        }
    }
    return 0;
}