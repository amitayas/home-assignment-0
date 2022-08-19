#include<stdio.h>

int main() {
  int n;
  while(1){
    printf("Enter a five digit number: ");
    scanf("%d", &n);
    if(n>0) break;
    printf("something was wrong!\n");
  }
  int number[10];

  for(int i = 4; i >= 0 ; i--){
    number[i] = n % 10;
    number[i+5] = number[i];
    n = n / 10;
  }

  for(int i = 0 ; i < 5; i++){
    for(int j = 0 ; j < 5 ; j++){
      printf("%d\t", number[i+j]);
    }
    printf("\n");
  }
}
