#include<stdio.h>

int compare(char *s1, char *s2, int len) {
  for(int i = 0 ; i < len ; i++){
    if(s1[i] != s2[i]) return 0;
  }
  return 1;
}

int search(char *s, char *arr, int len) {
  for(int i = 0 ; i < len ; i++){
    if(compare((s), (arr + 4 * i), 3)) return i;
  }
  return -1;
}


int main(){
  char days[7][4] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
  char first_day[4];
  int no_of_days = 30;
  
  printf("enter first day of the month: ");
  scanf("%s", &first_day);
  printf("enter the number of days in the month: ");
  scanf("%d", &no_of_days);
  
  int index_of_first = search(first_day, days, 7);

  //for(int i = 0 ; i < no_of_days ; i++) {
  //  printf("%d %s \n", (i+1), (days[(i+index_of_first)%7]));
  //}

  
  printf("\n\ncalendar for the month:-\n\n");


  for(int i = 0 ; i < 5 ; i++) {
    for(int j = 0 ; j < 7 && (i*7+j) < no_of_days ; j++) {
      printf("%d\t", (i * 7 + j +1));
    }
    printf("\n");
    for(int j = 0 ; j < 7 && (i*7+j) < no_of_days ; j++) {
      printf("%s\t", (days[(i*7+j+index_of_first)%7]));
    }
    printf("\n");
  }
}
