#include "dijkstra.h"

int main(){
  GraphMtx gm;
  //初始化图
  init_graph(&gm);
  //插入顶点
  insert_vertex(&gm, 'A');
  insert_vertex(&gm, 'B');
  insert_vertex(&gm, 'C');
  insert_vertex(&gm, 'D');
  insert_vertex(&gm, 'E');

  //添加连线
  insert_edge(&gm, 'A', 'B', 10);
  insert_edge(&gm, 'A', 'D', 30);
  insert_edge(&gm, 'A', 'E', 100);
  insert_edge(&gm, 'B', 'C', 50);
  insert_edge(&gm, 'C', 'E', 10);
  insert_edge(&gm, 'D', 'C', 20);
  insert_edge(&gm, 'D', 'E', 60);
  //打印图
  show_graph(&gm);

  int n = gm.NumVertices;
  E* dist = (E*)malloc(sizeof(E) * n);
  int* path = (int*)malloc(sizeof(int) * n);
  assert(NULL != dist && NULL != path);

  //最短路径
  short_path(&gm, 'A', dist, path);
}
