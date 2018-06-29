#include "nodequeue.h"

void init(NodeQueue* queue){
  queue->front = queue->tail = (Node*)malloc(sizeof(Node));
  queue->tail->next = NULL;
  queue->size = 0;
}
//入队(尾插)
void enQueue(NodeQueue* queue, ElemType val){
  Node* p = (Node*)malloc(sizeof(Node));
  p->data = val;
  if(queue->front->next == NULL){
    queue->front->next = p;
  }
  else{
    queue->tail->next = p;
  }
  queue->tail = p;  
  p->next = NULL;
  queue->size++;
}
//出队(头删)
void deQueue(NodeQueue* queue){
  if(queue->size == 0)return;
  Node* tmp = queue->front->next;
  queue->front->next = queue->front->next->next;
  free(tmp);
  queue->size--;
}
int length(NodeQueue* queue){
  return queue->size;
}
void show_list(NodeQueue* queue){
  Node* p = queue->front;
  while(p->next != NULL){
    printf("%d\n", p->next->data);
    p = p->next;
  }
}
void clear(NodeQueue* queue){
  if(queue->size == 0)return;  
  Node* p = queue->front;
  Node* tmp;
  while(p->next != NULL){
    tmp = p->next;
    p = p->next;
    free(tmp);
  }
  queue->tail = queue->front;
  queue->tail->next = NULL;
  queue->size = 0;  
}
void destroy(NodeQueue* queue){
  clear(queue);
  free(queue->front);
}

