#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    fork();
    printf("Hello!\n");
    fork();
    printf("I am from Ujjain\n");
    fork();
    printf("My name is Bhumika process_id(pid) =%d \n", getpid());
    return 0;
}