#include "critical_path.h"

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
  insert_vertex(&gm, 'G');
  insert_vertex(&gm, 'H');
  insert_vertex(&gm, 'I');

  //添加连线
  insert_edge(&gm, 'A', 'B', 6);
  insert_edge(&gm, 'A', 'C', 4);
  insert_edge(&gm, 'A', 'D', 5);
  insert_edge(&gm, 'B', 'E', 1);
  insert_edge(&gm, 'C', 'E', 1);
  insert_edge(&gm, 'D', 'F', 2);
  insert_edge(&gm, 'E', 'G', 9);
  insert_edge(&gm, 'E', 'H', 7);
  insert_edge(&gm, 'F', 'H', 4);
  insert_edge(&gm, 'G', 'I', 2);
  insert_edge(&gm, 'H', 'I', 4);
  //打印图
  show_graph(&gm);

}
