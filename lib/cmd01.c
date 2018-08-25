#include "types.h"
#include "user.h"

extern int asm_add(int a, int b);
extern int asm_f1(int a, int b);

int f1(int a, int b, int c){
  return (a+b)+c;
}

char* f2(char* a, char* b){
  return a[3];
}

int main(){
  int a = 1;
  int b = 2;
  int d = asm_add(a, b);
  d = f1(a,d,b);
  int e = asm_f1(5,2);
  e = e + 1;
  // int d = a + b;
  printf(1,"%d\n",e);
  char* c = f2("ab","cd");
  write(1, c, 1);
  exit();
  return 0;
}
