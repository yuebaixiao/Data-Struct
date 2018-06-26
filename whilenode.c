#include "seqnode.h"

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
  node->next = NULL;
  return node;
}
void push_back(NodeList* list, ElemType val){
  Node* p = create_node(val);

  list->last->next = p;
  list->last = p;
  list->last->next = list->first;
  list->size++;
}

void push_front(NodeList* list, ElemType val){
  Node* p = create_node(val);

  p->next = list->first->next;
  list->first->next = p;
  if(list->size == 0){
    list->last = p;
    list->last->next = list->first;
  }
  list->size++;
}

void show_list(NodeList* list){
  Node* tmp = list->first->next;
  while(tmp != list->first){
    printf("%d->", tmp->data);
    tmp = tmp->next;
  }
  printf("NULL\n");
}

void pop_back(NodeList* list){
  if(list->size == 0)return;
  Node* p = list->first;
  while(p->next != list->last){
    p = p->next;
  }
  p->next = list->first;
  free(list->last);
  list->last = p;
  list->size--;
}
void pop_front(NodeList* list){
  if(list->size == 0)return;
  Node* p = list->first->next;
  list->first->next = p->next;
  if(list->size == 1){
    list->last = list->first;
  }
  list->size--;
  free(p);
}
void insert_val(NodeList* list, ElemType val){
  if(list->size == 0){
    push_back(list, val);
    return;
  }
  Node* p = create_node(val);

  Node* t = list->first;
  while(t->next != list->first && val > t->next->data){
    t = t->next;
  }
  if(t->next == list->first){
    list->last = p;
  }
  p->next = t->next;
  t->next = p;
  
  list->size++;
}
Node* find(NodeList* list, ElemType val){
  if(0 == list->size){
    return NULL;
  }
  Node* p = list->first->next;
  do{
    if(val == p->data){
      return p;
    }
    p = p->next;
  }
  while(list->first != p);
  return NULL;
}
Node* find1(NodeList* list, ElemType val){
  if(0 == list->size){
    return NULL;
  }
  Node* p = list->first;
  do{
    if(p->next->data == val){
      return p;
    }
    p = p->next;
  }while(list->first != p);
  return NULL;
}
void delete_val(NodeList* list, ElemType val){
  if(0 == list->size)return;
 
  Node* p = find1(list, val);
  if(NULL == p)return;
  if(p->next == list->last){
    list->last = p;
  }
  Node* tmp = p->next;
  p->next = p->next->next;
  free(tmp);
  list->size--;
}

void sort(NodeList* list){
  if(list->size == 0 || list->size == 1)return;

  Node* p = list->first->next;

  Node* t = list->last = list->first;
  list->last->next = list->first;

  size_t s = list->size;

  while(s-- > 0){
    while(p->data > t->next->data && t->next != list->first){
      t = t->next;
    }
    if(t->next == list->first){
      list->last = p;
    }

    Node* tmp = p->next;
    p->next = t->next;
    t->next = p;

    p = tmp;
    t = list->first;
  }
  list->last->next = list->first;
}
void push_back_pnt(NodeList* list, Node* node){
  list->last->next = node;
  list->last = node;
  list->last->next = NULL;
  list->size++;
}
void resver(NodeList* list){
  if(list->size == 0 || list->size == 1)return;

  Node* e = list->last;
  Node* b = list->first->next;
  Node* tmp = list->first;
  size_t sz = list->size;

  list->last = list->first;
  list->size = 0;

  while(sz-- > 0){
    while(tmp->next != e && b != e){
      tmp = tmp->next;
    }
    if(b == e){
      push_back_pnt(list, b);
    }else{
      push_back_pnt(list, tmp->next);
    }
    e   = tmp;
    tmp = b;
  }
}

void push_front_pnt(NodeList* list, Node* node){
  node->next = list->first->next;
  list->first->next = node;
  list->size++;
}
void resver1(NodeList* list){
  if(list->size == 0 || list->size == 1)return;

  Node* head = list->first->next->next;

  list->last = list->first->next;
  list->last->next = NULL;
  list->size = 1;

  Node* tmp;
  while(head != NULL){
    tmp = head->next;
    push_front_pnt(list, head);
    head = tmp;
  }
}
void resver2(NodeList* list){
  if(list->size == 0 || list->size == 1)return;

  Node* p = list->first->next->next;
  list->last = list->first->next;
  list->last->next = NULL;

  Node* q;
  while(p != NULL){
    q = p->next;
    p->next = list->first->next;
    list->first->next = p;
    p = q;
  }
}

void clear(NodeList* list){
  if(list->size == 0) return;
  Node* b = list->first->next;
  Node* q;
  while(b != NULL){
    q = b->next;
    free(b);
    b = q;
  }
  list->last = list->first;
  list->last->next = NULL;
  list->size = 0;
}

void destroy(NodeList* list){
  Node* b = list->first;
  Node* q;
  while(b != NULL){
    q = b->next;
    free(b);
    b = q;
  }
}
