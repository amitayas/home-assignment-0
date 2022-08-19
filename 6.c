#include<stdio.h>

typedef struct Note {
  int two_thousand;
  int five_hundred;
  int hundred;
  int rest;
} Note;


Note parse_note(int money) {
  Note notes;
  notes.two_thousand = money / 2000;
  money = money % 2000;

  notes.five_hundred = money / 500;
  money = money % 500;

  notes.hundred = money / 100;
  money = money % 100;

  notes.rest = money;
  return notes;
}

int main() {
  printf("enter amount of money : ");
  int money;
  scanf("%d", &money);
  Note notes = parse_note(money);
  
  printf("\ntwo thousand rupee notes: %d\n", notes.two_thousand);
  printf("\nfive hundred rupee notes: %d\n", notes.five_hundred);
  printf("\nhundred rupee notes: %d\n", notes.hundred);
  printf("\nrest: %d\n", notes.rest);
}
