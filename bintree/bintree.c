#include "bintree.h"

void init(BinTree* tr, ElemType val){
  tr->root = NULL;
  tr->ref = val;
}

void createRoot(BinTree* bt, BinTreeNode** t){
  ElemType item;
  scanf("%c", &item);
  if(item == bt->ref){
    *t = NULL;
  }
  else{
    *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    assert(*t != NULL);
    (*t)->data = item;
    createRoot(bt, &((*t)->leftChild));
    createRoot(bt, &((*t)->rightChild));
  }
}

void createBinTree(BinTree* bt){
  createRoot(bt, &(bt->root));
}

void createBinTree_str(BinTree* bt, char* str){

}
