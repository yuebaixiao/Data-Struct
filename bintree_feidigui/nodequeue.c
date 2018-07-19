#include "nodequeue.h"

void init_queue(NodeQueue* queue){
  queue->front = queue->tail = (Node1*)malloc(sizeof(Node1));
  queue->tail->next = NULL;
  queue->size = 0;
}
//入队(尾插)
void enQueue(NodeQueue* queue, ElemType1 val){
  Node1* p = (Node1*)malloc(sizeof(Node1));
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
  Node1* tmp = queue->front->next;
  queue->front->next = queue->front->next->next;
  free(tmp);
  queue->size--;
}
int length(NodeQueue* queue){
  return queue->size;
}
void show_list(NodeQueue* queue){
  Node1* p = queue->front;
  while(p->next != NULL){
    printf("%d\n", p->next->data);
    p = p->next;
  }
}
void clear(NodeQueue* queue){
  if(queue->size == 0)return;  
  Node1* p = queue->front;
  Node1* tmp;
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

Node1* getHead(NodeQueue* queue){
  return queue->front->next;
}

bool isQueueEmpty(NodeQueue* queue){
  return queue->front == queue->tail;
}
