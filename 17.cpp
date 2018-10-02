#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * concat(const char *s1, const char *s2);

int main()
{

    char *p = concat("abc", "def");
    printf("Result: %s", p);

    return 0;

}



char * concat(const char *s1, const char *s2)
{
    char *result;

    result = (char *) malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL)
    {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    strcpy(result, s1);
    strcat(result, s2);

    return result;
}