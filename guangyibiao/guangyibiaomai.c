#include "guangyibiao.h"

int main(){
  GenList gl;
  init(&gl);
  
  char* a = "(1,2,3)";
  char* b = "(1,(2,3))";
  char* c = "(1,(2),3)";
  char* d = "((1,2),3)";
  char* e = "((1,2,3))";
  char* f = "((),1)";
  char* g = "(1,(2,(3,4)),5)";
  char* h = "((),1,(2,(3,(),4)),5)";
  char* i = "(())";
  
  createGenList(&gl, i);
  if(gl != NULL){
    printf("(");
    show(gl);
    printf(")\n");
  }
  
  return 0;
}
