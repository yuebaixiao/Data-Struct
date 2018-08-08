#include "bst.h"

//初始化二叉排序树
void init_bst(BST* bst){
  bst->root = NULL;
}

//插入树的节点
BOOL insert_bst_node(BSTNode** t, T x){
  if(*t == NULL){
    *t = (BSTNode*)malloc(sizeof(BSTNode));
    assert(NULL != *t);
    (*t)->data  = x;
    (*t)->left  = NULL;
    (*t)->right = NULL;
    return TRUE;
  }
  else if(x < (*t)->data){
    insert_bst_node(&((*t)->left), x);
  }
  else if(x > (*t)->data){
    insert_bst_node(&((*t)->right), x);
  }
  return FALSE;
}
BOOL insert_bst_tree(BST* bst, T x){
  return insert_bst_node(&(bst->root), x);
}

//求树中最小节点
T min_node(BSTNode* t){
  while(t->left != NULL)
    t = t->left;
  return t->data;
}
T min(BST* bst){
  assert(bst->root != NULL);
  return min_node(bst->root);
}
//求树中最大节点
T max_node(BSTNode* t){
  while(t->right != NULL){
    t = t->right;
  }
  return t->data;
}
T max(BST* bst){
  assert(bst->root != NULL);
  return max_node(bst->root);
}
//排序
void sort_node(BSTNode* t){
  if(NULL == t){
    return;
  }else{
    sort_node(t->left);
    printf("%d ", t->data);
    sort_node(t->right);
  }
}
void sort(BST* bst){
  assert(NULL != bst->root);
  sort_node(bst->root);
}
