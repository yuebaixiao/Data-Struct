#ifndef __mixspantree__
#define __mixspantree__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdlib.h>

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

typedef struct Edge{
  int begin;//边的起点
  int end;  //边的终点
  E   cost; //边的权重
}Edge;

//chu shi hua tu
void init_graph(GraphMtx* gm);
//打印二维数组
void show_graph(GraphMtx* gm);
//插入顶点
void insert_vertex(GraphMtx* gm, T v);
//添加顶点间的线
void insert_edge(GraphMtx* gm, T v1, T v2, E cost);
//删除顶点
void remove_vertex(GraphMtx* gm, T v);
//删除顶点间的线
void remove_edge(GraphMtx* gm, T v1, T v2);
//摧毁图
void destroy_graph(GraphMtx* gm);
//取得与v顶点有连线的第一个顶点
int getNeighbor(GraphMtx* gm, T v);
//取得与v1顶点，v1顶点之后的v2顶点的之后的有连线的第一个顶点
int getNextNeighbor(GraphMtx* gm, T v1, T v2);

//用kruskal算法构造最小生成树
void minSpanTree_kruskal(GraphMtx* gm);

#endif
