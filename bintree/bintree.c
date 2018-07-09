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

void createNode_str(BinTree* bt, BinTreeNode** t, char** str){

  if(**str == '\0'){
    return;
  }

  if(**str == bt->ref){
    *t = NULL;
    *str = *str + 1;
  }
  else{
    *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    (*t)->data = **str;
    *str = *str + 1;
    createNode_str(bt, &((*t)->leftChild),  str);
    createNode_str(bt, &((*t)->rightChild), str);
  }
}

void createBinTree_str(BinTree* bt, char** str){
  createNode_str(bt, &(bt->root), str);
}
//先中心，再左树，再右树
void show_node_clr(BinTreeNode* n){
  if(NULL == n)return;
  else{
    printf("%c ", n->data);
    show_node_clr(n->leftChild);
    show_node_clr(n->rightChild);
  }
}
//先中心，再左树，再右树
void show_clr(BinTree* tr){
  show_node_clr(tr->root);
}

//先左树，再中心，再右树
void show_node_lcr(BinTreeNode* n){
  if(NULL == n)return;
  else{
    show_node_lcr(n->leftChild);
    printf("%c ", n->data);    
    show_node_lcr(n->rightChild);
  }
}
//先左树，再中心，再右树
void show_lcr(BinTree* tr){
  show_node_lcr(tr->root);
}

//先左树，再右树，再中心
void show_node_lrc(BinTreeNode* n){
  if(NULL == n)return;
  else{
    show_node_lrc(n->leftChild);
    show_node_lrc(n->rightChild);
    printf("%c ", n->data);
  }
}
//先左树，再右树，再中心
void show_lrc(BinTree* tr){
  show_node_lrc(tr->root);
}
