#include "bst.h"

int main(){
  BST bst;
  init_bst(&bst);

  T ar[] = {11,45,12,53,3,37,100,24,61,90,78};
  int n = sizeof(ar) / sizeof(T);
  for(int i = 0; i < n; ++i){
    insert_bst_tree(&bst, ar[i]);
  }

  T min1 = min(&bst);
  printf("%d\n", min1);
  T max1 = max(&bst);
  printf("%d\n", max1);

  sort(&bst);
  printf("\n");
}
