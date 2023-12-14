#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - function that splits a string and return array
 * of each word of the string
 * 
 * 
 * Return: 0 success
*/

int main(void)
{
    char *buffer = malloc(1024);
    size_t len = 1024;
    char *token;

    if (buffer == NULL)
    {
        perror("malloc failed");
        return (1);
    }

    while (1)
    {
        printf("$ ");
        if (getline(&buffer, &len, stdin) == -1)
        {
            perror("getline failed");
            break;
        }

        printf("buffer getline: %s", buffer);

        token = strtok(buffer, " ");
        
        while (token)
        {
            printf("buffer strtok: %s\n", token);
            token = strtok(NULL, " ");
        }
    }
    free(buffer);
    return (0);
}
