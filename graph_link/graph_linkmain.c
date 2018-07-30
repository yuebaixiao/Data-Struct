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

  //插入边
  insert_edge(&gl, 'A', 'B');
  insert_edge(&gl, 'A', 'D');
  insert_edge(&gl, 'B', 'C');
  insert_edge(&gl, 'B', 'E');
  insert_edge(&gl, 'C', 'D');
  insert_edge(&gl, 'C', 'E');
  //显示图
  show_graph_link(&gl);
}
