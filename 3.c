#include<stdio.h>

typedef struct Range {
  int floor, roof;
} Range;

void print(Range range){
  for(int i = range.floor ; i <= range.roof ; i++){
    if((i % 7 == 0) && (i % 13 == 0)) {
      printf("%d\t", i);
    }
  }
}

int main() {
  int floor, roof;
  printf("Enter range: ");
  scanf("%d", &floor);
  scanf("%d", &roof);
  printf("\nNumbers within range that are divisible by 7 and thirteen:-\n");
  print((Range){
    floor,
    roof
  });
}
