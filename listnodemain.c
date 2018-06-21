#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define ElemType int

typedef struct listnode{
  ElemType data;
  struct listnode* next;
}listnode;

void init(listnode** head, int val){
  *head = (listnode*)malloc(sizeof(listnode));
  (*head)->data = val; 
  (*head)->next = NULL; 
}
void create(listnode* head,size_t size){
  listnode* tmp = head;
  for(int i = 1; i < size; ++i){
    listnode* p = (listnode*)malloc(sizeof(listnode));
    assert(NULL != p);
    p->data = i;
    p->next = NULL;

    tmp->next = p;
    tmp = p;
  }
}
listnode* create1(listnode* tail, size_t size){
  listnode* tmp = tail;
  listnode* head;
  for(int i = 0; i < size; ++i){
    listnode* p = (listnode*)malloc(sizeof(listnode));
    assert(NULL != p);
    if(i == size - 1){
      head = p;
    }
    p->data = i;
    p->next = tmp;

    tmp = p;
  }
  return head;
}
void showlist(listnode* ln){
  printf("%d->", ln->data);
  if(NULL == ln->next) {
    printf("NULL\n");
    return;
  }
  showlist(ln->next);
}
int main(){
  listnode* head;
  init(&head,111);
  create(head, 10);
  showlist(head);

  listnode* tail;
  init(&tail,222);
  listnode* head1;
  head1 = create1(tail, 10);
  showlist(head1);
}


