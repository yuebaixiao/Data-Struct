#include "seqnode.h"

void init(NodeList* list){
  list->first = (Node*)malloc(sizeof(Node));
  list->last = list->first;
  list->first->next = NULL;
  list->size = 0;
}

void push_back(NodeList* list, ElemType val){
  Node* p = (Node*)malloc(sizeof(Node));
  if(list->first->next == NULL){
    list->first->next = p;
    list->last = p;
    list->last->data = val;
    list->last->next = NULL;
    list->size++;
    return;
  }
  Node* p1 = list->last;
  list->last = p;
  p1->next = p;

  list->last->data = val;
  list->last->next = NULL;
  list->size++;
}

void push_front(NodeList* list, ElemType val){
  Node* p = (Node*)malloc(sizeof(Node));
  p->next = list->first->next;
  list->first->next = p;
  list->last = p;
  list->last->data = val;
  list->size++;
}

void show_list(NodeList* list){
  Node* tmp = list->first->next;
  while(tmp != NULL){
    printf("%d->", tmp->data);
    tmp = tmp->next;
  }
  printf("NULL\n");
}
