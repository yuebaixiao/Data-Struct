#include "bintree.h"

int main(){
  BinTree tr;
  init(&tr, '#');

  //ABC##DE#F##G##H##
  //createBinTree(&tr);

  char* a = "ABC##DE##F##G#H##";
  //char* a = "ABC#D##E#F#GI##L#J";
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

  ElemType target = 'F';
  BinTreeNode* n = search(&tr1, target);
  if(n != NULL)
    printf("查找%c,并找到了%c\n", target, n->data);
  else
    printf("查找%c,但没有找到\n", target);

  //查找父节点
  BinTreeNode* parent = get_parent(&tr1, n);
  if(parent != NULL)
    printf("查找%c的父节点,并找到了%c\n", n->data, parent->data);
  else
    printf("查找%c的父节点,但没有找到\n", n->data);

  //复制树
  char* b = "ABC##DE##F##G#H##";
  //char* b = "ABC#D##E#F#GI##L#J";
  //char* b = "AB##C##";
  BinTree tr2;
  init(&tr2, '#');
  //tr2为空树，把tr1复制给tr2
  copy(&tr2, &tr1);
  show_clr(&tr2);
  printf("\n");

  //销毁树
  bintree_clear(&tr2);
  show_clr(&tr2);
  printf("\n");

  return 0;
}
