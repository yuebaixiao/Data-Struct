#ifndef __graph_link__
#define __graph_link__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>

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
#endif
