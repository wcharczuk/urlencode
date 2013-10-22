#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//two ways to use urlencode:
// urlencode stuff
// echo stuff | urlencode 

bool is_symbol(char c)
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
    int i;
    int end = strlen(input);
    
    int final_size = (end * 2) + 1; //+1 for terminating null
    char *output = malloc(final_size * sizeof(char));
    
    for(i = 0; i < end; i++)
    {
        char c = input[i];
        if(is_symbol(c)) 
        {
            sprintf(output, "%s%%%02X", output, c); //String.Format("{0} %{1:x2}", output, c), in c# format
        }
        else
        {
            char newc[2] = { c, '\0' };
            strcat(output, newc);
        }
    }
    return output;
}

int main(int argc, char **argv) 
{
    if(argc > 1)
    {
        char* input = argv[1];
        printf("%s", url_escape(input));
    }
    else
    {
        char *line = NULL;
        size_t size;
        while(getline(&line, &size, stdin) != -1)
        {
            printf("%s", url_escape(line));
        }
    }
    return 0;
}