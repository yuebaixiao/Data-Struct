#include "seqstack.h"

int main(){
  seqstack list;
  init(&list);
  int select = 1;
  ElemType item;
  int index;
  while(select){
    printf("*****************************************\n");
    printf("*** [1]   push        [2]  pop        ***\n");
    printf("*** [3]   show_list   [4]  length     ***\n");
    printf("*** [5]   clear       [6]  destroy    ***\n");
    printf("*** [0]   quit                        ***\n");
    printf("*****************************************\n");
    printf("请选择:>");
    scanf("%d", &select);
    if(0 == select)
      break;
    switch(select){
    case 1:
      printf("请输入要插入的数据>\n");
      scanf("%d",&item);
      push(&list, item);	
      show_list(&list);
      break;
    case 2:
      pop(&list);	
      show_list(&list);
      break;
    case 3:
      show_list(&list);
      break;
    case 4:
      printf("length is %d\n", length(&list));
      show_list(&list);
      break;
    case 5:
      clear(&list);
      show_list(&list);
      break;
    case 6:
      destroy(&list);
      break;
    default:
      printf("输入的选择错误，请重新选择\n");
      break;
    }
  }
  destroy(&list);
}
