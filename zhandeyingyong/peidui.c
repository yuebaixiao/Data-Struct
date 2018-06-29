#include <stdio.h>
#include <malloc.h>
#include <string.h>

void pop(char** top){
  --(*top);
}
void push (char** top, char * base, char s){
  char* tmp = *top;
  if(*top == base || s != *--tmp){
    *(*top)++ = s;
  }
  else{
    pop(top);
  }
}
int main(){
  //char* s = "[([][])]";
  char* s = "[]";
  char *top, *base;
  top = base = (char*)malloc(sizeof(char) * strlen(s));
  int i = 0;
  for(; i < strlen(s); ++i){
    push(&top, base, s[i]);
  }
  if(top == base && s[i+1] == '\0'){
    printf("success\n");
  }
  free(base);
}
