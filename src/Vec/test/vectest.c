#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

initial_vector(char , abcd);
initial_vector(char, fl)

int main(void)
{ 
	vector(abcd) x = new_vector(abcd);
	vector(fl) y = new_vector(fl);
	for(int i = 0; i < 14; i++)
    {
		x->append(x, 'a'); //append working here
		y->append(y,'b');
	}
	printf("X\n");
	for(int i = 0; i < x->size(x); i++) //size working here
    {
		printf("%c\n", x->get(x, i));//get working here
		//printf("%d\n", y->get(y, i));
	}
	
	x->pop(x);x->pop(x); //pop works here
	y->extend(y,x);// extends works here
	 
	printf("Y\n");
	for(int i = 0; i < y->size(y); i++) //size working here
    {
		printf("%c\n", y->get(y, i));
	}
		
	printf("curr_size: %u\n", y->size(y)); //size works here
    printf("maxi_size: %u\n", y->max_size(y)); //max_size works here
	free_vector(x);// free works here
    free_vector(y);
    return 0;
}