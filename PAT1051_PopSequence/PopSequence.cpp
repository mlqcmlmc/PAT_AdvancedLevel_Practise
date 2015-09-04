#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    vector<int> sequence(N);
    for (int i = 0; i < N; ++i)
    {
        sequence[i] = i + 1;
    }
    vector<int> pop_sequence(N), push_sequence, stack_sequence;
    int stack_count = 0;
    for (int i = 0; i < K;++i)
    {
        push_sequence.clear();
        stack_sequence.clear();
        stack_count = 0;
        for (int j = 0; j < N;++j)
        {
            cin >> pop_sequence[j];
        }
        for (int h = N - 1; h >= 0;--h)
        {
            if (h>0 && pop_sequence[h] < pop_sequence[h - 1] && stack_count < M)
            {
                push_sequence.push_back(pop_sequence[h]);
                ++stack_count;
            }
            else
            {
                stack_sequence.push_back(pop_sequence[h]);
            }
        }
        reverse(stack_sequence.begin(), stack_sequence.end());
        push_sequence.insert(push_sequence.end(), stack_sequence.begin(), stack_sequence.end());
        if (push_sequence==sequence)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}