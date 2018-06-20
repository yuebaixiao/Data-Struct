#include "SeqList.h"

bool reInit(SeqList* seq){
  ElemType* newp = (ElemType*)realloc(seq->base,(seq->size+1)*sizeof(ElemType));
  if(NULL == newp){
    return true;
  }
  if(seq->base != newp){
    memmove(seq->base, newp, sizeof(ElemType)*seq->size);
    seq->base = newp;
  }
  seq->cap++;
  return false;
}
void init(SeqList* seq){
  seq->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_INIT_SIZE);
  assert(NULL != seq->base);
  seq->cap = SEQLIST_INIT_SIZE;
  seq->size = 0;
}
void push_back(SeqList* seq, ElemType x){
  if(seq->size >= seq->cap && reInit(seq)){
    printf("线性表已满\n");
    return;
  }
  seq->base[seq->size] = x;
  seq->size++;
}
void push_front(SeqList* seq, ElemType x){
  if(seq->size >= seq->cap && reInit(seq)){
    printf("线性表已满\n");
    return;
  }
  memmove(seq->base+1, seq->base,seq->size * sizeof(ElemType));
  seq->base[0] = x;
  seq->size++;
}
void pop_back(SeqList* seq){
  if(seq->size <= 0){
    printf("线性表以空\n");
    return;
  }
  seq->size--;
}
void pop_front(SeqList* seq){
  if(seq->size <= 0){
    printf("线性表以空\n");
    return;
  }
  memmove(seq->base, seq->base+1,seq->size * sizeof(ElemType));
  seq->size--;
}
void insert_pos(SeqList* seq, ElemType x, int index){
  if(seq->size >= seq->cap && reInit(seq)){
    printf("线性表已满\n");
    return;
  }
  if(index < 0 || index > seq->size){
    printf("given index is error\n");
    return;
  }
  memmove(seq->base+index+1,seq->base+index,(seq->size-index)*sizeof(ElemType));
  seq->base[index] = x;
  seq->size++;
}
int find(SeqList* seq, ElemType x){
  for(int i = 0; i < seq->size; ++i){
    if(x == seq->base[i]){
      return i;
    }
  }
  return -1;
}
int length(SeqList* seq){
  return seq->size;
}
void delete_pos(SeqList* seq, int index){
  if(seq->size <= 0){
    printf("线性表以空\n");
    return;
  }
  if(index < 0 || index > seq->size - 1){
    printf("given index is error\n");
    return;
  }
  memmove(seq->base+index,seq->base+index+1,(seq->size-index-1)*sizeof(ElemType));
  seq->size--;
}
void delete_val(SeqList* seq, int value){
  int pos = find(seq, value);
  if(pos == -1){
    printf("The enter value is not exist");
    return;
  }
  delete_pos(seq, pos);
  
}
void sort1(SeqList* seq){
  for(int i = 0; i < seq->size-1; ++i){
    for(int j = 0; j < seq->size-i-1; ++j){
      if(seq->base[j] > seq->base[j+1]){
	ElemType tmp = seq->base[j];
	seq->base[j] = seq->base[j+1];
	seq->base[j+1] = tmp;
      }
    }
  }
}
void sort2(SeqList* seq){
  for(int i = 0; i < seq->size-1; ++i){
    for(int j = 0; j < seq->size-1-i; ++j){
      if(seq->base[j] < seq->base[j+1]){
	seq->base[j] = seq->base[j] + seq->base[j+1];
	seq->base[j+1] = seq->base[j] - seq->base[j+1];
	seq->base[j] = seq->base[j] - seq->base[j+1];
      }
    }
  }
}
void resver(SeqList* seq){
  for(int i = 0; i < seq->size / 2; ++i){
    ElemType tmp = seq->base[i];
    seq->base[i] = seq->base[seq->size-i-1];
    seq->base[seq->size-i-1] = tmp;
  }
}
void clear(SeqList* seq){
  seq->size = 0;
}
void destroy(SeqList* seq){
  free(seq->base);
  seq->base = NULL;
  seq->cap = 0;
  seq->size = 0;
}
void show_list(SeqList* seq){
  for(int i = 0; i < seq->size; ++i){
    printf("%d ", seq->base[i]);
  }
  printf("\n");
}
