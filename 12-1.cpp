#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

void push(char in);
char pop(); 

char stack[STACK_SIZE];
char *top;

int main() {

    top = stack;
    printf("Enter a message: ");
    
    char input;
    for (;;)
    {
        input = getchar();

        if (input == '\n')
            break;
        else
            push(input);
    }

    printf("\n");
    printf("Reversal is: ");
    
    
    for (top=top-1;top>=stack;top--)
    {
        printf("%c", *top);
    }

    return 0;
}

void push(char in)
{
    *top++ = in;
}

char pop() 
{
    return *--top;
}
