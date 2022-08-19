#include<stdio.h>
#include<stdlib.h>

#define MAX_LENGTH 15


int larger_of(int a, int b){
  return (a>b)?a:b;
}

int smaller_of(int a, int b){
  return (a<b)?a:b;
}


int maxiumum(int *arr, int len){
  if(len == 0) return 0;
  if(len == 1) return arr[0];
  
  return larger_of(arr[0], maxiumum((arr+1), (len-1)));
}

int minimum(int *arr, int len){
  if(len ==0 ) return 0;
  if(len ==1 ) return arr[0];

  return smaller_of(arr[0], minimum((arr+1), (len-1)));
}

int main(){
  int *arr = (int*)malloc(sizeof(int) * MAX_LENGTH);
  
  int len = 0;
  
  printf("type the fuckin' array: ");

  char c;
  while((c=getchar()) != '\n'){
    ungetc(c, stdin);
    scanf("%d", (arr+len));
    len++;
  }

  printf("array entered: ");
  for(int i = 0 ; i < len ; i++){
    printf("%d  ", arr[i]);
  }
  printf("\n");

  printf("maxium number in this: %d\n", maxiumum(arr, len));
  printf("minimum number in this: %d\n", minimum(arr, len));
}
