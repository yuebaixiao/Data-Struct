#include <stdio.h>
#include <malloc.h>
#include <string.h>

void pop(char** top){
  --(*top);
}
void push (char** top, char * base, char s){
  switch (s){
  case ']':
    s = '[';
    break;
  case ')':
    s = '(';
    break;
  case '}':
    s = '{';
    break;
  default:
    break;
  }
  //保存top的指向
  char* tmp = *top;
  //第一次压栈，或者，s和栈顶的值不相同就继续压栈
  if(*top == base || s != *--tmp){
    *(*top)++ = s;
  }
  //s和栈顶的值相同就弹出
  else{
    pop(top);
  }
}
int main(){
  char* s = "[({}[])]";
  //char* s = "[";
  char *top, *base;
  top = base = (char*)malloc(sizeof(char) * strlen(s));
  int i = 0;
  for(; i < strlen(s); ++i){
    push(&top, base, s[i]);
  }
  //如果栈顶又回到了栈底，就说明完全都匹配上了
  if(top == base){
    printf("success\n");
  }else{
    printf("dead\n");
  }
  free(base);
}
