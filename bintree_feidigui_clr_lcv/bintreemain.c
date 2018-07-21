#include "bintree.h"

int main(){
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

  char* clr = "ABCDEFGH";
  char* lcr = "CBEDFAGH";
  //char* lrc = "CEFDBHGA";
  BinTree tr2;
  init(&tr2, '#');
  int n2 = strlen(clr);
  createBinTree_clr_lcr(&tr2, clr, lcr, n2);
  display_clr(&tr2);
  printf("\n");

  char* lcr1 = "CBEDFAGH";
  char lrc1[] = "CEFDBHGA";
  BinTree tr3;
  init(&tr3, '#');
  int n3 = strlen(lcr1);
  createBinTree_lcr_lrc(&tr3, lrc1, lcr1, n3);
  display_clr(&tr3);
  printf("\n");

  return 0;
}
