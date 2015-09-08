#define _CRT_SECURE_NO_WARNINGS
//��һ��multiset�ᳬʱ
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

//��һ��multiset�ᳬʱ��������multiset���е��������ᳬʱ
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
        //���С�Ĳ��ִ��ڴ�Ĳ��֣���С��������Ԫ���Ƶ���ĵ���  
        it = minm.end();
        --it;
        maxm.insert(*it);
        minm.erase(it);
    }
    else if (maxm.size() > minm.size())
    {
        //���С�Ĳ���С�ڴ�Ĳ��֣��Ѵ������С��Ԫ���Ƶ�С�ĵ���  
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
                adjust();//���� 
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
            adjust();//����
        }
    }
    return 0;
}

////���������״����Ľⷨ
//#include<iostream>   
//#include<stack> 
//#define MAX 100001/*������100000_no more than 10^5.*/
//using namespace std;   
//int Countkey[MAX] = { 0 };
///*htt p://duanple.blog.163.com/blog/static/7097176720081131113145832/*/
//int lowBit_from_right_to_left_first_One(int key)
//{
//  return key&(-key);/*���ӣ����������(key����)000110  ��ô����000010���ֵ��2;����2=2^1;
//                                            100011  ��ô����000001���ֵ��1;����1=2^0;
//                                            101000  ��ô����001000���ֵ��8;����8=2^3;
//                                            000000  ��ô����000000���ֵ��0;����0;
//                      ------------------------------------
//            �ȼ���key&(key^(key-1));
//            key��Ϊ��ʱ����ܱ�2��k�η�����������͵���2^k;
//            ��key���Ϊ��ʱ�����Ϊ�㣻
//            ----------------------------------------------
//            key&(-key) һ�����keyΪ�㣬���Ϊ0��
//            ��һ���������keyΪ������-keyΪ�����ڼ�������ò����ʾ
//            ��-key��=key��ԭ�ӵ�λ���ұ����󣩣���û��������һ��1������һ��1�����ֲ��䣬����ȥֱ������λ��������λȫ�䷴[1��0��0��1]��
//            --------------------------------------------------
//            key&(key^(key-1)����key��key-1����������key��1��ʱ�����λ��λ������λ������ڶ������е�key�����λΪ0����Ҫ��ȥ����1��
//            ��Ȼ���ᱻ��λ�����λ���ӵ�λ���ұ����󣩣��������ĵ�һ��1��������key��key-1�����1����߱���ȫһ������1���ұ߰���1ȫ��һ����
//            key^(���)key-1����λ���û�н�λ�ļӣ�ͬ���㣬��ͬ��1�������ź�ԭ����key��λ��&û�н�λ�ĳˣ�1&1=1������Ϊ0��
//            ��Ȼkey��key^(key-1ֻ�иո�1���Ǹ�λ��һ���Ҷ�Ϊ1��
//            */
//}
//void insertCountkey(int key,int add_dec)
//{
//  while (key <= MAX)
//  {
//    Countkey[key] += add_dec;
//    key += lowBit_from_right_to_left_first_One(key);
//  }/*��key�ļ���Ϊ2^kʵ��Countkey[key] ����һ��add�����һ��dec
//     ���Ŷ��ڼ������2^k�ĵ�һ��newkeyʵ��Countkey[newkey]����һ��add��ǻ����һ��dec
//     ע�ͣ���Щ����2^k��newkey=2^(k+1);2^(k+2)����<=MAX��
//          ������Ȼ��ֻ��Countkey[2^k]��������1<key<=2^k������
//                      Countkey[2^k+1]=Countkey[2^k+1];ֻ�������Լ���key=2^k+1��������
//                      Countkey[2^k+2]=����key=2^k+1��key=2^k+2������;
//      ��������low_and_�����������ʱ
//    low_and_(int*Countkey, int 2^k)��ôֱ�ӻ��sum+=Countkey[2^k],key=0;����ʱsum=����1<key<=2^k������
//    low_and_(int*Countkey, int 2^k+1)��ô����sum+=Countkey[2^k+1],key=2^k;����sum+=Countkey[2^k],key=0������ʱsum=����1<key<=2^k+1������;
//    low_and_(int*Countkey, int 2^k+2)��ô����sum+=Countkey[2^k+2],key=2^k;����sum+=Countkey[2^k],key=0������ʱsum=����1<key<=2^k+2������; 
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
//         �����2^k�ǲ��ϱ䶯�ġ�
//           �����һkey��n*2^k��nΪ����������ô��ʵ��sum+��key-�� 
//           �����һkey�Ѿ���2^k����ô���һ��key-=lowBit_from_right_to_left_first_One��
//                        (key=0����������Binary indexed tree-��״���� ����֪������ʱ��sum=Countkey[2^k]+����+Countkey[key�ʼ];
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