#ifndef __SEQQUEUE__
#define __SEQQUEUE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define SEQQUEUE_INIT_SIZE 8

typedef int ElemType;

typedef struct seqqueue{
  ElemType* base;
  int front;
  int tail;
}seqqueue;

void init(seqqueue*);
void enQueue(seqqueue*, ElemType);
void show_list(seqqueue*);
void deQueue(seqqueue*);
void clear(seqqueue*);
void destroy(seqqueue*);
#endif
