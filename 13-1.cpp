#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char input[21];
    char smallest_word[21] = "zzzzzzz"; 
    char largest_word[21] = "";

    for(;;)
    {
        printf("Enter word: ");
        scanf("%20s", input);
        if (strcmp(input, smallest_word) < 0)
            strcpy(smallest_word, input);
        
        if (strcmp(input, largest_word) > 0)
            strcpy(largest_word, input);

        if (strlen(input) == 4)
            break;
        

    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s", largest_word);

    return 0;


}