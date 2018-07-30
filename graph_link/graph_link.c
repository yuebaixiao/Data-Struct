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
void insert_edge_tail(GraphLink* g, T v1, T v2){
  int p1 = getVertexIndex(g, v1);
  int p2 = getVertexIndex(g, v2);

  if(p1 == -1 || p2 == -1)return;
  
  buyEdge(&(g->nodeTable[p1].adj), p2);
  g->NumEdges++;
  buyEdge(&(g->nodeTable[p2].adj), p1);
  g->NumEdges++;

}
//插入边(头插）
void insert_edge_head(GraphLink* g, T v1, T v2){
  int p1 = getVertexIndex(g, v1);
  int p2 = getVertexIndex(g, v2);

  if(p1 == -1 || p2 == -1)return;

  Edge* p = (Edge*)malloc(sizeof(Edge));
  p->idx = p2;
  p->link = g->nodeTable[p1].adj;
  g->nodeTable[p1].adj = p;
  
  p = (Edge*)malloc(sizeof(Edge));
  p->idx = p1;
  p->link = g->nodeTable[p2].adj;
  g->nodeTable[p2].adj = p;  
}
//删除边
int remove_edge_(Edge** p, int i){
  if(NULL == *p)return -1;
  Edge* f;
  //判断第一个边是否是目标边
  if((*p)->idx == i){
    //删除第一条边
    f = *p;
    *p = (*p)->link;
    free(f);
    return 0;
  }

  Edge* tmp = *p;
  while(tmp->link != NULL && tmp->link->idx != i){
    tmp = tmp->link;
  }
  //没有找到边
  if(tmp->link == NULL){
    return -1;
  }
  //找到边
  else{
    f = tmp->link;
    tmp->link = tmp->link->link;
    free(f);
    return 0;
  }

}
void remove_edge(GraphLink* g, T v1, T v2){
  int p1 = getVertexIndex(g, v1);
  int p2 = getVertexIndex(g, v2);

  if(p1 == -1 || p2 == -1)return;

  int r = remove_edge_(&(g->nodeTable[p1].adj), p2);
  if(r == 0){
    g->NumEdges--;
    remove_edge_(&(g->nodeTable[p2].adj), p1);
    g->NumEdges--;
  }

}
//删除顶点
void remove_vertex(GraphLink* g, T v){
  int p = getVertexIndex(g, v);

  if(p == -1)return;

  //删除目标顶点以外的顶点，与目标顶点之间的边
  for(int i = 0; i < g->NumVertices; ++i){
    if(i == p){
      continue;
    }else{
      remove_edge_(&(g->nodeTable[i].adj), p);
    }
  }

  //删除目标顶点行的所有边
  Edge* te = g->nodeTable[p].adj;
  Edge* tmp;
  while(te != NULL){
    tmp = te;
    te = te->link;
    free(tmp);
  }

  g->nodeTable[p].data = g->nodeTable[g->NumVertices - 1].data;
  g->nodeTable[p].adj = g->nodeTable[g->NumVertices - 1].adj;
  tmp = g->nodeTable[p].adj;
  Edge* q;
  while(tmp != NULL){
    q = g->nodeTable[tmp->idx].adj;
    while(q != NULL && q->idx != g->NumVertices - 1){
      q = q->link;
    }
    q->idx = p;

    tmp = tmp->link;
  }
  g->NumVertices--;
}
