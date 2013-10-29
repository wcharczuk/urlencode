#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//two ways to use urlencode:
// urlencode stuff
// echo stuff | urlencode 

bool is_non_symbol(char c)
{
    if(c == '\0') return 1;
    //if(c == '\r') return 1;
    //if(c == '\n') return 1;
    
    int c_int = (int)c;
    return (c_int >= 48 && c_int <= 57) || (c_int >= 65 && c_int <= 90) || (c_int >= 97 && c_int <= 122);
}

char *url_encode(const char *input)
{
    int i = 0;
    int index_in_output = 0;
    int end = strlen(input);
    size_t final_size = (end * 2) + 1; //+1 for terminating null

    char *output = malloc(final_size * sizeof(char));

    char c;
    for(;i < end; i++)
    {
        c = input[i];
        if(is_non_symbol(c)) 
        {
            sprintf(output+index_in_output, "%c", c);
            index_in_output++;
        }
        else
        {
            sprintf(output+index_in_output, "%%%02X", c);
            index_in_output+=3;
        }
    }
    
    return output;
}

int main(int argc, char **argv) 
{
    if(argc > 1)
    {
        char *input = argv[1];
        char *encoded = url_encode(input);
        printf("%s", encoded);
        free(encoded);
    }
    else
    {
        char *line = NULL;
        size_t size;
        while(getline(&line, &size, stdin) != -1)
        {
            char *encoded = url_encode(line);
            printf("%s", encoded);
            free(encoded);
        }
    }
    return 0;
}
