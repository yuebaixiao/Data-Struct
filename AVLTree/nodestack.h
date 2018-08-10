#ifndef __NODESTACK__
#define __NODESTACK__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

struct AVLNode;
typedef AVLNode* ElemType;

typedef struct Node{
  ElemType data;
  struct Node *next;
}Node;

typedef struct nodestack{
  int size;
  Node *base;
  Node *top;
}nodestack;

void init(nodestack*);
void push(nodestack*, ElemType);
void pop(nodestack*);
int length(nodestack*);
ElemType getTop(nodestack*);
void clear(nodestack*);
void destroy(nodestack*);
#endif
