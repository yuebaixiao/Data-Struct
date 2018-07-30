#include "graph_link.h"

//初始化图
void init_graph_link(GraphLink* g){
  g->MaxVertices = default_vertex_size;
  g->NumVertices = g->NumEdges = 0;

  g->nodeTable = (Vertex*)malloc(sizeof(Vertex) * g->MaxVertices);
  assert(NULL != g->nodeTable);
  for(int i = 0; i < g->MaxVertices; ++i){
    g->nodeTable[i].adj = NULL;
  }
}

//显示图
void show_graph_link(GraphLink* g){
  if(NULL == g)return;
  for(int i = 0; i < g->NumVertices; ++i){
    printf("%d %c->", i, g->nodeTable[i].data);
    Edge* p = g->nodeTable[i].adj;
    while(NULL != p){
      printf("%d->", p->idx);
      p = p->link;
    }
    printf(" NULL\n");
  }
}

//插入顶点
void insert_vertex(GraphLink* g, T v){
  if(g->NumVertices >= g->MaxVertices)return;
  g->nodeTable[g->NumVertices++].data = v;
}

//查找顶点的index
int getVertexIndex(GraphLink* g, T v){
  for(int i = 0; i < g->NumVertices; ++i){
    if(v == g->nodeTable[i].data)return i;
  }
  return -1;
}

//创建边
void buyEdge(Edge** e, int idx){
  Edge* p = (Edge*)malloc(sizeof(Edge));
  p->idx = idx;
  p->link = NULL;
  if(NULL == *e){
    *e = p;
  }
  else{
    Edge* tmp = *e;
    while(tmp->link != NULL){
      tmp = tmp->link;
    }
    tmp->link = p;
  }
}
//插入边(尾插）
void insert_edge(GraphLink* g, T v1, T v2){
  int p1 = getVertexIndex(g, v1);
  int p2 = getVertexIndex(g, v2);

  if(p1 == -1 || p2 == -1)return;
  
  buyEdge(&(g->nodeTable[p1].adj), p2);
  g->NumEdges++;
  buyEdge(&(g->nodeTable[p2].adj), p1);
  g->NumEdges++;

}
//插入边(头插）TODO


//删除边
void remove_edge(GraphLink* g, T v1, T v2){

}
