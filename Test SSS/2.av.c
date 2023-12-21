#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that print all the arg
 * @ac: first arg
 * @av: second arg
 * 
 * Return: 0 success
*/

int main(int ac, char **av)
{
    int i = 0;

    while(av[i])
    {
        printf("%s ", av[i]);
        i++;
    }
    printf("\n");
    return (0);
}
