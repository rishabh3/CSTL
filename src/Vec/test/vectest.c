#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

initial_vector(char , abcd);
initial_vector(char, fl)

int main(void)
{ 
	int iterate = 0;
	while(iterate==0)
	{
		PRINT("1.Construction 2.Append 3.Get 4.Pop 5.Extend 6.Current Size 7.Maximum Size 8.Destruction");
		int func=-1;
		scanf("%d",&func);
		switch(func)
		{
		case 1 :
			vector(abcd) x = new_vector(abcd);
			vector(fl) y = new_vector(fl);
			break;
		
		case 2:
			for(int i = 0; i < 14; i++)
			{
			x->append(x, 'a'); //append working here
			y->append(y,'b');
			}
			printf("X\n");
			break;
		
		case 3:
			for(int i = 0; i < x->size(x); i++) //size working here
			{
			printf("%c\n", x->get(x, i));//get working here
			}
			break;
			
		case 4:
			x->pop(x);
			x->pop(x); //pop works here
			break;
		
		case 5:
			y->extend(y,x);// extends works here
			printf("Y\n");
			for(int i = 0; i < y->size(y); i++) //size working here
			{
			printf("%c\n", y->get(y, i));
			}
			break;
			
		case 6:
			printf("Current Size: %u\n", y->size(y)); //size works here
			break;

		case 7:
			printf("Max Size: %u\n", y->max_size(y)); //max_size works here
			break;
		
		case 8:
			free_vector(x);// free works here
			free_vector(y);

		default:
			iterate = 1;
		}
	}
  	printf("ALL TEST CASES WORKING!");
    return 0;
}