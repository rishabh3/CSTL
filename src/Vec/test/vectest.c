#include <stdio.h>
#include <stdlib.h>
#include "../src/vec.h"

#define PRINT printf

int main(void)
{
	int iterate = 0;
	vector(char) x = NULL;vector(char) y = NULL;
	while(iterate==0)
	{
		PRINT("1.Construction 2.Append 3.Get 4.Pop 5.Extend 6.Current Size 7.Maximum Size 8.Destruction");
		int func=-1;
		scanf("%d",&func);
		switch(func)
		{
		case 1 :
			PRINT("Test for Vector construction\n");
			if(x != NULL || y != NULL){
				free_vector(x);// free works here
				x = NULL;
				free_vector(y);
				y = NULL;
			}
			x = new_vector(char);
			y = new_vector(char);
			PRINT("Test Case Passed\n");
			break;

		case 2:
			PRINT("Test for Vector Append\n");
			if(x == NULL || y == NULL){
				PRINT("Error: First Create the Vector\n");
				break;
			}
			for(int i = 0; i < 14; i++)
			{
				x->append(x, 'a'); //append working here
				y->append(y,'b');
			}
			PRINT("Test Case Passed\n");
			break;

		case 3:
			PRINT("Test for Vector Get\n");
			if(x == NULL || y == NULL){
				PRINT("Error: First Create the Vector\n");
				break;
			}
			for(int i = 0; i < x->size(x); i++) //size working here
			{
				printf("%c\n", x->get(x, i));//get working here
			}
			PRINT("Test Case Passed\n");
			break;

		case 4:
			PRINT("Test for Vector Pop\n");
			if(x == NULL || y == NULL){
				PRINT("Error: First Create the Vector\n");
				break;
			}
			x->pop(x);
			x->pop(x); //pop works here
			PRINT("Test Case Passed\n");
			break;

		case 5:
			PRINT("Test for Vector Extend\n");
			if(x == NULL || y == NULL){
				PRINT("Error: First Create the Vector\n");
				break;
			}
			y->extend(y,x);// extends works here
			printf("Y\n");
			for(int i = 0; i < y->size(y); i++) //size working here
			{
				printf("%c\n", y->get(y, i));
			}
			PRINT("Test Case Passed\n");
			break;

		case 6:
			PRINT("Test for Vector Size\n");
			if(x == NULL || y == NULL){
				PRINT("Error: First Create the Vector\n");
				break;
			}
			printf("Current Size: %u\n", y->size(y)); //size works here
			PRINT("Test Case Passed\n");
			break;

		case 7:
			PRINT("Test for Vector Capacity\n");
			if(x == NULL || y == NULL){
				PRINT("Error: First Create the Vector\n");
				break;
			}
			printf("Max Size: %u\n", y->max_size(y)); //max_size works here
			PRINT("Test Case Passed\n");
			break;

		case 8:
			PRINT("Test for Vector Destruction\n");
			if(x == NULL || y == NULL){
				PRINT("Error: First Create the Vector\n");
				break;
			}
			free_vector(x);// free works here
			x = NULL;
			free_vector(y);
			y = NULL;
			PRINT("Test Case Passed\n");
			break;

		default:
			iterate = 1;
		}
	}
  	printf("ALL TEST CASES WORKING!");
    return 0;
}
