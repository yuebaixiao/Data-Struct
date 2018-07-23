#ifndef __graph_mtx__
#define __graph_mtx__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>

#define Default_vertex_size 10

#define T char//dai biao ding dian de lei xing

typedef struct GraphMtx{
  int MaxVertices;//zui da ding dian shu liang]
  int NumVertices;//shi ji ding dian shu liang
  int NumEdges;//bian de shu lian

  T* VerticesList;//ding dian list
  int** Edge;//bian de lian jie xin xi, bu shi 0 jiu shi 1
}GraphMtx;

//chu shi hua tu
void init_graph(GraphMtx* gm);
//打印二维数组
void show_graph(GraphMtx* gm);
//插入顶点
void insert_vertex(GraphMtx* gm, T v);
//添加顶点间的线
void insert_edge(GraphMtx* gm, T v1, T v2);
//删除顶点
void remove_vertex(GraphMtx* gm, T v);
//删除顶点间的线
void remove_edge(GraphMtx* gm, T v1, T v2);
//摧毁图
void destroy_graph(GraphMtx* gm);


#endif
