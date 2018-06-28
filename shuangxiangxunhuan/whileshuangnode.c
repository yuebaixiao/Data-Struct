#include "whileshuangnode.h"

void init(NodeList* list){
  list->first = (Node*)malloc(sizeof(Node));
  list->last = list->first;
  list->first->before = list->last;
  list->last->next = list->first;
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
  p->next = list->first;
  
  list->first->before = p;
  list->last->next = p;

  list->last = p;
  
  list->size++;
}

void push_front(NodeList* list, ElemType val){
  Node* p = create_node(val);

  //设置p的before和next
  p->before = list->first;
  
  //第一次添加节点的时候要移动未指针,还要设置first的before
  if(list->first == list->first->next){
    list->last = p;
    p->next = list->first;
    list->first->before = p;
  }
  //不是第一次添加节点的时候，要把原第一个节点的before指向，新添加的节点
  else{
    p->next = list->first->next;
    list->first->next->before = p;
  }
  //设置头指针的next节点
  list->first->next = p;
  
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
  
  free(list->last);
  //让尾指针的next指向NULL
  list->last->before->next = list->first;
  //让first的before指向新的尾节点
  list->first->before = list->last->before;
  //让尾指针指向原尾节点的前一个节点
  list->last = list->last->before;

  list->size--;
}
void pop_front(NodeList* list){
  if(list->size == 0)return;

  free(list->first->next);
  //就剩一个节点的时候，要移动尾指针。
  if(list->first->next == list->last){
    list->last = list->first;
    list->last->next = list->first;
    list->first->before = list->last;
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
  while(p->next != list->first && val > p->next->data){
    p = p->next;
  }
  //第一次加节点，或者，最后一个节点的值也没有比给的值大的时候
  if(list->first == p->next){
    n->next = list->first;
    n->before = list->last;
    list->last->next = n;
    list->first->before = n;
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
  while(p->next != list->first && p->next->data != val){
    p = p->next;
  }
  if(list->first == p->next){
    return NULL;
  }
  printf("%d is found\n", p->next->data);
  return p->next;
}
void delete_val(NodeList* list, ElemType val){
  Node* p = find(list, val);
  if(NULL == p) return;

  //删除的节点是尾节点的时候，要移动last
  if(p == list->last){
    list->last = p->before;
    p->before->next = list->first;
    list->first->before = p->before;
    list->size--;
    return;
  }

  p->before->next = p->next;
  p->next->before = p->before;

  free(p);

  list->size--;
}

void sort(NodeList* list){
  if(list->size == 1 || list->size == 0)return;

  //p为第一个节点
  Node* p = list->first->next;

  //ｔ是空白list，往t里加节点
  Node* t = list->first;
  list->last = list->first;
  list->last->next = list->first;
  list->first->before = list->last;
  
  size_t sz = list->size;
  
  Node* tmp;
  
  while(sz-- > 0){
    //p的next会被改变，所以提前保存
    tmp = p->next;
    while(t->next != list->first && p->data > t->next->data){
      t = t->next;
    }
    //ｔ为first，或者t为last,都是尾插
    if(t->next == list->first){
      t->next = p;
      p->next = list->first;
      p->before = t;
      list->first->before = p;
      list->last = p;
    }
    else{
      p->next = t->next;
      t->next->before = p;

      t->next = p;
      p->before = t;
    }

    p = tmp;
    t = list->first;
  }
}

void resver(NodeList* list){
  if(list->size == 1 || list->size == 0)return;

  //第一个节点
  Node* head = list->first->next;
  //第二个节点
  Node* second = head->next;
  //head就是last，所以要head->next = NULL;
  list->last = head;
  list->last->next = list->first;
  list->first->before = list->last;

  Node* tmp;
  while(second != list->first){
    //必须保存second的next，因为下面的代码，会改变second的next
    tmp = second->next;

    //头插
    second->next = list->first->next;
    list->first->next->before = second;
    list->first->next = second;
    second->before = list->first;
    
    second = tmp;
  }
}

void clear(NodeList* list){
  Node* p = list->first->next;
  while(p != list->last){
    p = p->next;
    free(p);    
  }
  list->last = list->first;
  list->last->next = list->first;
  list->first->before = list->last;
  list->size = 0;
}

void destroy(NodeList* list){
  clear(list);
  free(list->first);
}
