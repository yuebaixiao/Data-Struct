#include "mixSpanTree.h"

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
    printf("%c  ", gm->VerticesList[i]);
  }
  printf("\n");
  for(int i = 0; i < gm->NumVertices; ++i){
    //在行首,打印出顶点的名字
    printf("%c:", gm->VerticesList[i]);
    for(int j = 0; j < gm->NumVertices; ++j){
      if(gm->Edge[i][j] == MAX_COST){
	printf("%c  ", '*');
      }
      else{
	printf("%d  ", gm->Edge[i][j]);
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
    //因为是无方向，所以更新2个值
    gm->Edge[j][k] = gm->Edge[k][j] = cost;
    //边数加一
    gm->NumEdges++;
  }
}

//比较边的权重,本函数作为快速排序函数的参数来使用。
int cmp(const void* a, const void* b){
  return ((*(Edge*)a).cost - (*(Edge*)b).cost);
}
//判断参数的2个顶点的父节点是否相同
bool is_same(int* father, int begin, int end){
  while(father[begin] != begin){
    begin = father[begin];
  }
  while(father[end] != end){
    end = father[end];
  }
  return begin == end;
}
//找到end节点的父节点x，再找到begin节点的父节点y，更新x节点的父节点为y
void mark_same(int* father, int begin, int end){
  while(father[begin] != begin){
    begin = father[begin];
  }
  while(father[end] != end){
    end = father[end];
  }
  father[end] = begin;

}
//用kruskal算法构造最小生成树
void minSpanTree_kruskal(GraphMtx* g){

  int n = g->NumVertices;
  Edge* edge = (Edge*)malloc(sizeof(Edge) * n*(n-1)/2);
  assert(edge != NULL);

  int k = 0;
  //查找一半的矩阵，把各条边的起点，终点，权重，放到edge数组里
  for(int i = 0; i < n; ++i){
    for(int j = i; j < n; j++){
      if(g->Edge[i][j] != 0 && g->Edge[i][j] != MAX_COST){
	edge[k].begin = i;
	edge[k].end = j;
	edge[k].cost = g->Edge[i][j];
	k++;
      }
    }
  }

  //按照权重来排序(用系统函数）
  //第一个参数：要被排序的数组
  //第二个参数：数组中元素的个数
  //第三个参数：每个数组元素占用的内存空间
  //第四个参数：函数指针，指定排序的规则
  qsort(edge, k, sizeof(Edge), cmp);

  //初始化每个节点的父节点，让每个节点的父节点为自身
  int *father = (int*)malloc(sizeof(int) * n);
  assert(NULL != father);
  for(int i = 0; i < n; ++i){
    father[i] = i;
  }

  for(int i = 0; i < n; ++i){
    //判断2个节点的父节点是否相同，不相同就连接
    if(!is_same(father, edge[i].begin, edge[i].end)){
      printf("%c->%c:%d\n",g->VerticesList[edge[i].begin],g->VerticesList[edge[i].end], edge[i].cost);
      //连接后，找到节点end的父节点x，再找到节点begin的父节点y，把节点x的父节点更新为y
      mark_same(father, edge[i].begin, edge[i].end);
    }
  }
}
