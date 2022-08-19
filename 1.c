#include<stdio.h>
#include<stdlib.h>

int main(){
  //char name[5][10];
  char *name = (char*)malloc(sizeof(char) * 10 *5);
  char c;
  int flag = 0;
  while(1){
    
    //printf("adas");
    scanf("%s", (char (*)[10])name + flag);
    flag++;
    if((c = getchar()) == '\n') break;
    //putchar(c);
  }
  for(int i = 0 ;  i < flag ; i++){
    printf("%s ", name + 10 * i);
  }
}
