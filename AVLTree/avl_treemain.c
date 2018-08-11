#include "avl_tree.h"

int main(){
  AVLTree avl;
  init_avl_tree(&avl);

  //Type ar[] = {13,24,37,90,53};
  //Type ar[] = {30,20,10};  
  Type ar[] = {30,20,40,10,25,5,22,28,21};  

  int n = sizeof(ar) / sizeof(Type);
  for(int i = 0; i < n; ++i){
    insert_avl(&avl, ar[i]);
  }
  return 0;
}
