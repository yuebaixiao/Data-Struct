#include "SeqList.h"

void init(SeqList* seq){
  seq->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
  assert(NULL != seq->base);
  seq->cap = SEQLIST_INIT_SIZE;
  seq->size = 0;
}
