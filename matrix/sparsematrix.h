#ifndef __SPARSEMATRIX__
#define __SPARSEMATRIX__

#include <stdio.h>
#include <memory.h>

#define ElemType int
#define MAXSIZE 100

typedef struct triple{
  int row;
  int col;
  ElemType e;
}triple;

typedef struct SMatrix{
  triple data[MAXSIZE];
  int mu;
  int nu;
  int tu;
}SMatrix;

void createMatrix(SMatrix *sm);
void printMatrix(SMatrix *sm);

#endif
