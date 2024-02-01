

 //  DINING PHILOSOPHERS PROGRAM USING SEMAPHORES


 #include<unistd.h>
 #include<sys/ipc.h>
 #include<sys/msg.h>
 #include<sys/sem.h>

 struct sembuf sop;
 int chopstick;

 main()
 {
	
	chopstick=semget((key_t)77,5,IPC_CREAT|0666);
	semctl(chopstick,0,SETVAL,1);
	semctl(chopstick,1,SETVAL,1);
	semctl(chopstick,2,SETVAL,1);
	semctl(chopstick,3,SETVAL,1);
	semctl(chopstick,4,SETVAL,1);
	if(fork()==0)

		philospher(0);
	else
	

	if(fork()==0)
	{
		philospher(1);
		sleep(5);
	}

	else 
		
	if (fork()==0)
	{
		philospher(2);
		sleep(5);

        }
	else
	
		if(fork()==0)
	{	
		philospher(3);
		sleep(5);

        }

	else
	{
		philospher(4);
		sleep(5);

	}
	}
	

	int philospher(int i)
	{
	
	while(1)
	{
		if(i==0 || i==2 || i==4)
	
	{

		printf("\n philospher %d is thinking\n",i);
		sleep(5);
		down(chopstick,i);
		down(chopstick,(i+1)%5);
		printf("\n philospher %d has acquired chopstick\n",i);
		sleep(5);
		printf("\n philospher %d is eating\n",i);
		sleep(5);
		up(chopstick,i);
		up(chopstick,(i+1)%5);
		printf("\n philospher %d has returned chopstick\n",i);
		sleep(5);
	}
	else
	{
		printf("\n philospher %d is thinking\n",i);
		sleep(5);
		down(chopstick,(i+1)%5);
		down(chopstick,i);
		printf("\n philospher %d has acquired chopstick\n",i);
		sleep(5);
		printf("\n philospher %d is eating\n",i);
		sleep(5);
		up(chopstick,(i+1)%5);
		up(chopstick,i);
		printf("\n philospher %d has retained chopstick\n");
		sleep(5);
	}
	}
	}

	int down(int semid,int num)
	{
	sop.sem_num=num;
	sop.sem_op=-1;
	sop.sem_flg=0;
	semop(semid, &sop,1);
	}
	up(int semid,int num)
	{
	sop.sem_num=num;
	sop.sem_op=+1;
	sop.sem_flg=0;
	semop(semid,&sop,1);
	}



