#include "graph_mtx.h"

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
void insert_edge(GraphMtx* gm, T v1, T v2){
  if(v1 == v2)return;
  
  //查找2个顶点的下标
  int j = getVertexIndex(gm, v1);
  int k = getVertexIndex(gm, v2);
  //说明找到顶点了,并且点之间还没有线
  if(j != -1 && k != -1 && gm->Edge[j][k] != 1){
    //因为是无方向，所以更新2个值
    gm->Edge[j][k] = gm->Edge[k][j] = 1;
    //边数加一
    gm->NumEdges++;
  }
}
//删除顶点间的线
void remove_edge(GraphMtx* gm, T v1, T v2){
  if(v1 == v2)return;
  //查找2个顶点的下标
  int j = getVertexIndex(gm, v1);
  int k = getVertexIndex(gm, v2);
  //说明找到顶点了,并且点之间还有线
  if(j != -1 && k != -1 && gm->Edge[j][k] == 1){
    //因为是无方向，所以更新2个值
    gm->Edge[j][k] = gm->Edge[k][j] = 0;
    //边数减一
    gm->NumEdges--;
  }
}
//删除顶点
void remove_vertex(GraphMtx* gm, T v){
  int k = getVertexIndex(gm, v);
  //找到了要被删除节点的index
  if(k != -1){
    //删除和要被删除点关联的线
    for(int i = 0; i < gm->NumVertices - 1; ++i){
      //从要被删除的顶点开始，用后面的值替换前面的值
      for(int j = k; j < gm->NumVertices - 1; ++j){
	//用同行的下一个值，替换掉现在位置的值
	gm->Edge[i][j] = gm->Edge[i][j+1];
	//循环到要删除的行的位置
	if(i >= k){
	  //用同列的下一行的值，替换掉现在位置的值
	  gm->Edge[i][j] = gm->Edge[i+1][j];
	}
      }
      //因为j的循环的临界值是NumVertices - 1，所以清除每行的最后一个值
      gm->Edge[i][gm->NumVertices-1] = 0;
    }
    //因为i的循环的临界值是NumVertices - 1，所以清除最后一整行的值
    memset(gm->Edge[gm->NumVertices], 0, sizeof(int) * gm->NumVertices);
    //TODO 未删除线的数量

    //删除点
    for(int i = k; i < gm->NumVertices - 1; ++i){
      gm->VerticesList[i] = gm->VerticesList[i+1];
    }
    //最后一个点清空
    gm->VerticesList[gm->NumVertices - 1] = ' ';
    gm->NumVertices--;
  }
}

