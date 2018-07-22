#ifndef __BINTREE__
#define __BINTREE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define ElemType char

typedef enum{LINK, THREAD}tag_type;

typedef struct BinTreeNode{
  ElemType data;
  struct BinTreeNode* leftChild;
  struct BinTreeNode* rightChild;
  tag_type ltag;
  tag_type rtag;
}BinTreeNode;

typedef struct BinTree{
  BinTreeNode* root;
  ElemType ref;
}BinTree;

void init_bintree(BinTree* tr, ElemType ref);
void create_tree(BinTree* tr, char* str);
//先中心，再左树，再右树
void show_clr(BinTree* tr);
//先左树，再中心，再右树
void show_lcr(BinTree* tr);
//先左树，再右树，再中心
void show_lrc(BinTree* tr);
//层级遍历
void show_level(BinTree* tr);

void create_link(BinTree* tr);
#endif
