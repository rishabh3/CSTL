#include "../src/pair.h"
#include <stdio.h>

int main(){
  PAIR_int *mypair = make_pair_int(10, 20);//integer
  PAIR_char *mycharpair = make_pair_char('a','c');//destroy_pair_char
  PAIR_float *myfloatpair = make_pair_float(5.1, 4.9);//float
  PAIR_double *mydoublepair = make_pair_double(5.1, 4.9);//double
  
  
  printf("First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  swap_int(mypair);
  printf("First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  PAIR_int *temp = make_pair_int(30, 40);
  printf("Result of comparison:%d\n",compare_int(mypair,temp));
  modify_pair_int(mypair,100,200);
  printf("After modification-First: %d, Second: %d\n", get_first_int(mypair), get_second_int(mypair));
  destroy_pair_int(mypair);
  destroy_pair_int(temp);
  
  
  
  printf("First: %f, Second: %f\n", get_first_float(myfloatpair), get_second_float(myfloatpair));
  swap_float(myfloatpair);
  printf("First: %f, Second: %f\n", get_first_float(myfloatpair), get_second_float(myfloatpair));
  PAIR_float *ftemp = make_pair_float(25.3, 35.9);
  printf("Result of comparison:%d\n",compare_float(myfloatpair,ftemp));
  modify_pair_float(myfloatpair,16.1,17.8);
  printf("After modification-First: %f, Second: %f\n", get_first_float(myfloatpair), get_second_float(myfloatpair));
  destroy_pair_float(myfloatpair);
  destroy_pair_float(ftemp);


 printf("First: %lf, Second: %lf\n", get_first_double(mydoublepair), get_second_double(mydoublepair));
  swap_double(mydoublepair);
  printf("First: %lf, Second: %lf\n", get_first_double(mydoublepair), get_second_double(mydoublepair));
  PAIR_double *dtemp = make_pair_double(36.2, 48.9);
  printf("Result of comparison:%d\n",compare_double(mydoublepair,dtemp));
  modify_pair_double(mydoublepair,54.3,68.7);
  printf("After modification-First: %lf, Second: %lf\n", get_first_double(mydoublepair), get_second_double(mydoublepair));
  destroy_pair_double(mydoublepair);
  destroy_pair_double(dtemp);


 printf("First: %d, Second: %d\n", get_first_char(mycharpair), get_second_char(mycharpair));
  swap_char(mycharpair);
  printf("First: %d, Second: %d\n", get_first_char(mycharpair), get_second_char(mycharpair));
  PAIR_char *ctemp = make_pair_char('d', 'e');
  printf("Result of comparison:%d\n",compare_char(mycharpair,ctemp));
  modify_pair_char(mycharpair,'q','f');
  printf("After modification-First: %d, Second: %d\n", get_first_char(mycharpair), get_second_char(mycharpair));
  destroy_pair_char(mycharpair);
  destroy_pair_char(ctemp);

  return 0;
}
