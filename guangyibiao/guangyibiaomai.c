#include "guangyibiao.h"

int main(){
  GenList gl;
  init(&gl);
  
  char* a = "(1,2,3)";
  char* b = "(1,(2,3))";
  char* c = "(1,(2),3)";
  char* d = "((1,2),3)";
  char* e = "((1,2,3))";
  char* f = "()";
  char* g = "(1,(2,(3,4)),5)";
  createGenList(&gl, a);
}
