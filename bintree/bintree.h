#ifndef __BINTREE__
#define __BINTREE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define ElemType char

typedef struct BinTreeNode{
  ElemType data;
  struct BinTreeNode* leftChild;
  struct BinTreeNode* rightChild;
}BinTreeNode;

typedef struct BinTree{
  BinTreeNode* root;
  ElemType ref;
}BinTree;

void init(BinTree* tr, ElemType val);
#endif
