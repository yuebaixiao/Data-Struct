#ifndef __SEQNODE__
#define __SEQNODE__

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

typedef struct NodeList{
  Node*  first;
  Node*  last;
  size_t size;
}NodeList;

void init(NodeList*);
void push_back(NodeList*, ElemType);
void push_front(NodeList*, ElemType);
void show_list(NodeList*);
#endif
