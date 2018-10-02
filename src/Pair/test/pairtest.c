#include "../src/pair.h"
#include <stdio.h>

int main(){
  PAIR_int *mypair = make_pair_int(10, 20);
  PAIR_char *myspair = make_pair_char('a','c');
  printf("First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  printf("First: %c, Second: %c\n", get_first_char(myspair), get_second_char(myspair));
  destroy_pair_int(mypair);
  destroy_pair_char(myspair);
  return 0;
}
