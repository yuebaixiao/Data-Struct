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
void createBinTree(BinTree* bt);
void createBinTree_str(BinTree* bt, char** str);

//先中心，再左树，再右树
void show_clr(BinTree* tr);
//先左树，再中心，再右树
void show_lcr(BinTree* tr);
//先左树，再右树，再中心
void show_lrc(BinTree* tr);
//层级遍历
void show_level(BinTree* tr);

int get_size1(BinTree* tr);
int get_size2(BinTree* tr);
int get_height(BinTree* tr);
BinTreeNode* search(BinTree* tr, ElemType key);
BinTreeNode* get_parent(BinTree* tr, BinTreeNode* p);
BinTreeNode* get_left_chile(BinTree* tr, BinTreeNode* p);
BinTreeNode* get_right_chile(BinTree* tr, BinTreeNode* p);
bool isBintreeEmpty(BinTree* tr);
void copy(BinTree* tr);
void bintree_clear(BinTree* tr);

#endif
