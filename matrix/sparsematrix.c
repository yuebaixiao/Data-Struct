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

void fanzhuan(SMatrix *s1){
  triple tmp;
  for(int i = 0; i < s1->tu - 1; ++i){
    for(int j = 0; j < s1->tu - i - 1; ++j){
      if(s1->data[j].col >= s1->data[j+1].col){
	if(s1->data[j].col == s1->data[j+1].col){
	  if(s1->data[j].row > s1->data[j+1].row){
	    memmove(&tmp, &(s1->data[j]), sizeof(triple));
	    memmove(&(s1->data[j]), &(s1->data[j+1]), sizeof(triple));
	    memmove(&(s1->data[j+1]), &tmp, sizeof(triple));
	  }
	}else{
	  memmove(&tmp, &(s1->data[j]), sizeof(triple));
	  memmove(&(s1->data[j]), &(s1->data[j+1]), sizeof(triple));
	  memmove(&(s1->data[j+1]), &tmp, sizeof(triple));
	}
      }
    }
    
  }
  
  for(int i = 0; i < s1->tu; ++i){
    s1->data[i].row = s1->data[i].row + s1->data[i].col;
    s1->data[i].col = s1->data[i].row - s1->data[i].col;
    s1->data[i].row = s1->data[i].row - s1->data[i].col;
  }
  
}
