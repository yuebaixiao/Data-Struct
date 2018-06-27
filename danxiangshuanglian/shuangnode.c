#include "shuangnode.h"

void init(NodeList* list){
  list->first = (Node*)malloc(sizeof(Node));
  list->last = list->first;
  list->last->next = NULL;
  list->size = 0;
}

Node* create_node(ElemType val){
  Node* node = (Node*)malloc(sizeof(Node));
  assert(NULL != node);
  node->data = val;
  node->before = NULL;
  node->next = NULL;
  return node;
}
void push_back(NodeList* list, ElemType val){
  Node* p = create_node(val);

  p->before = list->last;
  p->next = NULL;
  
  list->last->next = p;
  list->last = p;
  
  list->size++;
}

void push_front(NodeList* list, ElemType val){
  Node* p = create_node(val);

  //设置p的before和next
  p->before = list->first;
  p->next = list->first->next;
  //第一次添加节点的时候要移动未指针
  if(NULL == list->first->next){
    list->last = p;
  }
  //不是第一次添加节点的时候，要把原第一个节点的before指向，新添加的节点
  else{
    list->first->next->before = p;
  }
  //设置头指针的next节点
  list->first->next = p;
  
  list->size++;
}

void show_list(NodeList* list){
  Node* tmp = list->first->next;
  while(tmp != NULL){
    printf("%d->", tmp->data);
    tmp = tmp->next;
  }
  printf("NULL\n");
}

void pop_back(NodeList* list){
  if(list->size == 0)return;
  
  free(list->last);
  //让尾指针的next指向NULL
  list->last->before->next = NULL;
  //让尾指针指向原尾节点的前一个节点
  list->last = list->last->before;

  list->size--;
}
void pop_front(NodeList* list){
  if(list->size == 0)return;

  free(list->first->next);
  //就剩一个节点的时候，要移动尾指针。因为list->first->next已经为NULL，下面的list->first->next->before就会在执行时候崩掉，所以要return掉
  if(list->first->next == list->last){
    list->last = list->first;
    list->last->next = NULL;
    list->size--;
    return;
  }
  
  //头指针的next指向第二个节点
  list->first->next = list->first->next->next;
  //第二个节点的before指向头节点
  list->first->next->before = list->first;

  list->size--;
}
void insert_val(NodeList* list, ElemType val){
  Node* n = create_node(val);;
  
  Node* p = list->first;
  while(p->next != NULL && val > p->next->data){
    p = p->next;
  }
  //第一次加节点，或者，最后一个节点也没有给的值大的时候
  if(NULL == p->next){
    n->next = NULL;
    n->before = list->last;
    list->last->next = n;
    list->last = n;
    list->size++;
    return;
  }
  //新节点的next指向原节点的下一个节点
  n->next = p->next;
  //原节点的next指向新节点，注意这句的位置必须在上句的下面
  p->next = n;
  //新节点的下一个节点的before指向新节点
  n->next->before = n;
  //新节点的before指向原节点
  n->before = p;

  list->size++;
}
//寻找给定值的节点的位置
Node* find(NodeList* list, ElemType val){
  if(list->size == 0)return NULL;

  Node* p = list->first;
  while(p->next != NULL && p->next->data != val){
    p = p->next;
  }
  if(NULL == p->next){
    return NULL;
  }
  printf("%d is found\n", p->next->data);
  return p->next;
}
//寻找给定值的节点的前一个节点的位置
Node* find1(NodeList* list, ElemType val){
  if(list->size == 0)return NULL;

  Node* p = list->first;
  while(p->next != NULL && p->next->data != val){
    p = p->next;
  }
  if(NULL == p->next){
    return NULL;
  }
  printf("%d is found\n", p->next->data);
  return p;
}
void delete_val(NodeList* list, ElemType val){
  Node* p = find1(list, val);
  if(NULL == p) return;

  free(p->next);
  //删除的节点是尾节点的时候，要移动last
  if(p->next == list->last){
    list->last = p;
    p->next = NULL;
    list->size--;
    return;
  }

  p->next->next->before = p;
  p->next = p->next->next;

  list->size--;
}

void sort(NodeList* list){
  
}

void resver(NodeList* list){
  if(list->size == 1 || list->size == 0)return;

  //第一个节点
  Node* head = list->first->next;
  //第二个节点
  Node* second = head->next;
  //head就是last，所以要head->next = NULL;
  list->last = head;
  list->last->next = NULL;

  Node* tmp;
  while(second != NULL){
    //必须保存second的next，因为下面的代码，会改变second的next
    tmp = second->next;
    second->next = list->first->next;
    list->first->next->before = second;

    list->first->next = second;
    second->before = list->first;
    
    second = tmp;
  }
}

void clear(NodeList* list){
  Node* p = list->first->next;
  while(p != NULL){
    free(p);
    p = p->next;
  }
  list->last = list->first;
  list->last->next = NULL;
  list->size = 0;
}

void destroy(NodeList* list){
  Node* p = list->first;
  while(p != NULL){
    free(p);
    p = p->next;
  }
  list->size = 0;  
}
