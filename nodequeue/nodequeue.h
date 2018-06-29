#ifndef __NODEQUEUE__
#define __NODEQUEUE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define ElemType int

typedef struct Node{
  ElemType data;
  struct Node* next;
}Node;

typedef struct NodeQueue{
  Node*  front;
  Node*  tail;
  size_t size;
}NodeQueue;

void init(NodeQueue*);
void enQueue(NodeQueue*, ElemType);
void deQueue(NodeQueue*);
void show_list(NodeQueue*);
int length(NodeQueue*);
void clear(NodeQueue*);
void destroy(NodeQueue*);

#endif
