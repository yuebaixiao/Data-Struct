#ifndef __SEQLIST__
#define __SEQLIST__

#define SEQLIST_INIT_SIZE 8
typedef int ElemType;

typedef struct SeqList{
  ElemType *base;
  int cap;
  int size;
}SeqList;
#endif
