#include "bintree.h"
#include "nodequeue.h"

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

//层级遍历
void show_node_level(BinTreeNode* n){
  if(NULL == n) return;
  NodeQueue queue;
  init_queue(&queue);
  enQueue(&queue, n);

  BinTreeNode* tmp;
  while(!isQueueEmpty(&queue)){
    if(getHead(&queue) == NULL)break;
    tmp = getHead(&queue)->data;
    deQueue(&queue);
    printf("%c ", tmp->data);
    if(tmp->leftChild != NULL)
      enQueue(&queue, tmp->leftChild);
    if(tmp->rightChild != NULL)
      enQueue(&queue, tmp->rightChild);
  }
  printf("\n");
}

//层级遍历
void show_level(BinTree* tr){
  show_node_level(tr->root);
}

//--------------------分界线--------------------


//取得树中节点个数
void get_node_size1(BinTreeNode* n, int* p){
  if (NULL == n)return;
  else{
    *p = *p + 1;
    get_node_size1(n->leftChild, p);
    get_node_size1(n->rightChild, p);
  }
}
//取得树中节点个数
int get_size1(BinTree* tr){
  int size = 0;
  get_node_size1(tr->root, &size);
  return size;
}
int get_node_size2(BinTreeNode* p){
  if(NULL == p) return 0;
  else{
    return get_node_size2(p->leftChild) + get_node_size2(p->rightChild) + 1;
  }
}
int get_size2(BinTree* tr){
  return get_node_size2(tr->root);
}
void get_node_height(BinTreeNode* n, int* p){
  if(NULL == n) return;
  NodeQueue queue;
  init_queue(&queue);
  enQueue(&queue, n);

  BinTreeNode* tmp;
  while(!isQueueEmpty(&queue)){
    if(getHead(&queue) == NULL)break;
    tmp = getHead(&queue)->data;
    deQueue(&queue);

    if(tmp->leftChild != NULL){
      *p = *p + 1;
      enQueue(&queue, tmp->leftChild);
    }
    if(tmp->rightChild != NULL){
      enQueue(&queue, tmp->rightChild);
      if(tmp->leftChild == NULL)
	*p = *p + 1;
    }
  }

}
int get_height(BinTree* tr){
  int size = 0;
  get_node_height(tr->root, &size);
  return size;
}
BinTreeNode* search(BinTree* tr, ElemType key){

}
BinTreeNode* get_parent(BinTree* tr, BinTreeNode* p){

}
BinTreeNode* get_left_chile(BinTree* tr, BinTreeNode* p){

}
BinTreeNode* get_right_chile(BinTree* tr, BinTreeNode* p){

}
bool isBintreeEmpty(BinTree* tr){

}
void copy(BinTree* tr){

}
void bintree_clear(BinTree* tr){

}
