#include "bintree.h"

void init_bintree(BinTree* tr, ElemType ref){
  tr->root = NULL;
  tr->ref = ref;
}

BinTreeNode* buynode(ElemType x){
  BinTreeNode* n = (BinTreeNode*)malloc(sizeof(BinTreeNode));
  n->data = x;
  n->leftChild = n->rightChild = NULL;
  n->ltag = n->rtag = LINK;
  return n;
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
    *t = buynode(**str);
    *str = *str + 1;
    createNode_str(bt, &((*t)->leftChild),  str);
    createNode_str(bt, &((*t)->rightChild), str);
  }
}

void create_tree(BinTree* tr, char* str){
  createNode_str(tr, &(tr->root), &str);
}

void create_link_node(BinTreeNode* n, BinTreeNode** pre){
  if(NULL == n)return;

  create_link_node(n->leftChild, pre);
  if(NULL == n->leftChild){
    n->ltag = THREAD;
    n->leftChild = *pre;
  }
  if(*pre != NULL && (*pre)->rightChild == NULL){
    (*pre)->rtag = THREAD;
    (*pre)->rightChild = n;
  }
  *pre = n;
  create_link_node(n->rightChild, pre);
}
void create_link(BinTree* tr){
  BinTreeNode* pre = NULL;
  create_link_node(tr->root, &pre);
  pre->rightChild = NULL;
  pre->rtag = THREAD;
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
