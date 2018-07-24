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
  remove_vertex(&gm, 'A');
  //打印图
  show_graph(&gm);

  //添加顶点
  insert_vertex(&gm, 'F');
  //添加线
  insert_edge(&gm, 'F', 'B');
  insert_edge(&gm, 'F', 'C');
  insert_edge(&gm, 'F', 'D');
  //打印图
  show_graph(&gm);
  //删除顶点
  remove_vertex(&gm, 'D');
  //删除线
  remove_edge(&gm, 'F', 'B');
  //打印图
  show_graph(&gm);

  //取得与某顶点有连线的第一个顶点
  int p = getNeighbor(&gm, 'F');
  printf("%d\n", p);

  //取得与v1顶点，v1顶点之后的v2顶点的之后的有连线的第一个顶点
  int p1 = getNextNeighbor(&gm, 'E', 'B');
  printf("%d\n", p1);
  
  //摧毁图
  destroy_graph(&gm);

}
