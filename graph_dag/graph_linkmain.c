#include "graph_link.h"

int main(){
  GraphLink gl;
  //初始化图
  init_graph_link(&gl);
  //插入节点
  insert_vertex(&gl, 'A');
  insert_vertex(&gl, 'B');
  insert_vertex(&gl, 'C');
  insert_vertex(&gl, 'D');
  insert_vertex(&gl, 'E');
  insert_vertex(&gl, 'F');

  //插入边(头插)
  insert_edge_head(&gl, 'A', 'B');
  insert_edge_head(&gl, 'A', 'C');
  insert_edge_head(&gl, 'A', 'D');
  insert_edge_head(&gl, 'C', 'B');
  insert_edge_head(&gl, 'C', 'E');
  insert_edge_head(&gl, 'D', 'E');
  insert_edge_head(&gl, 'F', 'D');
  insert_edge_head(&gl, 'F', 'E');

  //显示图
  show_graph_link(&gl);

  //拓扑排序
  topo_sort(&gl);

  printf("\n");
}
