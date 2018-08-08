#ifndef __mixspantree__
#define __mixspantree__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>

#define Default_vertex_size 20

#define T char//dai biao ding dian de lei xing
#define E int
#define MAX_COST 0x7FFFFFFF


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
void insert_edge(GraphMtx* gm, T v1, T v2, E cost);

//最短路径
void short_path(GraphMtx* g,T v,E* dist, int* path);
#endif
