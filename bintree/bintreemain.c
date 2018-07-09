#include "bintree.h"

int main(){
  BinTree tr;
  init(&tr, '#');

  //ABC##DE##F##G##H##
  createBinTree(&tr);

  char* a = "ABC##DE##F##G##H##";
  BinTree tr1;
  init(&tr1, '#');
  createBinTree_str(&tr1, a);
  return 0;
}
