#ifndef __NODESTACK__
#define __NODESTACK__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

struct BinTreeNode;

typedef BinTreeNode* ElemType2;

typedef struct Node{
  ElemType2 data;
  struct Node *next;
}Node;

typedef struct nodestack{
  int size;
  Node *base;
  Node *top;
}nodestack;

void init(nodestack*);
void push(nodestack*, ElemType2);
void show_list(nodestack*);
Node* pop(nodestack*);
int length(nodestack*);
void clear(nodestack*);
void destroy(nodestack*);
#endif
