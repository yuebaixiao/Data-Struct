#ifndef __NODEQUEUE__
#define __NODEQUEUE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

struct BinTreeNode;

#define ElemType1 BinTreeNode*

typedef struct Node{
  ElemType1 data;
  struct Node* next;
}Node;

typedef struct NodeQueue{
  Node*  front;
  Node*  tail;
  size_t size;
}NodeQueue;

void init_queue(NodeQueue*);
void enQueue(NodeQueue*, ElemType1);
void deQueue(NodeQueue*);
void show_list(NodeQueue*);
int length(NodeQueue*);
void clear(NodeQueue*);
void destroy(NodeQueue*);
Node* getHead(NodeQueue*);
bool isQueueEmpty(NodeQueue*);

#endif
