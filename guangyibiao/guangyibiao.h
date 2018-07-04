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

typedef enum{HEAD, ATOM, CHILDLIST}ElemTag;
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

#endif
