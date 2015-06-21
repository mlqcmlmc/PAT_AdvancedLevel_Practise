#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include"stdio.h"
using namespace std;

pair<char, double> dmax(double W, double T, double L)
{
    pair<char, double> game;
    if (W > T&&W > L)
    {
        game.first = 'W';
        game.second = W;
    }
    else if (T > W&&T > L)
    {
        game.first = 'T';
        game.second = T;
    }
    else
    {
        game.first = 'L';
        game.second = L;
    }
    return game;
}
int main()
{
    vector<pair<char, double>> games;
    games.resize(3);
    double W, T, L;
    for (int i = 0; i < 3; i++)
    {
        cin >> W >> T >> L;
        games[i] = dmax(W, T, L);
        cout << games[i].first << ' ';
    }
    double maxprofit = (games[0].second*games[1].second*games[2].second*0.65 - 1) * 2;
    printf("%.2f", maxprofit);
    cout << endl;
    return 0;
}