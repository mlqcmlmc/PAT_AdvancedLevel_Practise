#define _CRT_SECURE_NO_WARNINGS
//用一个multiset会超时
//#include <iostream>
//#include <stack>
//#include <set>
//#include <vector>
//#include <string>
//#include <cstring>
//#include <algorithm>
//#include "stdio.h"
//using namespace std;
//int main()
//{
//    int N;
//    cin >> N;
//    char command[11];
//    char pop_[11] = "Pop";
//    char peek_[11] = "PeekMedian";
//    char push_[11] = "Push";    
//    stack<int> stack_;
//    multiset<int> vec;
//    for (int i = 0; i < N;++i)
//    {
//        scanf("%s", command);
//        if (strcmp(command , pop_)==0)
//        {
//            if (stack_.empty())
//            {
//                printf("Invalid\n");
//            }
//            else
//            {
//                printf("%d\n", stack_.top());
//                auto ite = find(vec.begin(), vec.end(), stack_.top());
//                vec.erase(ite);
//                stack_.pop();
//            }
//        }
//        if (strcmp(command , peek_) == 0)
//        {
//            if (stack_.empty())
//            {
//                printf("Invalid\n");
//            }
//            else
//            {
//                auto ite = vec.begin();
//                int peek_median;
//                int index_;
//                if (vec.size() % 2 == 0)
//                {
//                    index_ = vec.size() / 2 - 1;
//                }
//                else
//                {
//                    index_ = (vec.size() + 1) / 2 - 1;
//                }
//                while (index_--)
//                {
//                    ++ite;
//                }
//                peek_median = *ite;
//                printf("%d\n", peek_median);
//            }
//        }
//        if (strcmp(command, push_) == 0)
//        {
//            int value_;
//            scanf("%d", &value_);
//            stack_.push(value_);
//            vec.insert(value_);
//            //sort(vec.begin(), vec.end());
//        }
//    }
//    return 0;
//}

//用一个multiset会超时，用两个multiset进行调整，不会超时
#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include "stdio.h"
using namespace std;
#define INF 0x6fffffff  
multiset<int> minm, maxm;
stack<int> stack_;
int mid;
void adjust()
{
    multiset<int>::iterator it;
    if (maxm.size() + 1 < minm.size())
    {
        //如果小的部分大于大的部分，把小的中最大的元素移到大的当中  
        it = minm.end();
        --it;
        maxm.insert(*it);
        minm.erase(it);
    }
    else if (maxm.size() > minm.size())
    {
        //如果小的部分小于大的部分，把大的中最小的元素移到小的当中  
        it = maxm.begin();
        minm.insert(*it);
        maxm.erase(it);
    }
    if (stack_.size() > 0)
    {
        it = minm.end();
        --it;
        mid = *it;
    }
}
int main()
{
    int N;
    cin >> N;
    char command[11];
    char pop_[11] = "Pop";
    char peek_[11] = "PeekMedian";
    char push_[11] = "Push";    
   
    multiset<int> vec;
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
                if (mid >= stack_.top())
                {
                    auto ite = minm.find(stack_.top());
                    minm.erase(ite);
                }
                else
                {
                    auto ite = maxm.find(stack_.top());
                    maxm.erase(ite);
                }
                stack_.pop();
                adjust();//调整 
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
                printf("%d\n", mid);
            }
        }
        if (strcmp(command, push_) == 0)
        {
            int value_;
            scanf("%d", &value_);
            if (stack_.size() == 0)
            {
                minm.insert(value_);
                mid = value_;
            }
            else if (value_ <= mid)
                minm.insert(value_);
            else
                maxm.insert(value_);
            stack_.push(value_);
            adjust();//调整
        }
    }
    return 0;
}

////这里采用树状数组的解法
//#include<iostream>   
//#include<stack> 
//#define MAX 100001/*不多于100000_no more than 10^5.*/
//using namespace std;   
//int Countkey[MAX] = { 0 };
///*htt p://duanple.blog.163.com/blog/static/7097176720081131113145832/*/
//int lowBit_from_right_to_left_first_One(int key)
//{
//  return key&(-key);/*例子：比如二进制(key补码)000110  那么返回000010这个值是2;级别2=2^1;
//                                            100011  那么返回000001这个值是1;级别1=2^0;
//                                            101000  那么返回001000这个值是8;级别8=2^3;
//                                            000000  那么返回000000这个值是0;级别0;
//                      ------------------------------------
//            等价于key&(key^(key-1));
//            key不为零时最高能被2的k次方整除，结果就等于2^k;
//            当key结果为零时，结果为零；
//            ----------------------------------------------
//            key&(-key) 一种情况key为零，结果为0；
//            另一种情况假如key为正数，-key为负数在计算机中用补码表示
//            （-key补=key的原从低位（右边向左），在没有遇到第一个1包括第一个1都保持不变，接下去直到符号位包括符号位全变反[1变0，0变1]）
//            --------------------------------------------------
//            key&(key^(key-1)对于key与key-1的区别在于key减1的时候像高位借位，而借位的情况在二进制中当key的最低位为0，而要减去的是1，
//            显然，会被借位的最高位【从低位（右边向左），在遇到的第一个1】，所以key和key-1在这个1的左边本身全一样，在1的右边包括1全不一样；
//            key^(异或)key-1；按位异或，没有进位的加（同清零，不同置1），接着和原来的key按位与&没有进位的乘（1&1=1其他都为0）
//            显然key和key^(key-1只有刚刚1的那个位置一样且都为1；
//            */
//}
//void insertCountkey(int key,int add_dec)
//{
//  while (key <= MAX)
//  {
//    Countkey[key] += add_dec;
//    key += lowBit_from_right_to_left_first_One(key);
//  }/*设key的级别为2^k实现Countkey[key] 增加一个add或减少一个dec
//     接着对于级别大于2^k的第一个newkey实现Countkey[newkey]增加一个add标记或减少一个dec
//     注释：这些大于2^k的newkey=2^(k+1);2^(k+2)……<=MAX；
//          所以显然，只有Countkey[2^k]包含所有1<key<=2^k的数量
//                      Countkey[2^k+1]=Countkey[2^k+1];只包含他自己即key=2^k+1的数量；
//                      Countkey[2^k+2]=包含key=2^k+1和key=2^k+2的数量;
//      结合下面的low_and_函数，假如此时
//    low_and_(int*Countkey, int 2^k)那么直接获得sum+=Countkey[2^k],key=0;结束时sum=所有1<key<=2^k的数量
//    low_and_(int*Countkey, int 2^k+1)那么会先sum+=Countkey[2^k+1],key=2^k;接着sum+=Countkey[2^k],key=0；结束时sum=所有1<key<=2^k+1的数量;
//    low_and_(int*Countkey, int 2^k+2)那么会先sum+=Countkey[2^k+2],key=2^k;接着sum+=Countkey[2^k],key=0；结束时sum=所有1<key<=2^k+2的数量; 
//  */
//} 
//int low_and_(int key)
//{
//  int sum = 0;
//  while (key > 0)
//  {
//    sum += Countkey[key];
//    key -= lowBit_from_right_to_left_first_One(key);
//  }
//  return sum;/* 
//         下面的2^k是不断变动的。
//           如果这一key是n*2^k（n为奇数），那么会实现sum+和key-； 
//           如果这一key已经是2^k，那么最后一次key-=lowBit_from_right_to_left_first_One；
//                        (key=0；结束，由Binary indexed tree-树状数组 特性知道，此时的sum=Countkey[2^k]+……+Countkey[key最开始];
//                
//             */
//}
//int findmid(int mid)
//{
//  int low = 0, high = MAX ;
//  int midtemp,countSum;
//  while (low <= high)
//  {
//    midtemp = (low + high) / 2;
//    countSum = low_and_(midtemp);
//      if (countSum>= mid)high = midtemp-1;
//      else low = midtemp + 1;
//  }
//  return low;
//}
//void Push(stack<int>*Last_In_First_Out)
//{
//  int key;
//  scanf("%d", &key); 
//  (*Last_In_First_Out).push(key); 
//  insertCountkey(key,1);
//}
//void Pop(stack<int>*Last_In_First_Out)
//{
//  if ((*Last_In_First_Out).empty())printf("Invalid\n");
//  else 
//  {
//    printf("%d\n",Last_In_First_Out->top());
//    insertCountkey(Last_In_First_Out->top(), -1);
//    Last_In_First_Out->pop();
//  }
//}
//void PeekMedian(stack<int>*Last_In_First_Out)
//{
//
//  if ((*Last_In_First_Out).empty())printf("Invalid\n");
//  else
//  {
//    printf("%d\n",findmid(((*Last_In_First_Out).size() + 1) / 2)); 
//  }
//}
//int main()
//{   
//  stack<int> Last_In_First_Out;
//  int N; 
//  char order[11];
//  scanf("%d", &N); 
//  while (N--)
//  {
//    scanf("%s",order); 
//    switch(order[1])
//    {
//    case 'u':
//      Push(&Last_In_First_Out);
//      break;
//    case 'o':
//      Pop(&Last_In_First_Out);
//      break;
//    case 'e': 
//      PeekMedian(&Last_In_First_Out);
//      break;
//    }
//  } 
//  system("pause");
//  return 0;
//}

//
//#include<iostream>  
//#include<vector>  
//#include<algorithm>  
//#include<stack>  
//#include<string>  
//using namespace std;
//struct BinTree
//{
//    static const int MAXN = 100010;
//    vector<int> a;
//
//    BinTree()
//    {
//        a = vector<int>(MAXN, 0);
//    }
//
//    int lowbit(int t)
//    {
//        return t&(-t);
//    }
//
//    void update(int t, int d)
//    {
//        while (t <= MAXN)
//        {
//            a[t] += d;
//            t += lowbit(t);
//        }
//    }
//
//    int getsum(int t)
//    {
//        int sum(0);
//        while (t > 0)
//        {
//            sum += a[t];
//            t -= lowbit(t);
//        }
//        return sum;
//    }
//    int find(int val, int l = 0, int h = MAXN - 1)
//    {
//        if (l == h)
//            return l;
//        int mid = (l + h) / 2;
//        if (getsum(mid) < val)
//        {
//            //return find(val, mid, h);  
//            return find(val, mid + 1, h);
//        }
//        else
//        {
//            return find(val, l, mid);
//        }
//    }
//};
//BinTree tree;
//int main()
//{
//#ifdef ONLINE_JUDGE  
//#else  
//    freopen("D:\\in.txt", "r", stdin);
//    freopen("D:\\out.txt", "w", stdout);
//#endif  
//    int N(0);
//    scanf("%d", &N);
//    char str[20];
//    int n(0);
//    stack<int> stk;
//    while (N--)
//    {
//        scanf("%s", &str);
//        switch (str[1])
//        {
//        case 'o':
//            if (stk.empty())
//            {
//                printf("Invalid\n");
//            }
//            else
//            {
//                n = stk.top();
//                printf("%d\n", n);
//                stk.pop();
//                tree.update(n, -1);
//            }
//            break;
//        case 'u':
//            scanf("%d", &n);
//            stk.push(n);
//            tree.update(n, 1);
//            break;
//        case 'e':
//            if (stk.empty())
//                printf("Invalid\n");
//            else
//            {
//                printf("%d\n", tree.find((stk.size() + 1) / 2));
//            }
//            break;
//        }
//    }
//    return 0;
//}