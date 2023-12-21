#include "shell.h"

/**
*
*/

int main(int ac, char **argv)
{
    char **args = NULL;
    char *prompt = "$ ";
    char *lineptr;
    size_t n = 0;
    ssize_t nchars_read;

    (void)ac;
    (void)argv;

    while (1){
        printf("%s", prompt);
        
        lineptr = (char *)malloc(sizeof(char) * n);
        if (lineptr == NULL){
            perror("Error allocating memory");
            exit(EXIT_FAILURE);
        }
        nchars_read = getline(&lineptr, &n, stdin);

        if (nchars_read == -1)
        {
            free(lineptr);
            exit(EXIT_SUCCESS);
        }
        lineptr[nchars_read - 1] = '\0';
        args = strtok_custom(lineptr, " ");
        execshell(args);
        free(lineptr);  
    }
    return (0);
}
