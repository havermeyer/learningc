#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = 0;


void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char c)
{
    if (is_full())
        printf("STACK IS FULL\n");
    else
        stack[top++] = c;
}

char pop(void)
{
    if (is_empty())
    {
        printf("STACK IS EMPTY\n");
        return '0';
    }
    else
        return stack[--top];
}

void printStack(void)
{
    for (int i=top; i>=0; i--)
    {
        printf("%c\n", stack[i]);
    }
}

void processInput()
{
    char c;
    bool bad_command = false;
    
    while ((c = getchar()) !='\n')
    {
        //printf("in the loop");
        switch(c)
        {
            case '(':
            case '{':
            case '[':
            push(c);
            break;
            case ')':
                if (pop() != '(')
                {
                    printf("Not nested properly");
                }
                break;
            case '}':
                if (pop() != '{')
                {
                    printf("Not nested properly");
                }
                break;
            case ']':
            if (pop() != '[')
                {
                    printf("Not nested properly");
                }
            break;
            default:
            bad_command = true;
        }
        
        //printStack();
        //printf("\n");
     

    }

}

int main() {
    
    printf("Enter parentheses and/or braces: ");
    processInput();

    if (is_empty())
        printf("Parentheses/braces are nested properly");
    else
        printf("Something is wrong!");
    
    
    return 0;
}