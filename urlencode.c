#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//two ways to use urlencode:
// urlencode stuff
// echo stuff | urlencode 

int isSymbol(char c)
{
    if(c == '\0') return 0;
    if(c == '\r') return 0;
    if(c == '\n') return 0;
    
    int c_int = (int)c;
    int is_non_symbol =  (c_int >= 48 && c_int <= 57) || (c_int >= 65 && c_int <= 90) || (c_int >= 97 && c_int <= 122);
    return is_non_symbol == 0;
}

char *url_escape(char *input)
{
    int index = 0;
    int end = strlen(input);
    char *output = (char *)malloc(end * 2 * sizeof(char));
    
    while(index < end)
    {
        char c = input[index];
        char *replace_with = (char*)malloc(3 * sizeof(char));
        if(isSymbol(c)) 
        {
            sprintf(replace_with, "%%%02X", c);
            strcat(output, replace_with);
        }
        else
        {
            char *newc = (char *)malloc(sizeof(char));
            newc[0] = c;
            strcat(output, newc);
        }
        index = index + 1;
    }
    return output;
}

int main(int argc, char **argv) {
    if(argc > 1)
    {
        char *input = argv[1];
        printf("%s", url_escape(input));
    }
    else
    {
        char *line = NULL;
        size_t size;
        if(getline(&line, &size, stdin) == -1) {
            return 1;
        }
        else {
            printf("%s", url_escape(line));
        }
    }
    return 0;
}