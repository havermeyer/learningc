#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    int sum = 0;
    //argv++; //skip first
    for (int i=1;i<argc;i++)
    {
        printf("%s", argv[i]);
        sum = sum + atoi(argv[i]);
    }
    printf("Total: %d", sum);


    return 0;
}