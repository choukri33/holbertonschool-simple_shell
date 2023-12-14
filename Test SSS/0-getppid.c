#include <stdio.h>
#include <unistd.h>

/**
 * main - function that print pid
 * 
 * Return: 0 success
*/

int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("Enfant %u\n", my_pid);

    my_pid = getppid();
    printf("Père %u\n", my_pid);

    return (0);
}
