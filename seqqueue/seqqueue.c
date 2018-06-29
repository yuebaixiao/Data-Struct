#include "seqqueue.h"

void init(seqqueue* seq){
  seq->base = (ElemType*)malloc(sizeof(ElemType) * SEQQUEUE_INIT_SIZE);
  seq->front = seq->tail = 0;
}
void enQueue(seqqueue* seq, ElemType x){
  if(seq->tail == SEQQUEUE_INIT_SIZE -1){
    printf("queue is full\n");
    return;
  }
  seq->base[seq->tail++] = x;
}
void show_list(seqqueue* seq){
  int i = seq->front;
  while(i <= seq->tail-1){
    printf("%d\n", seq->base[i++]);
  }
}
void deQueue(seqqueue* seq){
  if(seq->front < SEQQUEUE_INIT_SIZE - 1){
    seq->front++;
  }
}
void clear(seqqueue* seq){
 
}
void destroy(seqqueue* seq){

}
