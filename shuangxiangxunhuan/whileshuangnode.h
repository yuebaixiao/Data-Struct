#ifndef __WHILESHUANGNODE__
#define __WHILESHUANGNODE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define ElemType int

typedef struct Node{
  ElemType data;
  struct Node* before;
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
void pop_back(NodeList*);
void pop_front(NodeList*);
void show_list(NodeList*);
void insert_val(NodeList*, ElemType);
Node* find(NodeList*, ElemType);
void delete_val(NodeList*, ElemType);
void sort(NodeList*);
void sort1(NodeList*);
void resver(NodeList*);
void resver1(NodeList*);
void resver2(NodeList*);
void clear(NodeList*);
void destroy(NodeList*);

#endif
