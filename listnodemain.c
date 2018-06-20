#include <stdio.h>
#include <assert.h>
#include <malloc.h>

#define ElemType int

typedef struct listnode{
  ElemType data;
  struct listnode* next;
}listnode;

void init(listnode** head){
  *head = (listnode*)malloc(sizeof(listnode));
  (*head)->data = 0;
}
void create(listnode* head){
  listnode* tmp = head;
  for(int i = 1; i < 10; ++i){
    listnode* p = (listnode*)malloc(sizeof(listnode));
    assert(NULL != p);
    p->data = i;
    p->next = NULL;

    tmp->next = p;
    tmp = p;
  }
}
void showlist(listnode* ln){
  printf("%d ", ln->data);
  if(NULL == ln->next) {
    printf("\n");
    return;
  }
  showlist(ln->next);
}
int main(){
  listnode* head;
  init(&head);
  create(head);
  showlist(head);

  
}


