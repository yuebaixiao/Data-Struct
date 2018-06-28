#include "nodestack.h"

Node* createNode(ElemType val){
  Node* n = (Node*)malloc(sizeof(Node));
  n->data = val;
  n->next = NULL;
  return n;
}
void init(nodestack* stack){
  stack->size = 0;
  stack->top = NULL;
  stack->base = NULL;
}
void push(nodestack* stack, ElemType x){
  Node* n = createNode(x);
  //当栈为空的时候
  if(stack->base == NULL){
    stack->top = stack->base = n;
    n->next = NULL;
    stack->size++;
    return;
  }
  n->next = stack->top;
  stack->top = n;
  stack->size++;
}
void show_list(nodestack* stack){
  Node* top = stack->top;
  while(top != NULL){
    printf("%d\n", top->data);
    top = top->next;
  }
}
void pop(nodestack* stack){
  if(stack->size == 0)return;

  Node* n = stack->top;
  stack->top = stack->top->next;
  free(n);
  stack->size--;
}
int length(nodestack* stack){
  return stack->size;
}
void clear(nodestack* stack){
  Node* top = stack->top;
  Node* tmp;
  while(top != NULL){
    tmp = top;
    top = top->next;
    free(tmp);
  }
  stack->top = stack->base = NULL;
  stack->size = 0;
}
void destroy(nodestack* stack){
  clear(stack);
}
