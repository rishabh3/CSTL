#include <stdio.h>
#include <stdlib.h>
#include "../src/vec.h"


int main(void)
{
    vector(float) x = new_vector(float);

	 for(int i = 0; i < 314; i++)
   {
	    x->append(x, i);
   }
	 for(int i = 0; i < x->size(x); i++)
   {
	   printf("%f\n", x->get(x, i));
   }


    free_vector(x);
    return 0;
}
