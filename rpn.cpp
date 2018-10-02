#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void get_expression();
void print_stack();
void print_answer();
void push(int in);
int pop();
void clear_stack();

int stack[100];
int top = 0;

int main(void)
{
    for (;;)
    {
        get_expression();
        print_answer();
        clear_stack();
    }
    return 0;
}

void get_expression()
{
    char in;
    int conv, a, b;
    printf("Enter an RPN expression: ");
    
    for (;;)
    {
        scanf(" %c", &in);

        if ((in >= '0') && (in <= '9')) 
        {
            conv = in - '0';
            push(conv);
        }
        else if (in == '+')
        {
            a = pop();
            b = pop();
            push(a+b);
        }
        else if (in == '-')
        {
            a = pop();
            b = pop();
            push(b-a);
        }
        else if (in == '*')
        {
            a = pop();
            b = pop();
            push(a*b);
        }
        else if (in == '/')
        {
            a = pop();
            b = pop();
            push(b/a);
        }
        else if (in == '=')
        {
            printf("\n");
            return;
        }
        else if (in == 'q')
        {
            exit(0);
        }
        print_stack();
    }
}

void push(int x)
{
    stack[top] = x;
    top++;
}

int pop()
{
    return stack[--top];
}

void clear_stack()
{
    top = 0;
}

void print_stack()
{
    for (int i=0;i<100;i++)
    {
        printf("%d", stack[i]);
    }
    printf("\n");
}

void print_answer()
{
    printf("Value of expression: %d", pop());
    printf("\n");
}