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
  Node* p = (Node*)malloc(sizeof(Node));
  p->data = val;
  p->next = list->first->next;
  list->first->next = p;
  if(list->size == 0){
    list->last = p;
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
  p->next = NULL;
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
  Node* p = (Node*)malloc(sizeof(Node));
  p->data = val;
  Node* t = list->first;
  do{
    if(val >= t->data && t->next != NULL && val <= t->next->data){
      p->next = t->next;
      t->next = p;
      break;
    }
    if(t->next == NULL){
      list->last->next = p;
      list->last = p;
      list->last->next = NULL;
      break;
    }
    t = t->next;
  }
  while(1);
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
      break;
    }
    p = p->next;
  }
  while(NULL != p);
}
void delete_val(NodeList* list, ElemType val){
  if(0 == list->size)return;
  Node* p = list->first;
  do{
    if(p->next->data == val){
      if(NULL == p->next->next){
	list->last = p;
      }
      free(p->next);
      p->next = p->next->next;
      list->size--;
      break;
    }
    p = p->next;
  }while(NULL != p->next);
}
void delete_val1(NodeList* list, ElemType val){
  if(0 == list->size)return;
  Node* p = find(list, val);
  if(NULL == p)return;
  if(p == list->last){
    pop_back(list);
  }
  else{
    p->data = p->next->data;
    free(p->next);
    p->next = p->next->next;
    if(NULL == p->next){
      list->last = p;
    }
    list->size--;
  }
}
void sort(NodeList* list){
  if(list->size == 0 || list->size == 1)return;
  Node* p = list->first->next;
  for(int i = 0; i < list->size-1; ++i){
    for(int j = 0; j < list->size-i-1; ++j){
      if(p->data > p->next->data){
	p->data = p->data + p->next->data;
	p->next->data = p->data - p->next->data;
	p->data = p->data - p->next->data;
      }
      p = p->next;
    }
    p = list->first->next;
  }
}

void insert_pnt(NodeList* list, Node* node){
  Node* t = list->first;
  do{
    if(t->next != NULL && node->data <= t->next->data){
      node->next = t->next;
      t->next = node;
      break;
    }
    if(t->next == NULL){
      list->last->next = node;
      list->last = node;
      list->last->next = NULL;
      break;
    }
    t = t->next;
  }
  while(1);
  list->size++;
}
void sort1(NodeList* list){
  if(list->size == 0 || list->size == 1)return;

  Node* n = list->first->next->next;

  list->size = 1;
  list->last = list->first->next;
  list->last->next = NULL;

  Node* t;
  while(NULL != n){
    t = n->next;
    insert_pnt(list, n);
    n = t;
  }
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
