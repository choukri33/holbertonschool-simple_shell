#include "shell.h"

/**
*
*/

char **strtok_custom(char *str, const char *delim)
{
    char **argv;
    int i = 0;
    int num_tokens = 0;
    char *token;
    char *str_copy;

    if (str == NULL || delim == NULL){
        return NULL;
    }

    str_copy = strdup(str);

    if (str_copy == NULL){
        perror("Error allocation memory");
        return NULL;
    }

    token = strtok(str_copy, delim);

    while (token != NULL){
        num_tokens++;
        token = strtok(NULL, delim);
    }

    argv = malloc(sizeof(char *) * (num_tokens + 1));

    if (argv == NULL){
        perror("Error allocating memory");
        free(str_copy);
        return NULL;
    }

    token = strtok(str, delim);

    for (i = 0; token != NULL; i++){
        argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(argv[i], token);
        token = strtok(NULL, delim);
    }
    argv[i] = NULL;

    free(str_copy);

    return (argv);
}
