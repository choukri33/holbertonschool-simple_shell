#include "shell.h"

/**
*
*/

char **strtok(char *str, const char *delim)
{
    char **argv;
    int i = 0;
    int num_tokens = 0;
    char *token;
    char *lineptr = NULL, *lineptr_copy = NULL;
    const char *delim = " \n";

    lineptr_copy = malloc(sizeof(char) * nchars_read);

    if (lineptr_copy == NULL){
        perror("error memory");
        return (-1);
    }

    strcpy(lineptr_copy, lineptr);

    token = strtok(lineptr, delim);

    while (token != NULL){
        num_tokens++;
        token = strtok(NULL, delim);
    }
    num_tokens++;

    argv = malloc(sizeof(char *) * num_tokens);

    token = strtok(lineptr_copy, delim);

    for (i = 0; token != NULL; i++){
        argv[i] = malloc(sizeof(char) * strlen(token));
        strcpy(argv[i], token);

        token = strtok(NULL, delim);
    }
    argv[i] = NULL;
    free(lineptr_copy);
    return(array);
}
