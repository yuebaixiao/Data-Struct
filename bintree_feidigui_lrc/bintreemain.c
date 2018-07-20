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
  display_clr(&tr1);
  printf("\n");
  display_lcr(&tr1);
  printf("\n");
  display_lrc(&tr1);
  printf("\n");

  return 0;
}
