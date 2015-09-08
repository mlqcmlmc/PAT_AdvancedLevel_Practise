#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>//使用unordered_set比使用set时间要小一倍多
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    vector<unordered_set<int>> vsets(N);
    for (int i = 0; i < N;++i)
    {
        int M;
        scanf("%d", &M);
        for (int j = 0; j < M;++j)
        {
            int temp;
            scanf("%d", &temp);
            vsets[i].insert(temp);
        }
    }
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K;++i)
    {
        int index1, index2;
        scanf("%d %d", &index1, &index2);
        index1 = index1 - 1;
        index2 = index2 - 1;
        int num_total = vsets[index1].size() + vsets[index2].size();
        int num_intersection = 0;
        auto ite = vsets[index1].begin();
        while (ite != vsets[index1].end())
        {
            if (vsets[index2].find(*ite)!=vsets[index2].end())
            {
                ++num_intersection;
            }
            ++ite;
        }
        double similarity;
        similarity = 100 * (double)num_intersection / (num_total - num_intersection);
        printf("%.1f%%\n", similarity);

    }
    return 0;
}


//使用stl set_intersection set_union:
//#include <cstdio>  
//#include <iostream>  
//#include <iomanip>  
//#include <algorithm>  
//#include <iterator>  
//#include <set>  
//using namespace std;
//set<int> s[50];
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i)
//    {
//        int num, x;
//        scanf("%d", &num);
//        for (; num; --num)
//        {
//            scanf("%d", &x);
//            s[i].insert(x);
//        }
//    }
//    int k;
//    scanf("%d", &k);
//    for (; k; --k)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);
//        set<int> inter, uni;
//        set_intersection(s[a - 1].begin(), s[a - 1].end(), s[b - 1].begin(), s[b - 1].end(), inserter(inter, inter.begin()));
//        //set_union(s[a-1].begin(), s[a-1].end(), s[b-1].begin(), s[b-1].end(), inserter(uni, uni.begin()));  
//        cout << setiosflags(ios::fixed) << setprecision(1) << inter.size() *100.0 / (s[a - 1].size() + s[b - 1].size() - inter.size()) << "%" << endl;
//    }
//    return 0;
//}