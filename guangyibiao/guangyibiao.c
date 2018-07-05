#include "guangyibiao.h"

void init(GenList* gl){
  *gl = NULL;
}

bool server1(char* sub, char* hsub){
  /*
  if(*sub == '\0' || strcmp(sub, "()") == 0){
    hsub[0] = '\0';
    return true;
  }
  */

  int n = strlen(sub);
  int i = 0;
  char ch = sub[0];
  int k = 0;
  //ｋ的作用是，识别逗号是括号里的，还是括号外的，如果是括号外的逗号就跳出while了，括号内的逗号不跳出循环，继续往下找。
  while(i < n && (ch != ',' || k != 0)){
    if(ch == '('){
      k++;
    }
    else if(ch == ')'){
      k--;
    }
    i++;
    ch = sub[i];
  }

  //逗号在sub的范围内
  if(i < n){
    sub[i] = '\0';
    strcpy(hsub, sub);
    strcpy(sub, sub+i+1);
  }
  //括号不匹配
  else if(k != 0) return false;
  //sub本身就是表，比如为(1,2)时，i会等于n，所以把sub给hsub，sub就没有以后部分了
  else{
    strcpy(hsub, sub);
    sub[0] = '\0';
  }

  return true;
}

void createGenList(GenList* gl, char* s){

  int n = strlen(s);
  //列表里最后一项是空括号()
  /*
  if(n - 2 == 0){
    *gl = (GLNode*)malloc(sizeof(GLNode));
    assert(NULL != *gl);
    (*gl)->tail = (*gl)->head = NULL;
    (*gl)->tag = LIST;
    return;
  }
  */
  
  char* sub  = (char*)malloc(sizeof(char) * (n - 2));
  char* hsub = (char*)malloc(sizeof(char) * (n - 2));
  assert(NULL != sub && NULL != hsub);
  strncpy(sub, s+1, n-2);
  sub[n-2] = '\0';

  GLNode* p = *gl;
  while(strlen(sub) != 0){
    if(NULL == p){
      *gl = p = (GLNode*)malloc(sizeof(GLNode));
      p->head = p->tail = NULL;
    }else{
      p = p->tail = (GLNode*)malloc(sizeof(GLNode));
      p->head = p->tail = NULL;
    }
    assert(NULL != p);

    if(server1(sub, hsub)){
      if(hsub[0] == '('){
	p->tag = LIST;
	createGenList(&(p->head), hsub);
      }
      else{
	p->tag = ATOM;
	p->atom = atoi(hsub);
      }
    }    
  }
}

void show(GenList gl){
  if(gl == NULL) return;
  
  if(gl->tag == ATOM){
    printf("%d", gl->atom);
    if(gl->tail != NULL){
      printf(",");
    }
    show(gl->tail);
  }
  else if(gl->tag == LIST){
    printf("(");
    show(gl->head);
    printf(")");
    if(gl->tail != NULL){
      printf(",");
    }
    show(gl->tail);
  }
}
