#ifndef __GUANGYIBIAO__
#define __GUANGYIBIAO__

#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#define AtomType int

typedef enum{ATOM, LIST}ElemTag;
typedef struct GLNode{
  ElemTag tag;
  union{
    AtomType atom;
    struct GLNode* head;
  };
  struct GLNode* tail;
}GLNode;

typedef GLNode* GenList;

void init(GenList* gl);
void createGenList(GenList* gl, char* s);
void show(GenList gl);
void destroy(GenList gl);
void copy(GenList* dest, GenList src);
int length(GenList gl);
int depth(GenList gl);
bool isEmpty(GenList gl);
GLNode* getHead(GenList gl);
GLNode* getTail(GenList gl);
void push_head(GenList* gl, GLNode* node);
void push_tail(GenList gl, GLNode* node);
void pop_head(GenList* gl);
void pop_tail(GenList* gl);

#endif
