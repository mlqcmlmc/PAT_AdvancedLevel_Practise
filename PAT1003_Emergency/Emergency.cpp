#include<iostream>
#include<vector>
#include"stdio.h"
#include"stdlib.h"
using namespace std;
struct EdgeNode
{
    int adj_vertex;
    int road_length;
    EdgeNode *next_edge;
};//边表结点
struct VertexNode
{
    int rescue_num;
    EdgeNode *first_edge;
};//顶点节点
struct AlgraphList
{
    int nodes;
    int edges;
    vector<VertexNode> vertex_list;
};

void CreatAlgraph(AlgraphList* list)
{
    int road_current, road_save;
    int rescue_num_temp;
    cin >> list->nodes >> list->edges >> road_current >> road_save;
    list->vertex_list.resize(list->nodes);
    for (int i = 0; i < list->nodes; i++)
    {
        cin >> rescue_num_temp;
        list->vertex_list[i].rescue_num = rescue_num_temp;
        list->vertex_list[i].first_edge = NULL;
    }
    //创建无向图的邻接表
    int c1, c2, L;
    EdgeNode *c1_new_node, *c2_new_node;
    for (int i = 0; i < list->edges; i++)
    {
        cin >> c1 >> c2 >> L;
        c1_new_node = (EdgeNode*)malloc(sizeof(EdgeNode));
        c1_new_node->adj_vertex = c2;
        c1_new_node->road_length = L;
        c1_new_node->next_edge = list->vertex_list[c1].first_edge;
        list->vertex_list[c1].first_edge = c1_new_node;

        c2_new_node = (EdgeNode*)malloc(sizeof(EdgeNode));
        c2_new_node->adj_vertex = c1;
        c2_new_node->road_length = L;
        c2_new_node->next_edge = list->vertex_list[c2].first_edge;
        list->vertex_list[c2].first_edge = c2_new_node;
    }
}

int main()
{
    AlgraphList* list;
    CreatAlgraph(list);

    return 0;
}