#include "SeqList.h"

void init(SeqList* seq){
  seq->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
  assert(NULL != seq->base);
  seq->cap = SEQLIST_INIT_SIZE;
  seq->size = 0;
}
void push_back(SeqList* seq, ElemType x){
  if(seq->size >= seq->cap){
    printf("线性表已满\n");
    return;
  }
  seq->base[seq->size] = x;
  seq->size++;
}
void push_front(SeqList* seq, ElemType x){
  if(seq->size >= seq->cap){
    printf("线性表已满\n");
    return;
  }
  memmove(seq->base+1, seq->base,seq->size * sizeof(ElemType));
  seq->base[0] = x;
  seq->size++;
}
void pop_back(SeqList* seq){
  if(seq->size <= 0){
    printf("线性表以空\n");
    return;
  }
  seq->size--;
}
void pop_front(SeqList* seq){
  if(seq->size <= 0){
    printf("线性表以空\n");
    return;
  }
  memmove(seq->base, seq->base+1,seq->size * sizeof(ElemType));
  seq->size--;
}
void insert_pos(SeqList* seq, ElemType x, int index){
  if(seq->size >= seq->cap){
    printf("线性表已满\n");
    return;
  }
  if(index < 0 || index > seq->size){
    printf("given index is error\n");
    return;
  }
  memmove(seq->base+index+1,seq->base+index,(seq->size-index)*sizeof(ElemType));
  seq->base[index] = x;
  seq->size++;
}
int find(SeqList* seq, ElemType x){

}
void show_list(SeqList* seq){
  for(int i = 0; i < seq->size; ++i){
    printf("%d ", seq->base[i]);
  }
  printf("\n");
}
