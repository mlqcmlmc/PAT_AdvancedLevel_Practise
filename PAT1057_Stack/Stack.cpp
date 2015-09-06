#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include "stdio.h"
using namespace std;
int main()
{
    int N;
    cin >> N;
    char command[11];
    char pop_[11] = "Pop";
    char peek_[11] = "PeekMedian";
    char push_[11] = "Push";

    
    stack<int> stack_;
    multiset<int> mset;
    for (int i = 0; i < N;++i)
    {
        scanf("%s", command);
        if (strcmp(command , pop_)==0)
        {
            if (stack_.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                printf("%d\n", stack_.top());
                auto ite = mset.find(stack_.top());
                mset.erase(ite);
                stack_.pop();
            }
        }
        if (strcmp(command , peek_) == 0)
        {
            if (stack_.empty())
            {
                printf("Invalid\n");
            }
            else
            {
                auto ite = mset.begin();
                int peek_median;

                if (mset.size()%2==0)
                {
                    int index_ = mset.size() / 2 - 1;
                    while (index_)
                    {
                        ++ite;
                        --index_;
                    }
                    peek_median = *ite;
                }
                else
                {
                    int index_ = (mset.size()+1) / 2 - 1;
                    while (index_)
                    {
                        ++ite;
                        --index_;
                    }
                    peek_median = *ite;
                }

                printf("%d\n", peek_median);
            }
        }
        if (strcmp(command, push_) == 0)
        {
            int value_;
            scanf("%d", &value_);
           // cin >> value_;
            stack_.push(value_);
            mset.insert(value_);
        }
    }
    return 0;
}