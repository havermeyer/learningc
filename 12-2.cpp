#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



void push(char in);
char pop(); 

char stack[100];
char *top = stack;

int main() 
{
    printf("Enter a message: ");
    
    char input;
    for (;;)
    {
        input = getchar();

        if (input == '\n')
            break;
        else if (input >= 'A' && input <= 'Z')
        {
            push(input);
        }
        else if (input >= 'a' && input <= 'z')
        {
            push(input-' ');
        }
        
    }
    

    bool palindrome = true;
    char *beg = stack;
    char *end = --top;
    while ((beg < end) && palindrome)
    {
        printf("%c = %c", *beg, *end);
        if (*beg++ != *end--)
            palindrome = false;

        //beg++;
        //end--;
    }

    if (palindrome)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not a palindrome");
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
