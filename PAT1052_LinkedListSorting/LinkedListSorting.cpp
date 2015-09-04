#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include "stdio.h"
using namespace std;
struct LinkList
{
    int addr;
    int key;
    int next_addr;
    bool operator < (const LinkList &rhs) const
    {
        return key < rhs.key;
    }
}link_nodes[100000],link_list[100000];
int main()
{
    int N, first_addr;
    scanf("%d %d", &N, &first_addr);
    int addr, key, next_addr;
    for (int i = 0; i < N;++i)
    {
        scanf("%d %d %d", &addr, &key, &next_addr);
        link_nodes[addr].addr = addr;
        link_nodes[addr].key = key;
        link_nodes[addr].next_addr = next_addr;
    }
    int link_list_size = 0;
    int addr_ = first_addr;
    while (addr_ != -1)
    {
        link_list[link_list_size].addr = link_nodes[addr_].addr;
        link_list[link_list_size].key = link_nodes[addr_].key;
        link_list[link_list_size].next_addr = link_nodes[addr_].next_addr;
        ++link_list_size;
        addr_ = link_nodes[addr_].next_addr;
    }
    sort(link_list, link_list + link_list_size);
    if (link_list_size==0)
    {
        printf("%d -1\n", link_list_size);
        return 0;
    }
    else
    {
        printf("%d %05d\n", link_list_size, link_list[0].addr);
        for (int i = 0; i < link_list_size-1;++i)
        {
            printf("%05d %d %05d\n", link_list[i].addr, link_list[i].key, link_list[i + 1].addr);
        }
        printf("%05d %d -1\n", link_list[link_list_size - 1].addr, link_list[link_list_size - 1].key);
        return 0;
    }
}