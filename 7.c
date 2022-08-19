#include<stdio.h>

typedef struct String {
  char *pointer;
  int length;
} String;

int contains(char c, String s) {
  for(int i = 0 ; i < s.length ; i++) {
    if(s.pointer[i] == c) return 1;
  }
  return 0;
}

int is_vowel(char c) {
  if(contains(c, (String){"aeiouAEIOU", 10})) return 1;
  return 0;
}

void bootstrap(char *s, int len) {
  for(int i = 0 ; i < len ; i++) {
    if(is_vowel(s[i])) s[i] = s[i] + 1;
  }
}

int main() {
  char str[] = {"abcdef"};
  bootstrap(str, 6);
  printf("%s", str);
}
