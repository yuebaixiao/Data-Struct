#include "bintree.h"

int main(){
  BinTree tr;
  init(&tr, '#');

  //ABC##DE##F##G##H##
  //createBinTree(&tr);

  char* a = "ABC##DE##F##G#H##";
  //char* a = "AB##C##";
  BinTree tr1;
  init(&tr1, '#');
  createBinTree_str(&tr1, &a);
  show_clr(&tr1);
  printf("\n");
  show_lcr(&tr1);
  printf("\n");
  show_lrc(&tr1);
  printf("\n");

  show_level(&tr1);

  printf("树种节点数:%d\n", get_size1(&tr1));
  printf("树种节点数:%d\n", get_size2(&tr1));

  printf("树的高度:%d\n", get_height(&tr1));

  return 0;
}
