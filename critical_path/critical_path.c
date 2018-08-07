#include "critical_path.h"

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
      gm->Edge[i][j] = 0;
    }
  }
}
//打印二维数组
void show_graph(GraphMtx* gm){
  printf("  ");
  for(int i = 0; i < gm->NumVertices; ++i){
    printf("%c  ", gm->VerticesList[i]);
  }
  printf("\n");
  for(int i = 0; i < gm->NumVertices; ++i){
    //在行首,打印出顶点的名字
    printf("%c:", gm->VerticesList[i]);
    for(int j = 0; j < gm->NumVertices; ++j){
      printf("%d  ", gm->Edge[i][j]);
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
  if(j != -1 && k != -1 && gm->Edge[j][k] != 1){
    //因为是有方向，所以更新1个值
    gm->Edge[j][k] = cost;
    //边数加一
    gm->NumEdges++;
  }
}
//取得与某顶点有连线的第一个顶点
int getNeighbor(GraphMtx* gm, T v){
  int p = getVertexIndex(gm, v);
  if(-1 == p)return -1;
  for(int i = 0; i < gm->NumVertices; ++i){
    if(gm->Edge[p][i] != 0)
      return i;
  }
  return -1;
}

//取得与v1顶点，v1顶点之后的v2顶点的之后的有连线的第一个顶点
int getNextNeighbor(GraphMtx* gm, T v1, T v2){
  if(v1 == v2)return -1;
  int p1 = getVertexIndex(gm, v1);
  int p2 = getVertexIndex(gm, v2);
  if(p1 == -1 || p2 == -1)return -1;

  for(int i = p2 + 1; i < gm->NumVertices; ++i){
    if(gm->Edge[p1][i] != 0)
      return i;
  }

  return -1;
}

E getWeight(GraphMtx* g, int v1, int v2){
  if(v1 == -1 || v2 == -1)return 0;
  return g->Edge[v1][v2];
}
//求解关键路径
void critical_path(GraphMtx* g){
  int n = g->NumVertices;
  //最早开始时间数组
  int* ve = (int*)malloc(sizeof(int) * n);
  //最晚开始时间数组
  int* vl = (int*)malloc(sizeof(int) * n);
  assert(NULL != ve && NULL != vl);
  for(int i = 0; i < n; ++i){
    ve[i] = vl[i] = 0;
  }

  int j, w;
  //ve
  for(int i = 0; i < n; ++i){
    j = getNeighbor(g, g->VerticesList[i]);
    while(j != -1){
      w = getWeight(g, i, j);
      if(ve[i] + w > ve[j]){
	ve[j] = ve[i] + w;
      }
      j = getNextNeighbor(g,g->VerticesList[i],g->VerticesList[j]);
    }
  }

  //vl
  vl[n-1] = ve[n-1];
  for(int i = n - 2; i > 0; --i){
    j = getNeighbor(g, g->VerticesList[i]);
    while(j != -1){
      w = getWeight(g, i, j);
      if(vl[j] - w > vl[i]){
	vl[i] = vl[j] - w;
      }
      j = getNextNeighbor(g,g->VerticesList[i],g->VerticesList[j]);
    }
  }

  int e, l;
  for(int i = 0; i < n; ++i){
    j = getNeighbor(g, g->VerticesList[i]);
    while(j != -1){
      e = ve[i];
      l = vl[j] - getWeight(g, i, j);
      if(e == l){
	printf("<%c, %c>是关键路径\n",g->VerticesList[i],g->VerticesList[j]);
      }
      j = getNextNeighbor(g,g->VerticesList[i],g->VerticesList[j]);
    }
  }

  free(ve);
  free(vl);
}
