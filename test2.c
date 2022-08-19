#include<stdio.h>
#include <stdlib.h>

void display(int *mat, int rows, int columns) {
  printf("\n\n");
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < columns ; j++){
      printf("%d\t", *(mat + i * columns + j));
    }
    printf("\n");
  }
  printf("\n\n");
}

void populate(int *mat, int rows, int columns) {
  printf("\nenter the fucking array:-\n");
  for(int i = 0 ; i < rows ; i++){
    for(int j = 0 ; j < columns ; j++) {
      scanf("%d", (mat + i * columns + j));
    }
  }
  printf("\n");
}

int main(){
  int *mat = (int*)malloc(sizeof(int) * 3 * 3);
  populate(mat, 3, 3);
  display(mat, 3, 3);
}
