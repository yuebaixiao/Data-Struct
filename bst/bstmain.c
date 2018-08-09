#include "bst.h"

int main(){
  BST bst;
  init_bst(&bst);

  //patten1 root没有右子节点，左子节点中有右子节点
  //T ar[] = {45,12,3,37,24,38};
  //patten2 root没有右子节点，左子节点中没有右子节点
  //T ar[] = {45,12,3};
  //patten3 只有root节点
  //T ar[] = {45};
  //patten4 root有右子节点，右子节点中没有左子节点
  //T ar[] = {45,12,53,3,37,100,24};
  //patten5 root有右子节点，右子节点中有左子节点
  T ar[] = {45,12,53,3,37,100,24,61,90,78};


  //T ar[] = {45,12,53,3,37,100,24,61,90,78};
  //T ar[] = {45,3,4,12,53};
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

  BSTNode* p = search_bst(&bst, 38);
  if(NULL != p)
    printf("%d \n", p->data);
  else
    printf("not exist\n");
  BSTNode* parent = get_parent(&bst, p);
  if(NULL != parent)
    printf("%d \n", parent->data);
  else
    printf("root\n");

  //删除节点
  remove_bst(&bst, 45);
  sort(&bst);
  printf("\n");
  
  clear_bst(&bst);
}
