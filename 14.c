#include <stdio.h>
#include <stdlib.h>

void compare(int a, int b, int *larger, int *smaller){
  if(a>b) {
    *larger = a;
    *smaller = b;
  }
  else {
    *larger = b;
    *smaller = a;
  }
}

int main(){
  int a = 6;
  int b=7;
  int *larger = (int*)malloc(sizeof(int)) ;
  int *smaller = (int*)malloc(sizeof(int));
  compare(a, b, larger, smaller);
  printf("amonmg %d and %d the larger is %d and the smaller is %d", a, b, *larger, *smaller);
}
