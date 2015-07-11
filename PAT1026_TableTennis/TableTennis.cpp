#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include"stdio.h"
using namespace std;
#define CLUB_OPEN (8*3600)
#define ClUB_CLOSE (21*3600)

struct Player
{
	long int arrive_time;
	long int serve_time;
	long int play_time;
	long int wait_time;
	int tag;
};
struct Table
{
	int avai_time = CLUB_OPEN;	//桌子available的时间
	int table_No;
	int count = 0;				//服务了多少组
	bool isVip = false;				//是否为VIP桌子
};
bool CmpPlayer(Player a, Player b)
{
	return a.arrive_time < b.arrive_time;
}
bool CmpTable(Table a, Table b)
{
	if (a.avai_time == b.avai_time)
	{
		return a.table_No < b.table_No;
	}
	else
	{
		return a.avai_time < b.avai_time;
	}
}
int main()
{
	int N;
	cin >> N;
	vector<Player> players;
	players.resize(N);
	int hour, minute, second, palytime, tag;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &palytime, &tag);
		players[i].arrive_time = hour * 3600 + minute * 60 + second;
		players[i].play_time = palytime * 60;
		players[i].tag = tag;
	}
	int K, M;
	cin >> K >> M;
	vector<Table> tables, vip_tables;
	vip_tables.resize(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> vip_tables[i].table_No;
		vip_tables[i].isVip = true;
	}
	tables.resize(K - M);
	for (int i = 0, j = 0; (i < K - M)&(j < vip_tables.size()); ++i)
	{
		while (i + j + 1 >= vip_tables[j].table_No)
		{
			++j;
		}
		tables[i].table_No = i + j + 1;
		tables[i].isVip = false;
	}

	sort(players.begin(), players.end(),CmpPlayer);
	vector<Player> served_players;
	queue<Player> ave_wait, vip_wait;
	for (int i = 0; i < N; ++i)
	{
		sort(tables.begin(), tables.end(),CmpTable);
		sort(vip_tables.begin(), vip_tables.end(), CmpTable);
		if (ave_wait.empty() && vip_wait.empty())
		{
			if (players[i].tag == 1 && players[i].arrive_time >= vip_tables[0].avai_time)
			{
				++vip_tables[0].count;
				vip_tables[0].avai_time = players[i].arrive_time + players[i].play_time;
				players[i].serve_time = players[i].arrive_time;
				served_players.push_back(players[i]);
			}
			else if (players[i].tag == 1 && players[i].arrive_time >= tables[0].avai_time)
			{
				++tables[0].count;
				tables[0].avai_time = players[i].arrive_time + players[i].play_time;
				players[i].serve_time = players[i].arrive_time;
				served_players.push_back(players[i]);
			}
			else if ((players[i].tag == 0) && (tables[0].avai_time<vip_tables[0].avai_time) && (players[i].arrive_time >= tables[0].avai_time))
			{
				++tables[0].count;
				tables[0].avai_time = players[i].arrive_time + players[i].play_time;
				players[i].serve_time = players[i].arrive_time;
				served_players.push_back(players[i]);
			}
			else if ((players[i].tag == 0) && (tables[0].avai_time>vip_tables[0].avai_time) && (players[i].arrive_time >= vip_tables[0].avai_time))
			{
				++vip_tables[0].count;
				vip_tables[0].avai_time = players[i].arrive_time + players[i].play_time;
				players[i].serve_time = players[i].arrive_time;
				served_players.push_back(players[i]);
			}
			else if ((players[i].tag == 0) && (tables[0].avai_time == vip_tables[0].avai_time) && (players[i].arrive_time >= vip_tables[0].avai_time))
			{
				if (tables[0].table_No < vip_tables[0].table_No)
				{
					++tables[0].count;
					tables[0].avai_time = players[i].arrive_time + players[i].play_time;
					players[i].serve_time = players[i].arrive_time;
					served_players.push_back(players[i]);
				}
				else
				{
					++vip_tables[0].count;
					vip_tables[0].avai_time = players[i].arrive_time + players[i].play_time;
					players[i].serve_time = players[i].arrive_time;
					served_players.push_back(players[i]);
				}
			}
			else
			{
				if (players[i].tag)
				{
					vip_wait.push(players[i]);
				}
				else
				{
					ave_wait.push(players[i]);
				}
			}
		}
		else
		{
			if (players[i].tag)
			{
				vip_wait.push(players[i]);
			}
			else
			{
				ave_wait.push(players[i]);
			}
			//处理队列中的数据
			//if (!ave_wait.empty() && vip_wait.empty())
			//{
   //             while (!ave_wait.empty() && (players[i].arrive_time >= vip_tables[0].avai_time
   //                 || players[i].arrive_time >= tables[0].avai_time))
			//	{
			//		if ((tables[0].avai_time < vip_tables[0].avai_time) || 
			//			(tables[0].avai_time == vip_tables[0].avai_time && tables[0].table_No < vip_tables[0].table_No))
			//		{
			//			ave_wait.front().wait_time = tables[0].avai_time - ave_wait.front().arrive_time;
			//			ave_wait.front().serve_time = tables[0].avai_time;
			//			++tables[0].count;
			//			tables[0].avai_time = tables[0].avai_time + ave_wait.front().play_time;
			//			served_players.push_back(ave_wait.front());
			//		}
			//		else
			//		{
			//			ave_wait.front().wait_time = vip_tables[0].avai_time - ave_wait.front().arrive_time;
			//			ave_wait.front().serve_time = vip_tables[0].avai_time;
			//			++vip_tables[0].count;
			//			vip_tables[0].avai_time = vip_tables[0].avai_time + ave_wait.front().play_time;
			//			served_players.push_back(ave_wait.front());
			//		}
			//		ave_wait.pop();
			//		sort(tables.begin(), tables.end(), CmpTable);
			//		sort(vip_tables.begin(), vip_tables.end(), CmpTable);
			//	}
			//}
			//else if (!vip_wait.empty() && ave_wait.empty())
			//{
   //             while (!vip_wait.empty() && (players[i].arrive_time >= vip_tables[0].avai_time
   //                 || players[i].arrive_time >= tables[0].avai_time))
			//	{
			//		if (tables[0].avai_time >= vip_tables[0].avai_time)
			//		{
			//			vip_wait.front().wait_time = vip_tables[0].avai_time - vip_wait.front().arrive_time;
			//			vip_wait.front().serve_time = vip_tables[0].avai_time;
			//			++vip_tables[0].count;
			//			vip_tables[0].avai_time = vip_tables[0].avai_time + vip_wait.front().play_time;
			//			served_players.push_back(vip_wait.front());
			//		}
			//		else
			//		{
			//			vip_wait.front().wait_time = tables[0].avai_time - vip_wait.front().arrive_time;
			//			vip_wait.front().serve_time = tables[0].avai_time;
			//			++tables[0].count;
			//			tables[0].avai_time = tables[0].avai_time + vip_wait.front().play_time;
			//			served_players.push_back(vip_wait.front());
			//		}
			//		vip_wait.pop();
			//		sort(tables.begin(), tables.end(), CmpTable);
			//		sort(vip_tables.begin(), vip_tables.end(), CmpTable);
			//	}
			//}
			//else if (!vip_wait.empty() && !ave_wait.empty())
			//{
				//还有最后一种情况没有写完
                
                while (!vip_wait.empty() && !ave_wait.empty() && (players[i].arrive_time >= vip_tables[0].avai_time
                    || players[i].arrive_time >= tables[0].avai_time))
                {
                    if (tables[0].avai_time >= vip_tables[0].avai_time)
                    {
                        vip_wait.front().wait_time = vip_tables[0].avai_time - vip_wait.front().arrive_time;
                        vip_wait.front().serve_time = vip_tables[0].avai_time;
                        ++vip_tables[0].count;
                        vip_tables[0].avai_time = vip_tables[0].avai_time + vip_wait.front().play_time;
                        served_players.push_back(vip_wait.front());
                        vip_wait.pop();
                        sort(tables.begin(), tables.end(), CmpTable);
                        sort(vip_tables.begin(), vip_tables.end(), CmpTable);
                    }
                    else
                    {
                        if (vip_wait.front().arrive_time > ave_wait.front().arrive_time)
                        {
                            ave_wait.front().wait_time = tables[0].avai_time - ave_wait.front().arrive_time;
                            ave_wait.front().serve_time = tables[0].avai_time;
                            ++tables[0].count;
                            tables[0].avai_time = tables[0].avai_time + ave_wait.front().play_time;
                            served_players.push_back(ave_wait.front());
                            ave_wait.pop();
                            sort(tables.begin(), tables.end(), CmpTable);
                            sort(vip_tables.begin(), vip_tables.end(), CmpTable);
                        }
                        else
                        {
                            vip_wait.front().wait_time = tables[0].avai_time - vip_wait.front().arrive_time;
                            vip_wait.front().serve_time = tables[0].avai_time;
                            ++tables[0].count;
                            tables[0].avai_time = tables[0].avai_time + vip_wait.front().play_time;
                            served_players.push_back(vip_wait.front());
                            vip_wait.pop();
                            sort(tables.begin(), tables.end(), CmpTable);
                            sort(vip_tables.begin(), vip_tables.end(), CmpTable);
                        }


                    }
                }
                while (!ave_wait.empty() && (players[i].arrive_time >= vip_tables[0].avai_time
                    || players[i].arrive_time >= tables[0].avai_time))
                {
                    if ((tables[0].avai_time < vip_tables[0].avai_time) ||
                        (tables[0].avai_time == vip_tables[0].avai_time && tables[0].table_No < vip_tables[0].table_No))
                    {
                        ave_wait.front().wait_time = tables[0].avai_time - ave_wait.front().arrive_time;
                        ave_wait.front().serve_time = tables[0].avai_time;
                        ++tables[0].count;
                        tables[0].avai_time = tables[0].avai_time + ave_wait.front().play_time;
                        served_players.push_back(ave_wait.front());
                    }
                    else
                    {
                        ave_wait.front().wait_time = vip_tables[0].avai_time - ave_wait.front().arrive_time;
                        ave_wait.front().serve_time = vip_tables[0].avai_time;
                        ++vip_tables[0].count;
                        vip_tables[0].avai_time = vip_tables[0].avai_time + ave_wait.front().play_time;
                        served_players.push_back(ave_wait.front());
                    }
                    ave_wait.pop();
                    sort(tables.begin(), tables.end(), CmpTable);
                    sort(vip_tables.begin(), vip_tables.end(), CmpTable);
                }
                while (!vip_wait.empty() && (players[i].arrive_time >= vip_tables[0].avai_time
                    || players[i].arrive_time >= tables[0].avai_time))
                {
                    if (tables[0].avai_time >= vip_tables[0].avai_time)
                    {
                        vip_wait.front().wait_time = vip_tables[0].avai_time - vip_wait.front().arrive_time;
                        vip_wait.front().serve_time = vip_tables[0].avai_time;
                        ++vip_tables[0].count;
                        vip_tables[0].avai_time = vip_tables[0].avai_time + vip_wait.front().play_time;
                        served_players.push_back(vip_wait.front());
                    }
                    else
                    {
                        vip_wait.front().wait_time = tables[0].avai_time - vip_wait.front().arrive_time;
                        vip_wait.front().serve_time = tables[0].avai_time;
                        ++tables[0].count;
                        tables[0].avai_time = tables[0].avai_time + vip_wait.front().play_time;
                        served_players.push_back(vip_wait.front());
                    }
                    vip_wait.pop();
                    sort(tables.begin(), tables.end(), CmpTable);
                    sort(vip_tables.begin(), vip_tables.end(), CmpTable);
                }

			//}

		}
	}

	return 0;
}