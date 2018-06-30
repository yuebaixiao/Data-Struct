#ifndef __WHILEQUEUE__
#define __WHILEQUEUE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
#include <stdbool.h>

#define WHILEQUEUE_INIT_SIZE 8

typedef int ElemType;

typedef struct whilequeue{
  ElemType* base;
  int front;
  int tail;
}whilequeue;

void init(whilequeue*);
void enQueue(whilequeue*, ElemType);
void show_list(whilequeue*);
void deQueue(whilequeue*);
void clear(whilequeue*);
void destroy(whilequeue*);
#endif
