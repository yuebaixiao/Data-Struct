#ifndef __SEQSTACK__
#define __SEQSTACK__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define SEQSTACK_INIT_SIZE 8
#define ADD_SIZE 1000

typedef int ElemType;

typedef struct seqstack{
  int size;
  ElemType *base;
  ElemType *top;
}seqstack;

void init(seqstack*);
void push(seqstack*, ElemType);
void show_list(seqstack*);
void pop(seqstack*);
int length(seqstack*);
void clear(seqstack*);
void destroy(seqstack*);
#endif
