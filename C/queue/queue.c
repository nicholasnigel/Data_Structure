#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(void)
{
    Queue Q = init(Q);
    Enqueue(Q,5);
    Enqueue(Q,6);
    PrintQueue(Q);
    Dequeue(Q);
    Enqueue(Q,7);

    PrintQueue(Q);
    return 0;
}