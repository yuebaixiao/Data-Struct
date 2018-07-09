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

  return 0;
}
