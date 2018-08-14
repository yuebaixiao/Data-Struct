#ifndef __HASH_TABLE__
#define __HASH_TABLE__

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#define ElemType int
#define P 13

typedef struct HashNode{
  ElemType data;
  struct HashNode* link;
}HashNode;

typedef HashNode* HashTable[P];

void init_hash(HashTable ht){
  for(int i = 0; i < P; ++i){
    ht[i] = NULL;
  }
}

int hash(ElemType key){
  return key % P;
}
void insert_hash_table(HashTable ht, ElemType x){
  int index = hash(x);
  HashNode* s = (HashNode*)malloc(sizeof(HashNode));
  assert(s != NULL);
  s->data = x;

  //头插
  s->link = ht[index];
  ht[index] = s;
}

void show_hash_table(HashTable ht){
  for(int i = 0; i < P; ++i){
    printf("%d: ", i);
    HashNode* p = ht[i];
    while(NULL != p){
      printf("%d->", p->data);
      p = p->link;
    }
    printf("Nul.\n");
  }
}
HashNode* search_hash_table(HashTable ht, ElemType x){
  int index = hash(x);
  HashNode* p = ht[index];
  while(NULL != p && p->data != x){
    p = p->link;
  }
  return p;
}
bool remove_hash_node(HashTable ht, ElemType x){
  HashNode* p = search_hash_table(ht, x);
  if(NULL == p)return false;

  int index = hash(x);
  HashNode* q = ht[index];
  if(p == q){
    ht[index] = p->link;
    free(p);
    return true;
  }
  while(q->link != p){
    q = q->link;
  }
  q->link = p->link;
  free(p);
  return true;
}
int main(){

  HashTable ht;
  init_hash(ht);

  ElemType ar[] = {19,14,23,1,68,20,84,27,55,11,10,79};
  int n = sizeof(ar) / sizeof(ElemType);

  for(int i = 0; i < n; ++i){
    insert_hash_table(ht, ar[i]);
  }

  show_hash_table(ht);

  ElemType key = 68;
  HashNode* p = search_hash_table(ht, key);
  if(NULL != p){
    printf("%d\n", p->data);
  }

  remove_hash_node(ht, key);
  show_hash_table(ht);

  return 0;

}

#endif
