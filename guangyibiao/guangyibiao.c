#include "guangyibiao.h"

void init(GenList* gl){
  *gl = NULL;
}

bool server1(char* sub, char* hsub){

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

void show_detail(GenList gl){
  if(gl == NULL) return;
  
  if(gl->tag == ATOM){
    printf("%d", gl->atom);
    if(gl->tail != NULL){
      printf(",");
    }
    show_detail(gl->tail);
  }
  else if(gl->tag == LIST){
    printf("(");
    show_detail(gl->head);
    printf(")");
    if(gl->tail != NULL){
      printf(",");
    }
    show_detail(gl->tail);
  }
}

void show(GenList gl){
  if(gl != NULL){
    printf("(");
    show_detail(gl);
    printf(")\n");
  }
}

void destroy(GenList gl){
  if(gl == NULL) return;
  
  if(gl->tag == ATOM){
    destroy(gl->tail);
    free(gl);
  }
  else if(gl->tag == LIST){
    destroy(gl->head);
    destroy(gl->tail);
    free(gl);
  }
}
void copy(GenList* dest, GenList src){
  if(src == NULL) {
    *dest = NULL;
    return;
  }

  GLNode* p = (GLNode*)malloc(sizeof(GLNode));
  *dest = p;
  p->head = p->tail = NULL;
  p->tag = src->tag;

  if(src->tag == ATOM){
    p->atom = src->atom;
    copy(&(p->tail), src->tail); 
  }
  else if(src->tag == LIST){
    copy(&(p->head), src->head); 
    copy(&(p->tail), src->tail); 
  }
}
int length(GenList gl){
  if(NULL == gl)return 0;
  int i = 0;
  GLNode* p = gl;
  while(p != NULL){
    p = p->tail;
    i++;
  }
  return i;
}
int depth(GenList gl){
  if(NULL == gl)return 0;
  int dep = 1;
  int tmp = dep;
  GLNode* p = gl;
  while(p != NULL){
    depth_detail(p, &tmp);
    if(tmp > dep){
      dep = tmp;
    }
    p = p->tail;
    tmp = 1;
  }
  return dep;
}
int depth_detail(GenList gl, int* tmp){
  if(NULL == gl)return;
  if(gl->tag == ATOM){
    depth_detail(gl->tail, tmp);
  }
  else if(gl->tag == LIST){
    *tmp = *tmp + 1;
    depth_detail(gl->head, tmp);
  }
}
bool isEmpty(GenList gl){
  return gl == NULL;
}
GLNode* getHead(GenList gl){
  if(NULL == gl)return NULL;

  return gl;
}
GLNode* getTail(GenList gl){
  if(NULL == gl)return NULL;

  GLNode* p = gl;
  while(p->tail != NULL){
    p = p->tail;
  }
  return p;
}
void push_head(GenList* gl, GLNode* node){
  if(NULL == node) return;
  getTail(node)->tail = *gl;
  *gl = node;
}
void push_tail(GenList gl, GLNode* node){
  if(NULL == node) return;
  getTail(gl)->tail = node;
  getTail(node)->tail = NULL;
}

void destroy_node(GenList gl){
  if(gl == NULL) return;
  
  if(gl->tag == ATOM){
    free(gl);
  }
  else if(gl->tag == LIST){
    destroy_node(gl->head);
    free(gl);
  }
}

void pop_head(GenList* gl){
  if(NULL == *gl)return;

  GLNode* p = *gl;
  *gl = (*gl)->tail;
  destroy_node(p);
  p = NULL;
}
void pop_tail(GenList* gl){
  if(NULL == gl)return;

  int l = length(*gl);

  GLNode* p = *gl;
  int i = 1;
  while(i++ != l - 1){
    p = p->tail;
  }
  
  if(l == 1){
    free(*gl);
    *gl = NULL;
  }
  destroy_node(p->tail);
  p->tail = NULL;
}
