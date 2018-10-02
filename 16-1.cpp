#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "readline.cpp"



struct dialing_code {
    char *country;
    int code;
};

char * search(int s);

const struct dialing_code country_codes[] =
    {{"Aregentina",     54},
     {"Brazil",         55},
     {"China",          86},
     {"Congo, Dem. Rep. of", 243},
     {"Ethiopia",       251},
     {"Germany",        49},
     {"Bangladesh",     880},
     {"Burma (Myanmar)",95},
     {"Colombia",       57},
     {"Egypt",          20},
     {"France",         33},
     {"India",          91},
     {"United States",  1},
     {"Ukraine",        380}};

int main()
{
    char input[100];

    struct dialing_code temp;
    temp.country = "test country";
    temp.code = 7;

    read_line(input, 100);
    printf("%s", input);
    printf("\n");
    printf("%s", search(atoi(input)));
    return 0;
}

char * search(int s)
{
    size_t n = sizeof(country_codes)/sizeof(country_codes[0]);

    for (int i=0; i<n; i++)
    {
        if (country_codes[i].code == s)
        {
            return country_codes[i].country;
        }
    }

    return "Error";

}