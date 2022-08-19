#include<stdio.h>


int greatest_among(int a, int b, int c){
  return (a>b)?((a>c)?a:c):((b>c)?b:c);
}

int main(){
  int a, b, c;
  printf("enter three numbers: ");

  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  printf("\nlargest among the three: %d\n", greatest_among(a,b,c));
}
