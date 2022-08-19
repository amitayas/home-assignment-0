#include <stdio.h>
#include<string.h>

typedef struct String {
  char *s;
  int len;
} String;



int length_of(char *s1){
  int pos = 0;
  while(s1[pos] != '\0') pos++;
  return pos;
}

char change_case(char c) {
  if(c > 'a' && c < 'z') return c + 32;
  if(c > 'A' && c < 'Z') return c - 32;
  return c;
}

int compare(char *s1, char *s2) {
  int len = length_of(s1);
  if(len != length_of(s2)) return 0;
  for(int i = 0 ; i < len ; i++){
    if(s1[i] != s2[i]) return 0;
  }
  return 1;
}

void toggle_case(char *s) {
  int len = length_of(s);
  for(int i = 0 ; i < len ; i++) {
    s[i] = change_case(s[i]);
  }
}

void flip(char *s, int len) {
  if(len > 1) {
    char tmp = s[0];
    s[0] = s[len - 1];
    s[len - 1] = tmp;
    flip((s + 1), (len - 2));
  }
}

void reverse(char *s, int len) {
  int start_index = 0;
  for(int i = 0 ; i < len ; i++){
    if(s[i] == ' ') {
      flip((s+start_index), (i - start_index));
      start_index = i + 1;
    }
  }
}

int main() {
  char s[] = "Hello";
  flip(s, 5);
  //printf("%s", s);
  char sen[] = "Hello how are you ";
  reverse(sen, 18);
  printf("%s", sen);
}
