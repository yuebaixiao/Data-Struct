#include "seqnode.h"


void init(NodeList* list){
  list->first = (Node*)malloc(sizeof(Node));
  list->first->next = NULL;
  list->last = list->first;
  list->size = 0;
}

void push_back(NodeList* list, ElemType val){
  list->last = (Node*)malloc(sizeof(Node));
  list->last->data = val;
  list->last->next = NULL;
  list->size++;
}

void show_list(NodeList* list){
  while(list){}
}
