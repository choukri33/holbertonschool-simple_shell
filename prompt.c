#include "shell.h"

/**
 * prompt - function that print the prompt $
 *  
*/

void prompt(void)
{
    char *buffer = malloc(1024);
    size_t len = 1024;

    while (1)
    {
        printf("$ ");
        getline(&buffer, &len, stdin);
        printf("%s", buffer);
    }

    free(buffer);
    return (0);
}
