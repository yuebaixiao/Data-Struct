#ifndef __AVLTREE__
#define __AVLTREE__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include "nodestack.h"

#define Type int
#define FALSE 0
#define TRUE 1
#define BOOL int

typedef struct AVLNode{
  Type data;
  struct AVLNode* left;
  struct AVLNode* right;
  int bf;//平衡因子
}AVLNode;

typedef struct AVLTree{
  struct AVLNode* root;
}AVLTree;

void init_avl_tree(AVLTree* avl);
//插入节点
BOOL insert_avl(AVLTree* avl, Type t);

#endif
