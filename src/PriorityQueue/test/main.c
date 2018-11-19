#include <stdio.h>
#include <stdlib.h>

#include "../src/pqueue.h"

int cmp_floats(const void *val1, const void *val2) {
    return *(float*) val1 - *(float*) val2;
}

int cmp_ints(const void *val1, const void *val2)
{
	return *(int*) val1 - *(int*) val2;
}

int main(int argc, char** argv) {

    PQueue* pq = pqueue_new(cmp_floats, 200);
    PQueue *pq1 = pqueue_new(cmp_ints , 200);
    float x = 100.0, y = 50.2, z = 300.3, k = 100.9;
    float w = 1000.0;
    int a = 10, b= 20, c = 30, d = 40, e = 50;

    pqueue_enqueue(pq, &x);
    pqueue_enqueue(pq, &y);
    pqueue_enqueue(pq, &z);
    pqueue_enqueue(pq, &k);
    pqueue_enqueue(pq, &w);
    pqueue_enqueue(pq1, &a);
    pqueue_enqueue(pq1, &b);
    pqueue_enqueue(pq1, &c);
    pqueue_enqueue(pq1, &d);
    pqueue_enqueue(pq1, &e);

    int i = 0;
    for(;i<5;++i)
        printf("%f\n", *(float*) pqueue_dequeue(pq));
    i = 0;
    for(;i<5;++i)
        printf("%d\n", *(int*) pqueue_dequeue(pq1));

    pqueue_delete(pq);
    pqueue_delete(pq1);

    return (EXIT_SUCCESS);
}
