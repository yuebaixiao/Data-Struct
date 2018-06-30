#include "whilequeue.h"

void init(whilequeue* seq){
  seq->base = (ElemType*)malloc(sizeof(ElemType) * WHILEQUEUE_INIT_SIZE);
  seq->front = seq->tail = 0;
}
void enQueue(whilequeue* seq, ElemType x){
  if((seq->tail + 1) % WHILEQUEUE_INIT_SIZE == seq->front){
    printf("queue is full\n");
    return;
  }
  seq->base[seq->tail] = x;
  seq->tail = (seq->tail + 1) % WHILEQUEUE_INIT_SIZE;
}
void show_list(whilequeue* seq){
  int i = seq->front;
  while(i != seq->tail){
    printf("%d\n", seq->base[i++ % WHILEQUEUE_INIT_SIZE]);
    i = i % WHILEQUEUE_INIT_SIZE;
  }
}
void deQueue(whilequeue* seq){
  if(seq->front == seq->tail)return;
  seq->front = (seq->front + 1) % WHILEQUEUE_INIT_SIZE;
}
void clear(whilequeue* seq){
 
}
void destroy(whilequeue* seq){

}
