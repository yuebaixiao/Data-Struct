#include "guangyibiao.h"

void init(GenList* gl){
  *gl = NULL;
}

bool server1(char* sub, char* hsub){
  if(*sub == '\0' || strcmp(sub, "()") == 0){
    hsub[0] = '\0';
    return true;
  }

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
  char* sub = (char*)malloc(sizeof(char) * (n-2));
  char* hsub = (char*)malloc(sizeof(char) * (n-2));
  assert(sub != NULL && hsub != NULL);

  //sub是去掉了最外层括号的串
  strncpy(sub, s+1, n-2);
  sub[n-2] = '\0';

  if(NULL == *gl){
    *gl = (GLNode*)malloc(sizeof(GLNode));
    assert(NULL != gl);

    (*gl)->tag = HEAD;
    (*gl)->head = (*gl)->tail = NULL;
  }

  GLNode* p = (*gl);
  while(strlen(sub) != 0){
    p = p->tail =  (GLNode*)malloc(sizeof(GLNode));
    assert(NULL != p);
    p->head = p->tail = NULL;

    //"1,2,3" ==> hsub="1" sub="2,3"
    //"(1,2),3,4" ==> hsub="(1,2)" sub="3,4"
    if(server1(sub, hsub)){
      if(hsub[0] == '('){
	p->tag = CHILDLIST;
	createGenList(&(p->head), hsub);
      }
      else{
	p->tag = ATOM;
	p->atom = atoi(hsub);
      }
    }
  } 
}
