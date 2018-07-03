#include "sparsematrix.h"

void createMatrix(SMatrix *sm){
  FILE *fp = fopen("matrix.txt", "r");
  if(NULL == fp) return;

  fscanf(fp, "%d %d", &sm->mu, &sm->nu);

  int val;
  int k = 0;
  for(int i = 0; i < sm->mu; ++i){
    for(int j = 0; j < sm->nu; ++j){
      fscanf(fp, "%d", &val);
      if(0 != val){
	sm->data[k].e = val;
	sm->data[k].row = i;
	sm->data[k].col = j;
	k++;
      }
    }
  }
  sm->tu = k;
  fclose(fp);
}

void printMatrix(SMatrix *sm){
  printf("row=%d, col=%d\n", sm->mu, sm->nu);
  for(int i = 0; i < sm->tu; ++i){
    printf("(%d, %d, %d)\n", sm->data[i].row, sm->data[i].col, sm->data[i].e);
  }
}
