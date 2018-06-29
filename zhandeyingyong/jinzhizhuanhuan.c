#include <stdio.h>
#include <malloc.h>

push(int** top, int val){
  //先取二级指针指向的值，再取一级指针指向的值，最后让一级指针指向上面一个地址
  *(*top)++ = val;
}
int pop(int** top){
  //先取二级指针指向的值，再让一级指针的指向下面以个位置，最后取一级指针指向的值
  return *--(*top);
}
int main(){


  int *top, *base;
  top = base = (int*)malloc(sizeof(int) * 32);
  printf("请输入要转换的数字\n");
  int c,d;
  scanf("%d", &d);
  while(d != 0){
    c = d % 2;
    push(&top, c);
    d = d / 2;
  }

  while(top != base){
    printf("%d", pop(&top));
  }
  printf("\n");

}
