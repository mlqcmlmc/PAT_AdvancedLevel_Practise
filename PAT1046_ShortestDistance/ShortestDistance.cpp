#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
#define MAXNUM 10000001
int sum[MAXNUM] = { 0 };
int main()
{
    int N;
    cin >> N;
    int temp;
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &temp);
        sum[i] = sum[i - 1] + temp;
    }
    int M;
    int pos1, pos2;
    int distance_;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d %d", &pos1, &pos2);
        int pos_l = pos1 <= pos2 ? pos1 : pos2;
        int pos_r = pos1 >= pos2 ? pos1 : pos2;
        int right_ = sum[pos_r-1] - sum[pos_l-1];
        int left_ = (sum[N] - sum[pos_r-1]) + (sum[pos_l-1] - sum[0]);
        distance_ = right_<left_?right_ : left_;
        printf("%d\n", distance_);
    }
    return 0;
}