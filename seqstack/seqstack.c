#include "seqstack.h"

bool reInit(seqstack* seq){
  ElemType* new = (ElemType*)realloc(seq->base, ADD_SIZE *sizeof(ElemType));
  if(NULL == new)return true;
  if(seq->base != new){
    memmove(new, seq->base, seq->size * sizeof(ElemType));
    seq->base = new;
    seq->top = seq->base + seq->size + 1;
  }
  return false;
}
void init(seqstack* seq){
  ElemType* e = (ElemType*)malloc(sizeof(ElemType) * SEQSTACK_INIT_SIZE);
  seq->base = seq->top = e;
  seq->size = 0;
}
void push(seqstack* seq, ElemType x){
  if(seq->size >= SEQSTACK_INIT_SIZE && reInit(seq)){
    printf("stack is full\n");
    return;
  }
  //先赋值，后移动top的指向
  *((seq->top)++) = x;
  seq->size++;
}
void show_list(seqstack* seq){
  ElemType* e = seq->top;
  while(e-- != seq->base){
    printf("%d\n",*e);
  }
}
void pop(seqstack* seq){
  --seq->top;
  seq->size--;
}
int length(seqstack* seq){
  return seq->size;
}
void clear(seqstack* seq){
  seq->top = seq->base;
  seq->size = 0;
}
void destroy(seqstack* seq){
  free(seq->base);
}
