#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < K; ++i)
    {
        stack<int> stack_;
        bool flag = true;
        int cur = 1;
        for (int j = 0; j < N;++j)
        {
            int num;
            scanf("%d", &num);
            while (stack_.empty()||stack_.top()!=num)
            {
                stack_.push(cur);
                if (stack_.size()>M)
                {
                    flag = false;
                    break;
                }
                ++cur;
            }
            if (flag && (!stack_.empty()) && stack_.top() == num)
            {
                stack_.pop();
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else 
        {
            printf("NO\n");
        }
    }
    return 0;
}