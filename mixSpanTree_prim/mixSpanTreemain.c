#include "mixSpanTree.h"

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
  insert_vertex(&gm, 'F');

  //添加连线
  insert_edge(&gm, 'A', 'B', 6);
  insert_edge(&gm, 'A', 'D', 5);
  insert_edge(&gm, 'A', 'C', 1);
  insert_edge(&gm, 'B', 'E', 3);
  insert_edge(&gm, 'B', 'C', 5);
  insert_edge(&gm, 'C', 'E', 6);
  insert_edge(&gm, 'C', 'D', 5);
  insert_edge(&gm, 'C', 'F', 4);
  insert_edge(&gm, 'F', 'E', 6);
  insert_edge(&gm, 'D', 'F', 2);
  //打印图
  show_graph(&gm);

  //prim
  minSpanTree_prim(&gm, 'E');

  //摧毁图
  destroy_graph(&gm);

}
