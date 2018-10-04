#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

initial_vector(float, integer);

int main(void)
{ 
    vector(integer) x = new_vector(integer);

	 for(int i = 0; i < 314; i++)
    {
	x->append(x, i);}
	 for(int i = 0; i < x->size(x); i++)
    {
	printf("%f\n", x->get(x, i));}
  

    free_vector(x);
    return 0;
}