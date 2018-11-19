#include "../src/deque.h"

/*
  Test file to test the basic functionality of the Deque. 
*/

int main(){
  printf("TEST for DEQUE\n");
  int iterate = 0;
  while(iterate == 0){
    printf("1.Construction 2.Push_front 3.Push_back 4.Pop_front 5.Pop_back 6.Peek_front 7.Peek_back 8.Destruction\n");
    int func = -1;
    scanf("%d", &func);
    switch(func){
      case 1:
        printf("TEST for construction\n");
        deque_type *d = deque_alloc();
		assert(d != NULL);
        printf("TEST CASE PASSED!\n");
        break;
      case 2:
        printf("TEST for push_front\n");
        assert(d != NULL);
        for(int i=1;i<=10;i+=1){
        	deque_push_front(d, i);
        }
        printf("TEST CASE PASSED!\n");
        break;
      case 3:
        printf("TEST for push_back\n");
        assert(d != NULL);
        for(int i=11;i<=20;i+=1){
        	deque_push_back(d, i);
        }
        printf("TEST CASE PASSED!\n");
        break;
      case 4:
        printf("TEST for pop_front\n");
        assert(d != NULL);
       // while (deque_is_empty(d) != true) {
		printf("%d\n", deque_pop_front(d));
	    //}
        printf("TEST CASE PASSED\n");
        break;
      case 5:
        printf("TEST for pop_back\n");
        assert(d != NULL);
        //while (deque_is_empty(d) != true) {
		printf("%d\n", deque_pop_back(d));
	    //}
	    printf("TEST CASE PASSED\n");
        break;
      case 6:
        printf("TEST for peek_front\n");
        assert(d != NULL);
        printf("%d\n",deque_peek_front(d));
	    printf("TEST CASE PASSED\n");
        break;
      case 7:
        printf("TEST for peek_back\n");
        assert(d != NULL);
        printf("%d\n",deque_peek_back(d));
	    printf("TEST CASE PASSED\n");
        break;
      case 8:
        printf("TEST for destruction\n");
        assert(d != NULL);
        deque_free(d);
        printf("TEST CASE PASSED\n");
        break;
      default:
        iterate = 1;

    }
  }
  printf("SUCCESS! ALL TEST CASES PASSED\n");
}
