#include "sparsematrix.h"

int main(){
  SMatrix sm;
  memset(&sm,0,sizeof(SMatrix));
  createMatrix(&sm);
  printMatrix(&sm);
  fanzhuan(&sm);
  printMatrix(&sm);
}
