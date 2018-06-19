#ifndef __SEQLIST__
#define __SEQLIST__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define SEQLIST_INIT_SIZE 8
typedef int ElemType;

typedef struct SeqList{
  int cap;
  int size;
  ElemType *base;
}SeqList;

void init(SeqList*);

#endif
