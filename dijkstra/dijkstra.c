#include "dijkstra.h"

void init_graph(GraphMtx* gm){
  gm->MaxVertices = Default_vertex_size;
  gm->NumEdges = gm->NumVertices = 0;

  //kai pi ding dian de nei cun kong jian
  gm->VerticesList = (T*)malloc(sizeof(T) * (gm->MaxVertices));
  assert(NULL != gm->VerticesList);

  //创建二维数组
  //让一个int的二级指针，指向一个有8个int一级指针的数组
  //开辟一个能存放gm->MaxVertices个int一级指针的内存空间
  gm->Edge = (int**)malloc(sizeof(int*) * (gm->MaxVertices));
  assert(NULL != gm->Edge);
  //开辟gm->MaxVertices组，能存放gm->MaxVertices个int的内存空间
  for(int i = 0; i < gm->MaxVertices; ++i){
    gm->Edge[i] = (int*)malloc(sizeof(int) * gm->MaxVertices);
  }
  //初始化二维数组
  //让每个顶点之间的边的关系都为不相连的
  for(int i = 0; i < gm->MaxVertices; ++i){
    for(int j = 0; j < gm->MaxVertices; ++j){
      if(i == j)
	gm->Edge[i][j] = 0;
      else
	gm->Edge[i][j] = MAX_COST;
    }
  }
}
//打印二维数组
void show_graph(GraphMtx* gm){
  printf("  ");
  for(int i = 0; i < gm->NumVertices; ++i){
    printf("%3c  ", gm->VerticesList[i]);
  }
  printf("\n");
  for(int i = 0; i < gm->NumVertices; ++i){
    //在行首,打印出顶点的名字
    printf("%c:", gm->VerticesList[i]);
    for(int j = 0; j < gm->NumVertices; ++j){
      if(gm->Edge[i][j] == MAX_COST){
	printf("%3c  ", '*');
      }
      else{
	printf("%3d  ", gm->Edge[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n");
}
//插入顶点
void insert_vertex(GraphMtx* gm, T v){
  //顶点空间已满，不能再插入顶点了
  if(gm->NumVertices >= gm->MaxVertices){
    return;
  }
  gm->VerticesList[gm->NumVertices++] = v;
}

int getVertexIndex(GraphMtx* gm, T v){
  for(int i = 0; i < gm->NumVertices; ++i){
    if(gm->VerticesList[i] == v)return i;
  }
  return -1;
}
//添加顶点间的线
void insert_edge(GraphMtx* gm, T v1, T v2, E cost){
  if(v1 == v2)return;
  
  //查找2个顶点的下标
  int j = getVertexIndex(gm, v1);
  int k = getVertexIndex(gm, v2);
  //说明找到顶点了,并且点之间还没有线
  if(j != -1 && k != -1 ){
    //因为是有方向，所以更新1个值
    gm->Edge[j][k] = cost;
    //边数加一
    gm->NumEdges++;
  }
}

//取得2个顶点之间的权值
E getWeight(GraphMtx* g, int v1, int v2){
  if(v1 == -1 || v2 == -1) return MAX_COST;
  return g->Edge[v1][v2];
}
//最短路径
void short_path(GraphMtx* g,T v,E* dist, int* path){
  int n = g->NumVertices;
  bool* s = (bool*)malloc(sizeof(bool) * n);
  assert(NULL != s);

  int vi = getVertexIndex(g, v);
  for(int i = 0; i < n; ++i){
    //获得各个顶点与目标顶点之间的权值
    dist[i] = getWeight(g, vi, i);
    s[i] = false;
    if(i != vi && dist[i] < MAX_COST){
      path[i] = v;
    }
    else{
      path[i] = -1;
    }
  }

  s[v] = true;
  int min;
  int w;
  for(int i = 0; i < n -1; ++i){
    mix = MAX_COST;
    //u为最短路径顶点的下标
    int u = vi;
    for(int j = 0; j < n; ++j){
      if(!s[j] && dist[j] < min){
	u = j;
	min = dist[j];
      }
    }
    //把u加入到s集合
    s[u] = true;

    //更新下一个点都所有点的权值
    for(int k = 0; i < n; ++k){
      w = getWeight(g, u, k);
      if(!s[k] && w < MAX_COST && dist[u] + w < dist[k]){
	dist[k] = dist[u] + w;
	path[k] = u;
      }
    }
  }
}
