#include "seqstack.h"

int main(){
  SeqList list;
  init(&list);
  int select = 1;
  ElemType item;
  int index;
  while(select){
    printf("*****************************************\n");
    printf("*** [1]   push_back   [2]  push_front ***\n");
    printf("*** [3]   show_list   [4]  pop_back   ***\n");
    printf("*** [5]   pop_front   [6]  insert_pos ***\n");
    printf("*** [7]   find        [8]  length     ***\n");
    printf("*** [9]   delete_pos  [10] delete_val ***\n");
    printf("*** [11]  sort1       [12] resver     ***\n");
    printf("*** [13]  clear       [14*] destroy    ***\n");
    printf("*** [0]   quit        [15] sort2      ***\n");
    printf("*****************************************\n");
    printf("请选择:>");
    scanf("%d", &select);
    if(0 == select)
      break;
    switch(select){
    case 1:
      printf("请输入要插入的数据,以-1结束>\n");
      while(scanf("%d",&item),item != -1){
	push_back(&list, item);	
      }
      show_list(&list);
      break;
    case 2:
      printf("请输入要插入的数据,以-1结束>\n");
      while(scanf("%d",&item),item != -1){
	push_front(&list, item);	
      }
      show_list(&list);
      break;
    case 3:
      show_list(&list);
      break;
    case 4:
      pop_back(&list);
      show_list(&list);
      break;
    case 5:
      pop_front(&list);
      show_list(&list);
      break;
    case 6:
      printf("请输入要插入的数据>\n");
      scanf("%d",&item);
      printf("请输入要插入的index>\n");
      scanf("%d",&index);
      insert_pos(&list, item, index);
      show_list(&list);
      break;
    case 7:
      printf("please enter what you shoule find out>\n");
      scanf("%d",&item);
      index = find(&list, item);
      if(index == -1){
	printf("can not find %d \n", item);
      }else{
	printf("find %d at position %d\n", item, index);
      }
      show_list(&list);
      break;
    case 8:
      printf("length is %d\n", length(&list));
      show_list(&list);
      break;
    case 9:
      printf("please enter the index that you shoule delete>\n");
      scanf("%d", &index);
      delete_pos(&list, index);
      show_list(&list);
      break;
    case 10:
      printf("please enter the value what you shoule delete >\n");
      scanf("%d", &item);
      delete_val(&list, item);
      show_list(&list);
      break;
    case 11:
      sort1(&list);
      show_list(&list);
      break;
    case 12:
      resver(&list);
      show_list(&list);
      break;
    case 13:
      clear(&list);
      show_list(&list);
      break;
    case 15:
      sort2(&list);
      show_list(&list);
      break;
    default:
      printf("输入的选择错误，请重新选择\n");
      break;
    }
  }
  destroy(&list);
}
