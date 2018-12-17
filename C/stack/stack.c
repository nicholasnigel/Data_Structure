#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


int main(void)
{
    Stack s = init(s);
    Push(s, 3);
    Push(s, 5);

    printf("%d\n", getElement(Top(s)));
    Pop(s);
    printf("%d\n", getElement(Top(s)));
    return 0;

}