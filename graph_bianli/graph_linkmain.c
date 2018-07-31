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
  insert_vertex(&gl, 'G');
  insert_vertex(&gl, 'H');
  //显示图
  //show_graph_link(&gl);
  //插入边(头插)
  ///*
  insert_edge_head(&gl, 'A', 'B');
  insert_edge_head(&gl, 'A', 'C');
  insert_edge_head(&gl, 'B', 'D');
  insert_edge_head(&gl, 'B', 'E');
  insert_edge_head(&gl, 'C', 'F');
  insert_edge_head(&gl, 'C', 'G');
  insert_edge_head(&gl, 'D', 'H');
  insert_edge_head(&gl, 'E', 'H');
  insert_edge_head(&gl, 'F', 'G');
  //*/
  //显示图
  show_graph_link(&gl);

  //深度遍历
  dfs_graph(&gl, 'A');
  printf("null\n");
}
