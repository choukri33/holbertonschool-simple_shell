#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that print $ and wait for user to enter a command
 *
 * Return: 0 success 
*/

int main(void)
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
