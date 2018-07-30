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
  //显示图
  //show_graph_link(&gl);

  //插入边(尾插)
  /*
  insert_edge_tail(&gl, 'A', 'B');
  insert_edge_tail(&gl, 'A', 'D');
  insert_edge_tail(&gl, 'B', 'C');
  insert_edge_tail(&gl, 'B', 'E');
  insert_edge_tail(&gl, 'C', 'D');
  insert_edge_tail(&gl, 'C', 'E');
  */

  //插入边(头插)
  ///*
  insert_edge_head(&gl, 'A', 'B');
  insert_edge_head(&gl, 'A', 'D');
  insert_edge_head(&gl, 'B', 'C');
  insert_edge_head(&gl, 'B', 'E');
  insert_edge_head(&gl, 'C', 'D');
  insert_edge_head(&gl, 'C', 'E');
  //*/
  //显示图
  show_graph_link(&gl);

  printf("\n");

  //删除边
  remove_edge(&gl, 'A', 'D');
  //显示图
  show_graph_link(&gl);

  printf("\n");

  //删除顶点
  remove_vertex(&gl, 'C');
  //显示图
  show_graph_link(&gl);
}
