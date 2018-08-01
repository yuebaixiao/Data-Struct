#ifndef __graph_link__
#define __graph_link__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define default_vertex_size 10
#define T char

//边的结构
typedef struct Edge{
  //顶点的下标
  int idx;
  //指向下一个边的指针
  struct Edge* link;
}Edge;

//顶点的结构
typedef struct Vertex{
  //顶点的值
  T data;
  //边
  Edge* adj;
}Vertex;

//图的结构
typedef struct GraphLink{
  int MaxVertices;
  int NumVertices;
  int NumEdges;

  Vertex* nodeTable;
}GraphLink;

//初始化图
void init_graph_link(GraphLink* g);
//显示图
void show_graph_link(GraphLink* g);
//插入顶点
void insert_vertex(GraphLink* g, T v);
//插入边尾插
void insert_edge_tail(GraphLink* g, T v1, T v2);
//插入边头插
void insert_edge_head(GraphLink* g, T v1, T v2);
//删除边
void remove_edge(GraphLink* g, T v1, T v2);
//删除顶点
void remove_vertex(GraphLink* g, T v);
//销毁图
void destroy_graph_link(GraphLink* g);
//取得指定顶点的第一个后序顶点
int get_first_neighbor(GraphLink* g, T v);
//取得指定顶点v1的临街顶点v2的第一个后序顶点
int get_next_neighbor(GraphLink* g, T v1, T v2);

//深度遍历
void dfs_graph(GraphLink* g, T v);
//取得顶点的data值
T getVertexValue(GraphLink* g, int i);
//广度遍历
void cfs_graph(GraphLink* g, T v);

#endif
