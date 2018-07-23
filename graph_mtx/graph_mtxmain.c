#include "graph_mtx.h"

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
  insert_edge(&gm, 'A', 'B');
  insert_edge(&gm, 'A', 'D');
  insert_edge(&gm, 'B', 'C');
  insert_edge(&gm, 'B', 'E');
  insert_edge(&gm, 'C', 'E');
  insert_edge(&gm, 'C', 'D');
  //打印图
  show_graph(&gm);

  //删除连线
  //remove_edge(&gm, 'A', 'B');
  //打印图
  //show_graph(&gm);

  //删除顶点
  remove_vertex(&gm, 'B');
  //打印图
  show_graph(&gm);
}
