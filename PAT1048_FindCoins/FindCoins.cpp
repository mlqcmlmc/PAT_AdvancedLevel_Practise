//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include "stdio.h"
//using namespace std;
//int main()
//{
//    int flag = 0;
//    int N, M;
//    cin >> N >> M;
//    vector<int> face_value(N);
//    for (int i = 0; i < N;++i)
//    {
//        scanf("%d", &face_value[i]);
//    }
//    sort(face_value.begin(), face_value.end());
//    vector<int>::iterator ite;
//    for (ite=face_value.begin(); ite!=face_value.end()&&*ite <= M / 2; ++ite)
//    {
//        if (binary_search(ite + 1, face_value.end(), M - *ite))
//        {
//            flag = 1;
//            printf("%d %d\n", *ite, M - *ite);
//            break;
//        }
//    }
//    if (flag == 0)
//    {
//        printf("No Solution\n");
//    }
//    return 0;
//}

#include <vector>
#include <algorithm>
#include "stdio.h"
using namespace std;
#define NUM 501
int face_flag[NUM] = { 0 };
int main()
{
    int flag = 0;
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> face_value(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &face_value[i]);
        ++face_flag[face_value[i]];
    }
    sort(face_value.begin(), face_value.end());
    for (int i = 0; i < N && face_value[i] <= M / 2; ++i)
    {
        if (M - face_value[i] == face_value[i] && face_flag[face_value[i]]>1)
        {
            flag = 1;
            printf("%d %d\n", face_value[i], M - face_value[i]);
            break;
        }
        else if (M - face_value[i] != face_value[i] && M - face_value[i]<NUM&&face_flag[M - face_value[i]]>0)
        {
            flag = 1;
            printf("%d %d\n", face_value[i], M - face_value[i]);
            break;
        }
    }
    if (flag == 0)
    {
        printf("No Solution\n");
    }

    return 0;
}