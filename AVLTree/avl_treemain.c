#include "avl_tree.h"

int main(){
  AVLTree avl;
  init_avl_tree(&avl);

  //Type ar[] = {13,24,37,90,53};
  //Type ar[] = {30,20,10};  
  //Type ar[] = {30,20,40,10,25,5,22,28,21};  
  //Type ar[] = {30,20,10};
  //Type ar[] = {50,40,60,10,45,70,5,30,20,12};
  Type ar[] = {30,20,50,10,40,70,60,80,55};

  int n = sizeof(ar) / sizeof(Type);
  for(int i = 0; i < n; ++i){
    insert_avl(&avl, ar[i]);
  }
  return 0;
}
