#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
int main()
{
  key_t key= ftok(".",'A');
  if(key == -1) 
{
  perror("ftok error");
return 1;
}
int semid = semget(key,1,IPC_CREAT | 0666);
if (semid == -1)
{
perror("semget error ");
return 1;
}
printf("1. Semaphore Created. ID: %d\n",semid);
if (semctl (seemid , 0, SETVAL,1)== -1)
{
perror("semctl init error");
return 1;
}
printf("2. Semaphore initiated to 1.\n");      
struct sembuf op;
op.sem_num=0;
op.sem_fig=SEM_UNDO;
op.sem_op = -1;
printf("3. Locking Semaphore...\n");
semop(semid,&op,1);
printf("4. Inside Critical Section! (Sleeping for 2 seconds....)\n");
sleep(2);
op.sem_op =1;
printf("5. Unlocking Semaphore...\n");
semop(semid , &op,1);
printf("6. Out of Critical Section! \n");
if (semctl (semid,0,IPC_RMID, 0) ==-1) 
{
perror("semctl delete error");
return 1;
}
printf("7.Semaphore Deleted Successfully.\n");
return 0;
}
