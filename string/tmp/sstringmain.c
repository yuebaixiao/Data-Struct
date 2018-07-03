#include "sstring.h"

int main(){
  SString ss;
  init(ss);
  char* tc = "abcdefg";
  assign(ss, "abcdefgh");
  printf("%s\n", ss);
  SString sub;
  init(sub);
  substring(ss, sub,2,3);
  printf("%s\n", sub);

  SString des;
  init(des);
  assign(des,"abcdefgh1");
  int idx = subindex(ss,des);
  printf("index is %d\n", idx);
}
