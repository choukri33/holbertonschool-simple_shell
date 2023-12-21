#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - program that executes the command ls -l /tmp in 5 
 * different childc processes
 * 
 * Return: 0 success
*/

int main(void)
{
    pid_t my_pid;
    pid_t child_pid = 1;
    int i = 0;
    int status;
    char *argv[] = {"bin/ls", "-l", "tmp/", NULL};

    my_pid = getpid();

    while (i <= 4 && (child_pid != 0))
    {
        child_pid = fork();
        
        if (child_pid == -1)
        {
            printf("Error");
            return (1);
        }
        wait(&status);
        i++;
    }
    if (child_pid == 0)
    {
        printf("ID enfant: %u\n\nID père: %u\n\n", getpid(), getppid());
    }
    else 
    {
        printf("%u je suis le père et mon ID est: %u\n", my_pid, child_pid);
    }
    if (execve(argv[0], argv, NULL) == -1)
    {
       //perror("Error:");
    }
    return (0);
}
