#ifndef __SEQLIST__
#define __SEQLIST__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>

#define SEQLIST_INIT_SIZE 8
typedef int ElemType;

typedef struct SeqList{
  int cap;
  int size;
  ElemType *base;
}SeqList;

void init(SeqList*);
void push_back(SeqList*, ElemType);
void show_list(SeqList*);
void push_front(SeqList*, ElemType);
void pop_back(SeqList*);
void pop_front(SeqList*);
#endif
