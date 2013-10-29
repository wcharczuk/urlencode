#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//two ways to use urldecode:
// urldecode stuff
// echo stuff | urldecode 

char *url_decode(const char *input)
{
	int input_length = strlen(input);

	size_t output_length = (input_length + 1) * sizeof(char);
	char *working = malloc(output_length), *output = working;
	
	while(*input)
	{
		if(*input == '%')
		{
			char buffer[3] = { input[1], input[2], 0 };
			*working++ = strtol(buffer, NULL, 16);
			input += 3;
		}
		else
		{
			*working++ = *input++;
		}
	}

	*working = 0; //null terminate
	return output;
}

int main(int argc, char **argv) 
{
    if(argc > 1)
    {
        char *input = argv[1];
        char *decoded = url_decode(input);
        printf("%s",decoded);
    	free(decoded);
    }
    else
    {
        char *line = NULL;
        size_t size;
        while(getline(&line, &size, stdin) != -1)
        {
        	char *decoded = url_decode(line);
            printf("%s", decoded);
            free(decoded);
        }
    }
    
    return 0;
}
