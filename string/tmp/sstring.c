#include "sstring.h"

void init(SString ss){
  ss[0] = '\0';
}

void assign(SString ss, char* src){
  if(strlen(src) > 20)return;
  int i = 0;
  while(src[i] != '\0'){
    ss[i] = src[i];
    i++;
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

void  substring(SString ss, SString sub, int pos, int len){
  if(pos < 0 || pos >= MAX_SIZE || getLength(ss) - 1 <= pos)return;
  int i = 0;
  while(ss[pos] != '\0' && i < len){
    sub[i++] = ss[pos++];
  }
  sub[i] = '\0';
}

int subindex(SString ss, SString sub){
  int i = 0, j = 0, m = 0;
  while(ss[i] != '\0'){
    //存储i的值。因为i的值在下面会被递增，但是最外层的循环是控制被查找串的位置，所以i应该是每次加1，所以在i被递增前，用m保存i的值
    m = i;
    while(sub[j] != '\0' && ss[i] != '\0'){
      if(ss[i] == sub[j]){
	j++;
	i++;
      }else{
	break;
      }
    }
    //pi pei success
    if(sub[j] == '\0'){
      return i - j;
    }
    i = m + 1;
    j = 0;
  }
  return -1;
}

void replace(SString target, SString be, SString af){
  
  
}

void insert(SString des, int pos, SString t){

}

void clear(SString des){
  des[0] = '\0';
}
