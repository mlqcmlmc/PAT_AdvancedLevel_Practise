//�����ĿҪ������ȫ���������������ֱ�Ӳ�����ͨ�Ľ�����ʽ����ʵͦ�鷳�ģ�
//�Ҹտ�ʼҲ���������õ����������˺ܾã�AC�ˣ�������ͻȻ�����Ͽ����������������˼·�ǳ��ĺã�
//�����������պ�д���£���ʵ�������������ݽṹ����ȫ�������ĵ�һ�����ʣ�
//���ӽڵ���±�Ϊi�������ӽڵ���±�Ϊ2*i���Һ��ӽڵ���±�Ϊ2*i + 1���������ֻ����ȫ�����������㣬
//��ʵ��������������ʹ��������������һ����ȫ�������� Ҫʵ�������ȫ������Ҳ������������ʵ�ͼ��ˣ�
//��Ȼһ�ö�����������������������ǵ�������ģ�������ͼ��ˣ�ֻҪ�ڹ�����ȫ��������ʱ��������Ϳ�����
//��ǰ����Ԫ�ص������򣩡�
//��ǰ��������Ŀ���������͵ģ��������Ŀ����ȫ���������������ȷ�ǳ��ĺ��ʣ����Լ�¼�£����Ժ�ع�ѧϰ��


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tree[1005] = { 0 };
int N, pos;
vector<int> numbers;
void BuildTress(int root)
{
    if (root > N)
        return;
    int lson = root << 1;
    int rson = (root << 1) + 1;
    BuildTress(lson);
    tree[root] = numbers[pos++];
    BuildTress(rson);
}
int main()
{
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &numbers[i]);
    }
    sort(numbers.begin(), numbers.end());
    pos = 0;
    BuildTress(1);
    printf("%d", tree[1]);
    for (int i = 2; i <= N; ++i){
        printf(" %d", tree[i]);
    }
    printf("\n");
    return 0;
}