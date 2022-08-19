#include <stdio.h>
#include <stdlib.h>

typedef struct Sparse {
  int *mat;
  int height;
} Sparse;

typedef struct Matrix {
  int *mat;
  int rows, columns;
} Matrix;


int* multiply(int *mat1, int *mat2, int order) {
  int *mat = (int*)malloc(sizeof(int) * order * order);
  int vect_mult = 0;
  for(int i = 0 ; i < order ; i++) {
    for(int j = 0 ; j < order ; j++) {
      vect_mult = 0;
      for(int k = 0 ; k < order ; k++) {
        vect_mult += mat1[i*order+k] * mat2[k*order+j];
      }
      mat[i*order+j] = vect_mult;
    }
  }
  return mat;
}


void display(int *mat, int rows, int columns) {
  printf("\n");
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < columns ; j++){
      printf("%d\t", mat[i * columns + j]);
    }
    printf("\n");
  }
  printf("\n");
}


int sum_of_upper_triangular(int *mat, int order) {
  int sum = 0 ;
  for(int i = 0 ; i < order ; i++) {
    for(int j = i+1 ; j < order ; j++) {
      sum += mat[i * order + j];
    }
  }
  return sum;
}

void sum_of_each_row(int *mat, int rows , int columns) {
  int sum = 0 ;
  for(int i = 0 ; i < rows ; i++) {
    sum = 0;
    for(int j = 0 ; j < columns ; j++) {
      sum += mat[i * columns + j];
    }
    printf("sum of row %d: %d", i, sum);
  }
}


Sparse get_sparse(int *mat, int rows, int columns) {
  int height = 0;
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < columns ; j++) {
      if(mat[i*columns+j] != 0) height++;
    }
  }
  int *mat_sparse = (int*)malloc(sizeof(int) * height * 3);
  int flag = 0;
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < columns ; j++) {
      if(mat[i*columns+j] != 0) {
        mat_sparse[flag*3] = mat[i*columns+j];
      
        mat_sparse[flag*3 + 1] = i;

        mat_sparse[flag*3 + 2] = j;

        flag++;
      }
    }
  }
  return (Sparse){mat_sparse, height};
}


void interchange_diagonals(int *mat, int order){
  int tmp;
  for(int i = 0 ; i < order ; i++) {
    tmp = mat[i*order+i];
    mat[i*order+i] = mat[i*order+order-i-1];
    mat[i*order+order-i-1] = tmp;
  }
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


void a() {
  int order;
  printf("\nenter the order of the matrx: ");
  scanf("%d", &order);
  
  int *mat1 = (int*)malloc(sizeof(int) * order * order);
  int *mat2 = (int*)malloc(sizeof(int) * order * order);

  populate(mat1, order, order);
  populate(mat2, order, order);

  int *mat = multiply(mat1, mat2, order);

  display(mat, order, order);
}


void b() {
  int order;
  printf("\nenter the order of the matrx: ");
  scanf("%d", &order);

  int *mat = (int*)malloc(sizeof(int) * order * order);

  populate(mat, order, order);

  printf("\nsum of upper triangular elements: %d", sum_of_upper_triangular(mat, order));
}

void c() {
  int rows, columns;
  printf("\nenter the no of rows in the matrx: ");
  scanf("%d", &rows);
  printf("\nenter the no of columns in the matrx: ");
  scanf("%d", &columns);

  int *mat = (int*)malloc(sizeof(int) * rows * columns);

  populate(mat, rows, columns);

  sum_of_each_row(mat, rows, columns);
}


void d() {
  int rows, columns;
  printf("\nenter the no of rows in the matrx: ");
  scanf("%d", &rows);
  printf("\nenter the no of columns in the matrx: ");
  scanf("%d", &columns);

  int *mat = (int*)malloc(sizeof(int) * rows * columns);

  populate(mat, rows, columns);

  Sparse sparse = get_sparse(mat, rows, columns);
  display(sparse.mat, sparse.height, 3);
}

void e() {
  int order;
  printf("\nenter the order of the matrx: ");
  scanf("%d", &order);

  int *mat = (int*)malloc(sizeof(int) * order * order);

  populate(mat, order, order);
  interchange_diagonals(mat, order);
}



int main() {
  char choice;
  while(1) {
    printf("\nthese are what this program can do:-\n");
    printf("\na. Multiplication of two matrix");
    printf("\nb. Sum of the upper triangular matrix");
    printf("\nc. The sum of each row and column of a matrix.");
    printf("\nd. Check the sparse matrix");
    printf("\ne. Interchange diagonals of a matrix.");
    printf("\nmake your choice: (a/b/d/c/e) ");
    
    scanf("%c", &choice);

    switch(choice) {
      case 'a':
        a();
        break;
      case 'b':
        b();
        break;
      case 'c':
        c();
        break;
      case 'd':
        d();
        break;
      case 'e':
        e();
      default:
        printf("\nbad choice baby... enter again!");
    }
    
  }
}
