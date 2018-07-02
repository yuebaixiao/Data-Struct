#include "sstring.h"

void init(SString ss){
  ss[0] = '\0';
}

void assign(SString ss, char* src){
  if(strlen(src) > 20)return;
  int i = 0;
  while(src[i] != '\0'){
    ss[i++] = src[i++];
  }
  ss[i] = '\0';
}

void copy(SString des, SString src){
  int i = 0;
  while(src[i] != '\0'){
    des[i++] = src[i++];
  }
  des[i] = '\0';
}

bool isEmpty(SString ss){
  if(ss[0] == '\0'){
    return true;
  }
  else{
    return false;
  }
}

int compare(SString ss1, SString ss2){
  int i = 0;
  while(ss1[i] != '\0' && ss2[i] != '\0'){
    if(ss1[i++] > ss2[i++]){
      return 1;
    }
    else if(ss1[i++] < ss2[i++]){
      return -1;
    }
  }
  if(ss1[i] != '\0'){
    return 1;
  }
  if(ss2[i] != '\0'){
    return -1;
  }
  if(ss1[i] == '\0' && ss2[i] == '\0'){
    return 0;
  }
}

int getLength(SString ss){
  int i = 0;
  while(ss[i] != '\0'){
    i += 1;
  }
  return i;
}

void concat(SString* ss1, SString ss2){
  int i = 0;
  while(*ss1[i] != '\0'){
    i += 1;
  }
  int j = 0;
  while(ss2[j] != '\0' && i < MAX_SIZE){
    *ss1[i++] = ss2[j++];
  }
  //ss2不是空的情况下，需要重新设置尾部\0
  if(j != 0){
    *ss1[i] = '\0';
  }
}

void substring(SString ss, SString sub, int pos, int len){
  if(pos >= MAX_SIZE)return;
  if(getLength(ss) - 1 > pos){

  }
}

void replace(SString target, SString be, SString af){

}

void insert(SString des, int pos, SString t){

}

void clear(SString des){
  des[0] = '\0';
}
