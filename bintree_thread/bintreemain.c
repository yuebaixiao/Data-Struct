#include "bintree.h"

int main(){
  BinTree tr1;
  init_bintree(&tr1, '#');
  char* a1 = "ABC##DE##F##G#H##";
  create_tree(&tr1, a1);

  create_link(&tr1);
  //  show_clr(&tr1);
  //printf("\n");

  return 0;
}
