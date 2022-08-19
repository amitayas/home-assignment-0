#include<stdio.h>
#include <stdlib.h>

typedef struct String {
  char *pointer;
  int length;
} String;



int frequency_of(char c, String s) {
  int freq = 0 ;
  for(int i = 0 ; i < s.length ; i++) {
    if(s.pointer[i] == c) freq++ ;
  }
  return freq;
}


int contains(char c, char *done, int len){
  for(int i =  0; i < len ; i++) {
    if(done[i] == c) return 1;
  }
  return 0;
}


void bootstrap(String s){
  char *done = (char*)malloc(sizeof(char) * (s.length + 1));
  int done_len = 0;
  for(int i = 0 ; i < s.length ; i++){
    //if(s.pointer[i] == '\0') continue;
    if(contains(s.pointer[i], done, done_len)) continue; 
    printf("\nfrequency of %c is %d\n", s.pointer[i], frequency_of(s.pointer[i], s));
    done[done_len] = s.pointer[i]; done_len++;
  }
}




int main(){
  bootstrap((String){"abcdbbd0", 8});

}
