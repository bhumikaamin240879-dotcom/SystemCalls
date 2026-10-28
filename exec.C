#include <stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid;
    int status;
    printf("Parent Process Created!\n");
    pid = fork();
    if(pid < 0) 
    {
        perror("FORK FAIL");
        return 1;
    }
    if (pid == 0)
    {
        printf("Child process created\n");
        printf("Child PId = %d\n",getpid());
        printf("Executing ls command using exec()\n");
        execlp("ls","ls","-1", (char *)0);
        perror("exec Failed");
        exit(1);
    }
    else
    {
        printf("Parent PId =%d\n",getpid());
        printf("Parent is waiting for child...");
        wait(&status);
        
        if(WIFEXITED(status))
        {
            printf("Child exited with status %d\n",WEXITSTATUS(status));
        }
        printf("Parent Process Completed\n");
    }
    return 0;
}