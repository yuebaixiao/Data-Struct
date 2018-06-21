#include "seqnode.h"

int main(){
  NodeList* list;
  init(list);
  int select = 1;
  while(select){
    printf("*****************************************\n");
    printf("*** [1]   push_back   [2]  push_front ***\n");
    printf("*** [3]   show_list   [4]  pop_back   ***\n");
    printf("*** [5]   pop_front   [6]  insert_val ***\n");
    printf("*** [7]   find        [8]  length     ***\n");
    printf("*** [9]   delete_val  [10] sort1      ***\n");
    printf("*** [11]  sort2       [12] resver     ***\n");
    printf("*** [13]  clear       [14*] destroy   ***\n");
    printf("*** [0]   quit                        ***\n");
    printf("*****************************************\n");
    printf("请选择:>");
    scanf("%d", &select);
    if(0 == select)
      break;
    switch(select){}

  }
}
