#include <stdio.h>

typedef struct String {
  char *pointer;
  int length;
} String;


int are_equal(String s1, String s2) {
  if(s1.length != s2.length) return 0;
  if(s1.length == 0) return 1;
  if(s1.pointer[0] != s2.pointer[0]) return 0;
  return are_equal(
    (String){
      (s1.pointer+1), (s1.length-1)
    },
    (String){
      (s2.pointer+1), (s2.length-1)
    }
  );
}


int index_of_substr(String str, String substr){
  //int index = -1; 
  for(int i = 0 ; i <  (str.length - substr.length); i++){
    if(are_equal(
      (String){(str.pointer+i), (substr.length)},
      substr
    )) return i;
  }
  return -1;
}


int main() {
  String s1 = {"abcd", 4};
  String s2 = {"abce", 4};
  printf("%d", are_equal(s1, s2));
  printf("%d", index_of_substr(
    (String){"mogaman", 7},
    (String){"gam", 3}
  ));
}
