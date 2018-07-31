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

  //让被删除顶点那行，指向最后一个顶点那行。
  //因为最后一行向上移动了，所以要修改和最后一行有连线的点那行的线的下标。
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
//销毁图
void destroy_graph_link(GraphLink* g){
  //释放所有边的内存空间
  Edge* t = NULL;
  Edge* p = NULL;
  for(int i = 0; i< g->NumVertices; ++i){
    t = g->nodeTable[i].adj;
    while(NULL != t){
      p = t;
      t = t->link;
      free(p);
    }
  }

  //释放所有顶点的内存空间
  free(g->nodeTable);
  g->nodeTable = NULL;
  g->MaxVertices = g->NumVertices = g->NumEdges = 0;
}

//取得指定顶点的第一个后序顶点
int get_first_neighbor(GraphLink* g, T v){
  int i = getVertexIndex(g, v);
  if (-1 == i)return -1;
  Edge* p = g->nodeTable[i].adj;
  if(NULL != p)
    return p->idx;
  else
    return -1;
}

//取得指定顶点v1的临街顶点v2的第一个后序顶点
int get_next_neighbor(GraphLink* g, T ve1, T ve2){
  int v1 = getVertexIndex(g, ve1);
  int v2 = getVertexIndex(g, ve2);
  if(v1 == -1 || v2 == -1)return -1;

  Edge* t = g->nodeTable[v1].adj;
  while(t != NULL && t->idx != v2){
    t = t->link;
  }
  if(NULL != t && t->link != NULL){
    return t->link->idx;
  }
  return -1;
}

//深度遍历
void dfs_graph_v(GraphLink* g, Vertex* v, bool* visited){

  Edge* p = v->adj;
  if(p != NULL){
    if(!visited[p->idx]){
      printf("%d ", p->idx);
    
      visited[p->idx] = true;
      dfs_graph_v(g, &(g->nodeTable[p->idx]), visited);
    }
  }
}
void dfs_graph(GraphLink* g, T v){
  int cnt = g->NumVertices;
  bool* visited = (bool*)malloc(sizeof(bool));
  assert(NULL != visited);
  for(int i = 0; i < cnt; ++i){
    visited[i] =  false;
  }
  
  int index = getVertexIndex(g, v);
  Vertex* p = &(g->nodeTable[index]);
  Edge* e = p->adj;
  while(NULL != e){
    dfs_graph_v(g, p, visited);
    printf("\n");
    e = e->link;
    if(NULL != e){
      p = &(g->nodeTable[e->idx]);
    }
  }

}
